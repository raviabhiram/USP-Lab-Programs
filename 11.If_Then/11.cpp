#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

char stmt[3][50],input[200];
int i,j,sindex,len,curr=0,l1=101,l2=102,l3=103;

void gen()
{
	cout<<"if "<<stmt[0]<<" goto "<<l1<<endl;
	cout<<"goto "<<l2<<endl;
	cout<<l1<<" :- "<<stmt[1]<<endl;
	if(curr<3)
	{
		cout<<l2<<" :- STOP\n";
		return;
	}
	cout<<"goto "<<l3<<endl;
	cout<<l2<<" :- "<<stmt[2]<<endl;
	cout<<l3<<" :- STOP\n";
	return;
}

int main()
{
	cout<<"Sample input:-\n1.if(a<b)then(s=a);\n2.if(a<b)then(s=a)else(s=b)\n";
	cout<<"Enter the inpput:-\n";
	cin>>input;
	len=strlen(input);
	for(i=0;i<len && input[i]!=';';i++)
	{
		if(input[i]=='(')
		{
			sindex=0;
			for(j=i+1;input[j]!=')';j++)
				stmt[curr][sindex++]=input[j];
			i=j;
			curr++;
		}
	}
	gen();
	return 0;
}
