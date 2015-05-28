%{
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100
int getREindex(char*);
char production[MAX][MAX];
int count=0,i,j;
char temp[MAX],temp2[MAX];
%}

%token ALPHABET
%left '|'
%left '.'
%nonassoc '*''+'

%%
S:re '\n'
{
	printf("The rightmost derivation is:-\n");
	for(i=count-1;i>=0;--i)
	{
		if(i==count-1)
		{
			printf("\nre=>");
			strcpy(temp,production[i]);
			printf("%s",temp);
		}
		else
		{
			printf("\n  =>");
			j=getREindex(temp);
			temp[j]='\0';
			sprintf(temp2,"%s%s%s",temp,production[i],temp+j+2);
			printf("%s",temp2);
			strcpy(temp,temp2);
		}
	}
	printf("\n");
	exit(0);
}
re:ALPHABET{temp[0]=yylval;temp[1]='\0';strcpy(production[count++],temp);}
|'('re')'{strcpy(production[count++],"(re");}
|re'+'{strcpy(production[count++],"re+");}
|re'.'{strcpy(production[count++],"re.");}
|re'|'re{strcpy(production[count++],"re|re");}
%%
int main(int argc,char** argv)
{
	printf("Enter the expression:-\n");
	yyparse();
	return 0;
}

yylex()
{
	signed char ch=getchar();
	yylval=ch;
	if(isalpha(ch))
		return ALPHABET;
	return ch;
}

yyerror()
{
	printf("Invalid Statement\n");
	exit(0);
}

int getREindex(char* str)
{
	j=strlen(str)-1;
	for(;j>=0;--j)
		if(str[j]=='e' && str[j-1]=='r')
			return j-1;
}
