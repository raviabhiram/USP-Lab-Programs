#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int mySystem(char* cmd)
{
	int status =0;
	printf("\nExecuting mySystem function...\n");
	if((execl("/bin/bash","bash","-c",cmd,NULL))==-1)
	{
		perror("ecexl");
		status = -1;
		return status;
	}
	printf("\nSuccessfully executed the command.\n");
	return status;
}

int main()
{
	pid_t pid,retPid;
	int retStatus,status;
	char cmd[10];
	printf("Enter the command to be executed:- ");
	gets(cmd);
	if((pid=fork())==-1)
	{
		perror("fork");
		return -1;
	}
	else if(pid == 0)
	{
		printf("\nInside child process with PID %d.\n",(int)getpid());
		if((retStatus=mySystem(cmd))==-1)
		{
			printf("Error.\n");
			return -1;
		}
		else
			printf("\nCommand executed successfully.\n");
	}
	else
	{
		retPid=wait(&status);
		printf("\nInside parent with PID %d.\n",(int)getpid());
	}
	return 0;
}
