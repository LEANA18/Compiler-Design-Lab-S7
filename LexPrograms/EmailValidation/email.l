%{
	int flag=0;
%}
%%
[a-z . 0-9]+@[a-z]+".com"|".in" {flag=1;}
%%
int main(int argc,char **argv)
{
	FILE *file;
	file=fopen("efile.txt","r");
	if(!file)
	{
		printf("Cannot open file");
		exit(0);
	}
	yyin=file;
	yylex();
	if(flag==1)
	{
		printf("Email Accepted");
	}
	else
	{
		printf("Email is not Accepted");
	}
	printf("\n");
	return (0);
}
int yywrap()
{
	return (1);
}
	
