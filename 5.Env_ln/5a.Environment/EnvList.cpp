#include<iostream>
#include<stdio.h>

using namespace std;

int main(int argc,char** argv, char** env)
{
	cout<<"The environment variables are:-\n";
	int i=0;
	while(env[i]!=NULL)
		cout<<env[i++]<<endl;//print the environment variables
	return 0;
}
