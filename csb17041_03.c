#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

/*char terminals[20];
char nonTerminals[20];
char leadingSet[20];
char trailingSet[20];*/

typedef struct Rules{
	char lhs;
	char rhs[20];
}rules;

rules production[4];

void create_grammar(){
	production[0].lhs='A';
	strcpy(production[0].rhs, "w(C)bSe");

	production[1].lhs='C';
	strcpy(production[1].rhs, "i>n"); // i and n has been taken for id and num respectively for convenience.

	production[2].lhs='S';
	strcpy(production[2].rhs, "E;");

	production[3].lhs='E';
	strcpy(production[3].rhs, "i=i*n");
}

/*void create_symbols(){
	int i, j, k=0, l=0;
	for(i=0;i<4;i++)
	{	
		nonTerminals[k++]=production[i].lhs;
		for(j=0;j<strlen(production[i].rhs);j++)
		{	
			if(production[i].rhs[j] >= 'A' && production[i].rhs[j] <= 'Z')
				nonTerminals[k++]=production[i].rhs[j];
			else if(production[i].rhs[j] >= 'a' && production[i].rhs[j] <= 'z')
				terminals[l++]=production[i].rhs[j];
			else
				terminals[l++]=production[i].rhs[j];
		}
	}
}

void remove_duplicates(char *str){
	int i, j, k;
	for(i=0;i<strlen(str);i++)
	{
		for(j=i+1;str[j]!='\0';j++)
		{
			if(str[j]==str[i])
			{
				for(k=j;str[k]!='\0';k++)
				{
					str[k]=str[k+1];
				}
			}
		}
	}
}*/

int check_nonTerminal(char ch){
	if((ch >= 'a' && ch <= 'z') ||
		ch==';' ||
		ch=='(' ||
		ch==')' ||
		ch=='=' ||
		ch=='>' ||
		ch=='*')
	{
		return 1;
	}
	else
		return 0;
}

char check_further(char ch, int i, int flag)
{
	int j;
	for(j=i+1;j<4;j++)
	{
		if(flag==1)
		{
			if(ch == production[j].lhs)
			{
				if(check_nonTerminal(production[j].rhs[0]))
					return (production[j].rhs[0]);
				else
					check_further(production[j].rhs[0], j, 1);
			}
			else
				continue;
		}
		else if(flag==2)
		{
			if(ch == production[j].lhs)
			{
				if(check_nonTerminal(production[j].rhs[strlen(production[j].rhs)-1]))
					return (production[j].rhs[strlen(production[j].rhs)-1]);
				else
					check_further(production[j].rhs[strlen(production[j].rhs)-1], j, 2);
			}
		}
	}
}

void finding_leading_trailing(){
	int i, j, k=0;
	for(i=0;i<4;i++)
	{
		printf("Leading set of %c: ", production[i].lhs);
		for(j=0;j<strlen(production[i].rhs);j++)
		{
			/*if((production[i].rhs[j] >= 'a' && production[i].rhs[j] <= 'z') ||
				production[i].rhs[j]==';' ||
				production[i].rhs[j]=='(' ||
				production[i].rhs[j]==')' ||
				production[i].rhs[j]=='=' ||
				production[i].rhs[j]=='>' ||
				production[i].rhs[j]=='*')*/
			if(check_nonTerminal(production[i].rhs[j]))
			{
				printf("%c", production[i].rhs[j]);
				break;
			}
			else
			{
				printf("%c ", check_further(production[i].rhs[j], i, 1));
			}
		}
		printf("\n");
	}

		printf("\n");
		k=0;
		for(i=0;i<4;i++)
		{
			printf("Trailing set of %c: ", production[i].lhs);
			for(j=strlen(production[i].rhs)-1;j>=0;j--)
			{
				if(check_nonTerminal(production[i].rhs[j]))
				{
					printf("%c", production[i].rhs[j]);
					break;
				}
				else
				{
					printf("%c", check_further(production[i].rhs[j], i, 2));
				}
			}
			printf("\n");
		}
}

int main()
{
	printf("--The operator precedence grammar--\n");
	int i;
	create_grammar();
	for (i=0; i<4; i++)
	{
		printf("%c -> %s\n", production[i].lhs, production[i].rhs);
	}
	/*create_symbols();
	remove_duplicates(terminals);
	remove_duplicates(nonTerminals);
	puts(terminals);
	puts(nonTerminals);*/
	printf("\n--Finding the leading and the trailing set--\n");
	finding_leading_trailing();
	return 0;
}
