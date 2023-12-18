#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main()
{
	FILE *filein=fopen("filein.txt","r");
	FILE *fileout=fopen("fileout.txt","w");
	int lineno=1,tokno=0,flag=0,j;
	char ch,str[100];
	char keywords[50][50]={"int","main","if","else","for","do","while","switch","return","FILE","scanf","printf"};
	fprintf(fileout,"Line no \t\tToken no \tToken \t\t Lexeme\n\n");
	while((ch=fgetc(filein))!=EOF)
	{
		if(ch=='/')
		{
			ch=fgetc(filein);
			if(ch=='/')
			{
				while((ch=fgetc(filein))!='\n')
				{
					if(ch==EOF)
					{
							break;
					}
				}
				lineno++;
			}
			else if (ch=='*')
			{
				while((ch=fgetc(filein))!='*')
				{
					if(ch==EOF)
					{
						break;
					}
				}
				ch=fgetc(filein);
				if(ch=='/')
				{
					continue;
				}
			}
		}
		if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='%'||ch=='=')
		{
			fprintf(fileout,"%7d\t\t%7d\t\tOperator\t%7c\n",lineno,tokno,ch);
			tokno++;
		}
		else if(ch==';'||ch==':'||ch=='{'||ch=='}'||ch=='['||ch==']'||ch=='?'||ch=='|'||ch=='\"'||ch=='('||ch==')')
		{
			fprintf(fileout,"%7d\t\t%7d\t\tSpecial Symbol\t%7c\n",lineno,tokno,ch);
			tokno++;
		}
		else if(isdigit(ch))
		{
			fprintf(fileout,"%7d\t\t%7d\t\tDigit\t\t%7c\n",lineno,tokno,ch);
			tokno++;
		}
		else if(isalpha(ch))
		{
			int i=0;
			str[i++]=ch;
			ch=fgetc(filein);
			while(isalnum(ch) && ch!=' ')
			{
				str[i++]=ch;
				ch=fgetc(filein);
			}
			str[i]='\0';
			flag=0;
			for(j=0;j<50;j++)
			{
				if(strcmp(str,keywords[j])==0)
				{
					flag=1;
					break;
				}
			}
			if(flag==1)
			{
				fprintf(fileout,"%7d\t\t%7d\t\tKeyword\t\t%7s\n",lineno,tokno,str);
				tokno++;
			}
			else
			{
				fprintf(fileout,"%7d\t\t%7d\t\tIdentifier\t%7s\n",lineno,tokno,str);
				tokno++;
			}
			if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='%'||ch=='=')
			{
				fprintf(fileout,"%7d\t\t%7d\t\tOperator\t%7c\n",lineno,tokno,ch);
				tokno++;
			}
			if(ch==';'||ch==':'||ch=='{'||ch=='}'||ch=='['||ch==']'||ch=='?'||ch=='|'||ch=='\"'||ch=='('||ch==')')
			{
				fprintf(fileout,"%7d\t\t%7d\t\tSpecial Symbol\t%7c\n",lineno,tokno,ch);
				tokno++;
			}
			
		}
		
		else if(ch=='\n')
		{
			lineno++;
		}
		}
	
	fclose(fileout);
	fclose(filein);
	return 0;
}
//||ch=='>'||ch=='<'
		
