#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<fcntl.h>

int main(int argc,char** argv)
{
	int i,fd;
	char buf[100];
	struct flock filelock;
	filelock.l_type=F_WRLCK;
	filelock.l_whence=SEEK_END;
	filelock.l_start=-100;
	filelock.l_len=100;

	if(argc!=2)
	{
		printf("Usage:- %s <file_name>\n",argv[0]);
		return -1;
	}
	
	if((fd=open(argv[1],O_RDWR,0644))==-1)
	{
		perror("open");
		return -1;
	}

	if(fcntl(fd,F_SETLK,&filelock)==-1)
	{
		if((fcntl(fd,F_GETLK,&filelock))==-1)
		{
			perror("fcntl");
			return -1;
		}
		else
		{
			printf("Process %d has already locked %ld bytes of the file\n",(int)getpid(),filelock.l_len);
		}
		return 0;
	}

	printf("Process with PID %d sets lock on the file %s\n",(int)getpid(),argv[1]);
	sleep(5);
	
	if((lseek(fd,-51,SEEK_END))==-1)
	{
		perror("lseek");
		return -1;
	}

	if((read(fd,&buf,50))==-1)
	{

		perror("read");
		return -1;
	}

	printf("\nThe last 50 bytes of the file %s are:-\n\"",argv[1]);
	for(i=0;i<50;i++)
	{
		printf("%c",buf[i]);
	}
	printf("\"\n\n");
	
	filelock.l_type=F_UNLCK;
	filelock.l_whence=SEEK_END;
	filelock.l_start=-100;
	filelock.l_len=100;
	
	if(fcntl(fd,F_SETLK,&filelock)==-1)
	{
		perror("fcntl");
		return -1;
	}

	printf("Process %d releases the lock\n",(int)getpid());
	return 0;
}
