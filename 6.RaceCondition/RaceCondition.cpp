#include<iostream>
#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<string.h>

using namespace std;

int pfd1[2],pfd2[2],i,c;

void Print(char* msg)
{
	setbuf(stdout,NULL);
	while(c=*msg++)
	{
		putc(c,stdout);
		for(int j=0;j<100000000;j++)
		{
		}
	}
}

void TELL_CHILD()
{
	if((write(pfd1[1],"p",1))!=1)
		perror("write");
}

void TELL_PARENT()
{
	if((write(pfd2[1],"c",1))!=1)
		perror("write");
}

void WAIT_CHILD()
{
	char c;
	if((read(pfd2[0],&c,1))!=1)
		perror("read");
	if(c!='c')
		cout<<"Child not done.\n";
}

void WAIT_PARENT()
{
	char c;
	if((read(pfd1[0],&c,1))!=1)
		perror("read");
	if(c!='p')
		cout<<"Parent not done.\n";
}

int main()
{
	pid_t pid;

	if(pipe(pfd1)<0 || pipe(pfd2)<0)
	{
		perror("pipe");
		return -1;
	}

	if((pid=fork())==-1)
	{
		perror("fork");
		return -1;
	}
	
	else if(pid==0)
	{
		WAIT_PARENT();
		Print("Output From Child.\n");
		TELL_PARENT();
	}

	else
	{
		Print("Output From Parent.\n");
		TELL_CHILD();
		WAIT_CHILD();
	}
	return 0;
}
