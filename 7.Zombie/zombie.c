#include<stdio.h>
#include<unistd.h>

int main()
{
	pid_t pid;
	if((pid=fork())==-1)
	{
		perror("fork");
		return -1;
	}
	else if(pid == 0)
	{
		printf("Child process with PID %d is running.\n",(int)getpid());
		printf("Status before sleeping:-\n\n");
		system("ps aux");
		sleep(5);
		printf("Child finishes its tasks.\n");
	}
	else if(pid>0)
	{
		printf("Parent process with PID %d is running.\n",(int)getpid());
		sleep(20);
		printf("Status after sleep is:-\n\n");
		system("ps aux | grep Z");
		printf("Parent finishes its tasks.\n");
	}
	return 0;
}
