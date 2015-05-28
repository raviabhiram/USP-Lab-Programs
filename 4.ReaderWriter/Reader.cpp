#include<iostream>
#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

using namespace std;

char *myfifo= "/home/raviabhiram/programs/USP/lab/4.ReaderWriter/MYFIFO";//FIFO file to read from

int main()
{
	char readbuf[100];//buffer to read messages into
	int fd,readbytes;

	if((fd=open(myfifo,O_RDONLY))==-1)//open the FIFO file
	{
		perror("open");
		return -1;
	}
	
	cout<<"Waiting for Writer process:-\n";

	while(1)
	{
		if((readbytes=read(fd,&readbuf,sizeof(readbuf)))==-1)//read from FIFO into the buffer
		{
			perror("read");
			return -1;
		}
		cout<<"Reader read:- "<<readbuf<<endl;//print the contents read
	}
	return 0;
}
