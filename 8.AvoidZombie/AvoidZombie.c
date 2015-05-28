#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	pid_t child1,child2;
	int status;
	int waitstatus;
	if((child1=fork())==-1)//fork a process, this doesn't become a zombie
	{
		perror("fork");
		return -1;
	}
	else if(child1==0)
	{
		
		printf("First child process %d created by parent process %d\n",getpid(),getppid());
		sleep(5);
		if((child2=fork())==-1)//fork another process, this becomes a zombie
		{
			perror("fork");
			return -1;
		}
		else if(child2==0)
		{
			printf("Second child process %d created by the first child %d\n",getpid(),getppid());
			sleep(10);//sleeps shorter than its parent
			printf("Second child process terminates.\n");
		}
		else
		{
			sleep(15);
			system("ps -aux");
			printf("First child process terminates.\n");
		}
	}
	else
	{
		wait(&waitstatus);//synchronize the first process so that its child doesn't become a zombie
		sleep(15);
		system("ps -aux");
	}
	return 0;
}
