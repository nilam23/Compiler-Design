#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

typedef struct rules{
	char lhs;
	char rhs[10];
	char firstSet[10];
	char followSet[10];
}rule;

rule production[4];

void createGrammar()
{
	production[0].lhs='S';
	strcpy(production[0].rhs, "TR");

	production[1].lhs='R';
	strcpy(production[1].rhs, "+TR|#");

	production[2].lhs='T';
	strcpy(production[2].rhs, "n");
}

int isTerminal(char ch)
{
	if(ch=='+' || ch=='#' || ch=='n')
		return 1;
	return 0;
}

int isEpsilon(char *s)
{
	if(s[strlen(s)-1]=='#')
		return 1;
	return 0;
}

void first(char N)
{
	int i, k=0;	
	for(i=0;i<3;i++)
	{
		if(production[i].lhs==N)
		{
			if(N>='a' && N<='z')
				production[i].firstSet[k]=N;
			else if(isTerminal(production[i].rhs[0]))
				production[i].firstSet[k++]=production[i].rhs[0];
			else if(!isTerminal(production[i].rhs[0]))
			{
				for(int j=0; j<3; j++)
				{
					if(production[j].lhs==production[i].rhs[0])
					{
						if(isTerminal(production[j].rhs[0]))
							production[i].firstSet[k++]=production[j].rhs[0];
					}
				}
			}
			if(isEpsilon(production[i].rhs))
				production[i].firstSet[k++]='#';
		}
	}

	// int k=0;
	// if(N>='a' && N<='z')
	// {
	// 	production[pos].firstSet[k]=N;
	// 	k++;
	// }
	// else if(isTerminal(production[pos].rhs[0]))
	// {
	// 	production[pos].firstSet[k]=production[pos].rhs[0];
	// 	printf("%c",production[pos].firstSet[k]);
	// 	k++;
	// }
	// else if(!isTerminal(production[pos].rhs[0]))
	// {

	// }
}

int check(char N,char *temp){
	int j;
	for(int j = 0;j < strlen(temp);j++){
		if(temp[j] == N){
			return j;
		}
	}
	return 0;
}

char *find_first(char N){
	for (int i = 0; i < 3; ++i)
	{
		if(N == production[i].lhs){
			return (production[i].firstSet);
		}
	}
}

void follow(char N,int t){
	int i=0,j =0,current;
	char temp[7],first[7],buf;
	if(N == 'S'){
		production[t].followSet[j++]='$';
	}
	else{
		strcpy(temp,production[0].rhs);
		current = check(N,temp);
		if(temp[current+1] == '\0'){
			strcpy(production[t].followSet,production[0].followSet);
		}
		else {
			strcpy(first,find_first(temp[current+1]));
			if(isEpsilon(first)){
				production[t].followSet[j++] = first[0];
				strcat(production[t].followSet,production[0].followSet);
			}
		}
	}
}

int main()
{
	printf("--The operator precedence grammar--\n");
	int i;
	createGrammar();
	for(i=0;i<3;i++)
	{
		printf("%c->%s\n", production[i].lhs, production[i].rhs);
	}
	printf("--Calculating FIRST--\n");
	for (i=0; i<3; i++)
	{
		first(production[i].lhs);
	}
	for(i=0; i<3; i++)
	{
		printf("First of %c: %s\n", production[i].lhs, production[i].firstSet);
	}
	printf("--Calculating FOLLOW--\n");
	for (i=0; i<3; i++)
	{
		follow(production[i].lhs, i);
	}
	for(i=0; i<3; i++)
	{
		printf("Follow of %c: %s\n", production[i].lhs, production[i].followSet);
	}
	return 0;
}
