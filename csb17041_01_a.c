#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include "token.h"

char buffer[20];
FILE *fp;

void lexicalAnalyser()
{
	char ch;
	while(1)
	{
		ch=fgetc(fp);
		if(feof(fp))
		{
			printf("\n--End of file has been reached--\n");
			break;
		}
		else if(ch == ';')
		{
			printf("%c--TOK_SEMICOLON %d\n", ch, TOK_SEMICOLON);
		}
		else if(ch == ',')
		{
			printf("%c--TOK_COMMA %d\n", ch, TOK_COMMA);
		}
		else if(ch == '%')
		{
			buffer[0]=ch;
			char ch1=fgetc(fp);
			buffer[1]=ch1;
			buffer[2]='\0';
			printf("%s--TOK_ID %d\n", buffer, TOK_ID);
		}
		else if(ch == '+')
		{
			buffer[0]=ch;
			char ch1=fgetc(fp);
			buffer[1]=ch1;
			buffer[2]='\0';
			if(strcmp(buffer, "++")==0)
			{
				printf("%s--TOK_INCREMENT %d\n", buffer, TOK_INCREMENT);
			}
			else if(strcmp(buffer, "+=")==0)
			{
				printf("%s--TOK_PLUS_INCR %d\n", buffer, TOK_PLUS_INCR);
			}
			else
			{
				printf("%c--TOK_ADD %d\n", ch, TOK_ADD);
			}
		}
		else if(ch == '=')
		{
			buffer[0]=ch;
			char ch1=fgetc(fp);
			buffer[1]=ch1;
			buffer[2]='\0';
			if(strcmp(buffer, "==")==0)
			{
				printf("%s--TOK_COMAPRISON %d\n", buffer, TOK_INCREMENT);
			}
			else {
				ungetc(ch1,fp);
				printf("%c--TOK_EQUAL %d\n", ch, TOK_EQUAL);
			}
		}
		else if(ch == '(')
		{
			printf("%c--TOK_LEFTBKT %d\n", ch, TOK_LEFTBKT);
		}
		else if(ch == ')')
		{
			printf("%c--TOK_RIGHTBKT %d\n", ch, TOK_RIGHTBKT);
		}
		else if(ch == '{')
		{
			printf("%c--TOK_LEFTCRL %d\n", ch, TOK_LEFTCRL);
		}
		else if(ch == '}')
		{
			printf("%c--TOK_RIGHTCRL %d\n", ch, TOK_RIGHTCRL);	
		}
		else if(isalpha(ch))
		{
			int i=0;
			buffer[i]=ch;
			ch=fgetc(fp);
			while(isalnum(ch))
			{
				buffer[++i]=ch;
				ch=fgetc(fp);
			}
			ungetc(ch, fp);
			buffer[++i]='\0';
			if(strcmp(buffer, "if")==0)
			{
				printf("%s--TOK_IF %d\n", buffer, TOK_IF);
			}
			else if(strcmp(buffer, "else")==0)
			{
				printf("%s--TOK_ELSE %d\n", buffer, TOK_ELSE);
			}
			else if(strcmp(buffer, "while")==0)
			{
				printf("%s--TOK_WHILE %d\n", buffer, TOK_WHILE);
			}
			else if(strcmp(buffer, "for")==0)
			{
				printf("%s--TOK_FOR %d\n", buffer, TOK_FOR);
			}
			else if(strcmp(buffer, "return")==0)
			{
				printf("%s--TOK_RETURN %d\n", buffer, TOK_RETURN);
			}
			else
			{
				printf("%s--TOK_ID %d\n", buffer, TOK_ID);
			}
		}
		else if(isdigit(ch))
		{
			int i=0;
			buffer[i]=ch;
			ch=fgetc(fp);
			while(isdigit(ch))
			{
				buffer[++i]=ch;
				ch=fgetc(fp);
			}
			ungetc(ch, fp);
			buffer[++i]='\0';
			printf("%s--TOK_DIGIT %d\n", buffer, TOK_DIGIT);
		}
	}
}
int main()
{
	fp=fopen("file.txt", "r");
	if(fp==NULL)
	{
		perror("FOPEN error:");
		exit(1);
	}
	lexicalAnalyser();
	fclose(fp);
}