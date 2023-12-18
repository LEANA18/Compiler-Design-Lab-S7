%{
int vow_count=0;
int const_count=0;
%}
%%
[aeiouAEIOU] {vow_count++;}
[a-zA-Z] {const_count++;}
%%
int main(int argc,char **argv)
{
	FILE *file;
	file=fopen("vfile.txt","r");
	if(!file)
	{
		printf("Cannot open the file");
		exit(0);
	}
	yyin=file;
	yylex();
	printf("No of vowels:%d\nNo of consonants:%d",vow_count,const_count);
	return(0);
}
int yywrap()
{
	return(1);
}
