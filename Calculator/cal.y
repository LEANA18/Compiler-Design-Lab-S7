%{
	#include<stdio.h>
	int flag=0;
%}

%token NUMBER

%left'+''-'
%left'*''/''%'
%left'('')'

%%

ArithmeticExpression:E{
	printf("\nResult:%d\n",$$);
	return 0;
};
	
E:E'+'E {$$=$1+$3;}
|E'-'E {$$=$1-$3;}
|E'*'E {$$=$1*$3;}
|E'/'E {$$=$1/$3;}
|E'%'E {$$=$1%$3;}
|'('E')' {$$=$2;}
|NUMBER {$$=$1;}
;

%%

void main()
{
	printf("Enter Arithmetic Expression that contains operations addition, subtraction,multiplication,divison,modulo,round brackets\n");
	yyparse();
	if(flag==0)
	{
		printf("Entered Expression is valid\n");
	}
}

void yyerror()
{
	printf("Entered expression is invalid\n");
	flag=1;
}
