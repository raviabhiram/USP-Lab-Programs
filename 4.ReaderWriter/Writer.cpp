#include<iostream>
#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<signal.h>
#include<stdlib.h>
#include<sys/wait.h>

//#define myfifo "~/programs/USP/lab/4.ReaderWriter/MYFIFO"

using namespace std;

char* myfifo= "/home/raviabhiram/programs/USP/lab/4.ReaderWriter/MYFIFO";

void sigHandler(int sig)//signal handler to catch SIGINT
{
	cout<<"Exiting...\n";
	unlink(myfifo);//remove the FIFO file
	exit(0);
}

int main()
{
	signal(SIGINT,sigHandler);
	char writebuf[100];
	int status,fd,wrotebyte;

	if((mkfifo(myfifo,0666))==-1)//create the FIFO file
	{
		perror("mkfifo");
		return -1;
	}

	if((fd=open(myfifo,O_WRONLY))==-1)//open the FIFO file
	{
		perror("open");
		return -1;
	}
	
	cout<<"Waiting for Reader process:-\n";
	while(1)
	{
		gets(writebuf);//input from user the string to write
		if((wrotebyte=write(fd,&writebuf,sizeof(writebuf)))==-1)//actual writing into the FIFO file
		{
			perror("write");
			return -1;
		}
	}
	return 0;
}
