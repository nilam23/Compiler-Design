#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

/*
Grammar is-
A -> w(C)bE;e
C -> i>n
E -> i=i*n
*/

char str[]="w(a>5)b a=a*2; e";
int inc=0;

int start();
int C();
int E();

void parser(char *str)
{
	if(start()==1)
	{
		printf("\nScanning of the input string is completed.\n");
		printf("--Successful--\n");
	}
	else if(start()==0)
	{
		printf("\nScanning of the input string is not completed.\n");
		printf("--Error--\n");
	}
}

int start()
{
	if(str[inc]=='w')
	{
		printf("input char:%c at pos:%d\n", str[inc], inc);
		if(str[++inc]='(')
		{
			printf("input char:%c at pos:%d\n", str[inc], inc);
			if(C())
			{
				printf("input char:%c at pos:%d\n", str[inc], inc);
				if(str[++inc]==')')
				{
					printf("input char:%c at pos:%d\n", str[inc], inc);
					if(str[++inc]=='b')
					{
						printf("input char:%c at pos:%d\n", str[inc], inc);
						if(str[++inc]=' ')
						{
							printf("input char:%c at pos:%d\n", str[inc], inc);
							//inc++;
							if(E())
							{
								printf("input char:%c at pos:%d\n", str[inc], inc);
								if(str[++inc]==';')
								{
									printf("input char:%c at pos:%d\n", str[inc], inc);
									if(str[++inc]==' ')
									{
										printf("input char:%c at pos:%d\n", str[inc], inc);
										//inc ++;
										if(str[++inc]=='e')
										{
											printf("input char:%c at pos:%d\n", str[inc], inc);
											return 1;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return 0;
}

int C()
{
	if(isalpha(str[++inc]))
	{
		printf("input char:%c at pos:%d\n", str[inc], inc);
		if(str[++inc]=='>')
		{
			printf("input char:%c at pos:%d\n", str[inc], inc);
			if(isdigit(str[++inc]))
			{
				return 1;
			}
		}
	}
	return 0;
}

int E()
{
	if(isalpha(str[++inc]))
	{
		printf("input char:%c at pos:%d\n", str[inc], inc);
		if(str[++inc]=='=')
		{
			printf("input char:%c at pos:%d\n", str[inc], inc);
			if(isalpha(str[++inc]))
			{
				printf("input char:%c at pos:%d\n", str[inc], inc);
				if(str[++inc]=='*')
				{
					printf("input char:%c at pos:%d\n", str[inc], inc);
					if(isdigit(str[++inc]))
						return 1;
				}
			}
		}
	}
	return 0;
}

int main()
{
	printf("\nInput string is:");
	puts(str);
	printf("\n");
	parser(str);
	return 0;
}