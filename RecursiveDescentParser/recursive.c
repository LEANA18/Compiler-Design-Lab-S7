#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

char input[10];
int pos=0;

int parseExpression();
int parseTerm();
int parseFactor();
int parseNumber();

int main()
{
	printf("Enter Arithmetic Expression\n");
	fgets(input,sizeof(input),stdin);
	int result=parseExpression();
	if(pos==strlen(input)-1)
	{
		printf("Successfully Parsed\nResult:%d",result);
	}
	else
	{
		printf("Error in parsing at position:%d\n",pos);
 	}
 	return 0;
 }
 int parseExpression()
 {
 	int left=parseTerm();
 	while(input[pos]=='+'||input[pos]=='-')
 	{
 		char op=input[pos];
 		pos++;
 		if(input[pos]=='*'||input[pos]=='/'||input[pos]=='+'||input[pos]=='-')
 		{
 			printf("Error");
 			exit(1);
 		}
 		int right=parseTerm();
 		if(op=='+')
 		{
 			left+=right;
 		}
 		else
 		{
 			left-=right;
 		}
 	}
 	return left;
 }
 int parseTerm()
 {
 	int left=parseFactor();
 	while(input[pos]=='*'||input[pos]=='/')
 	{
 		char op=input[pos];
 		pos++;
 		if(input[pos]=='*'||input[pos]=='/'||input[pos]=='+'||input[pos]=='-')
 		{
 			printf("Error");
 			exit(1);
 		}
 		int right=parseFactor();
 		if(op=='*')
 		{
 			left*=right;
 		}
 		else if(right!=0)
 		{
 			left/=right;
 		}
 		else
 		{
 			printf("Error.Divison by Zero\n");
 			exit(1);
 		}
 	}
 	return left;
 }
 int parseFactor()
 {
 	while(isspace(input[pos]))
 	{
 		pos++;
 	}
 	if(input[pos]=='(')
 	{
 		pos++;
 		int result=parseExpression();
 		if(input[pos]==')')
 		{
 			pos++;
 			return result;
 		}
 		else
 		{
 			printf("Missing Paranthesis");
 			exit(1);
 		}
 	}
 	else
 	{
 		return parseNumber();
 	}

 }
 int parseNumber()
 {
 	int number=0;
 	while(isdigit(input[pos]))
 	{
 		number=number*10+(input[pos]-'0');
 		pos++;
 	}
 return number;
 }
 
 	
 	
 
 		
