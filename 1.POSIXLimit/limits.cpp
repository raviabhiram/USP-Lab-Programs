#include<iostream>
#include<unistd.h>
#include<stdio.h>

using namespace std;

int main()
{
	long retval;
	
	if((retval=sysconf(_SC_CLK_TCK))==-1)//check maximum number of clockk ticks
	{
		perror("sysconf");
		return -1;
	}
	cout<<"Max clock ticks:-\t\t"<<retval<<endl;
	if((retval=sysconf(_SC_CHILD_MAX))==-1)//check maximum number of children
	{
		perror("sysconf");
		return -1;
	}
	cout<<"Max children:-\t\t\t"<<retval<<endl;
	if((retval=pathconf("/",_PC_PATH_MAX))==-1)//check maximum number length of relative path
	{
		perror("pathconf");
		return -1;
	}
	cout<<"Max path length:-\t\t"<<retval<<endl;
	if((retval=pathconf("/",_PC_NAME_MAX))==-1)//check maximum characters in a file name
	{
		perror("pathconf");
		return -1;
	}
	cout<<"Max characters in file name:-\t"<<retval<<endl;
	if((retval=sysconf(_SC_OPEN_MAX))==-1)//check maximum number of files that a process can open
	{
		perror("sysconf");
		return -1;
	}
	cout<<"Max open files:-\t\t"<<retval<<endl;
	return 0;
}
