%{
	int COMMENT=0;
%}

%%

#.* {printf("\n%s is Preprocessor directives",yytext);}

int|float|char|printf|scanf|goto|do|while|for|if|else|return|struct {if(!COMMENT) printf("\n%s is a keyword",yytext);}

"/*" {COMMENT=1; printf("\n%s is Comment Code",yytext);}
"*/" {COMMENT=0;}
"//" {COMMENT=1; printf("Comment Code");}
\n {COMMENT=0;}

[a-zA-Z_][a-zA-Z0-9_]*? {if(!COMMENT) printf("\n%s is an identifier",yytext);}

\".*\" {if(!COMMENT) printf("\n%s is a STRING",yytext);}

[0-9]+ {if(!COMMENT) printf("\n%s is DIGIT",yytext);}

[+\-*/%=\<>!&|] {if(!COMMENT) printf("\n%s is a operator",yytext);}

\'[a-zA-Z0-9]\' {if(!COMMENT) printf("\n%s is a character literal",yytext);}

[,{}()\[\];:"'] {if(!COMMENT) printf("\n%s is a Special Symbol",yytext);}

[ \t\n]+;

. {if(!COMMENT) printf("\n%s is an unregonized token",yytext);}

%%

int main(int argc, char **argv)
{
	FILE *file;
	file=fopen("file.c","r");
	if(!file)
	{
		printf("Cannot open the file\n");
		exit(0);
	}
	yyin=file;
	yylex();
	printf("\n");
	return (0);
}

int yywrap()
{
	return (1);
}







