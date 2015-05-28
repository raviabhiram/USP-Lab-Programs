#include<iostream>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

int main(int argc, char **argv)
{
	if(argc<3)//this program takes at least 2 file names as input
	{
		cout<<"Usage:- "<<argv[0]<<" <options> <file1> <file2>\n";
		return -1;
	}
	system("ls -l");
	if(argc == 4 && (strcmp(argv[1],"-s")==0))//checking if symbolic link is to be created
	{
		if((symlink(argv[2],argv[3]))==-1)//creating a symbolic link
		{
			perror("symlink");
			return -1;
		}
		cout<<"Symbolic link created between "<<argv[2]<<" & "<<argv[3]<<endl;
		system("ls -l");
		return 0;
	}
	if((link(argv[1],argv[2]))==-1)//creating a hard link
	{
		perror("link");
		return -1;
	}
	cout<<"Hard link created between "<<argv[1]<<" & "<<argv[2]<<endl;
	system("ls -l");
	return 0;
}
