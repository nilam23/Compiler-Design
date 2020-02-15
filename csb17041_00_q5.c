#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, char *argv[])
{
	if(argc<2)
	{
		printf("Some arguments arent provided.\n");
		exit(1);
	}
	FILE *fp=fopen(argv[1], "rb");
	if(fp==NULL)
	{
		perror("FOPEN error:");
		exit(1);
	}
	char ch;
	if(argv[1][strlen(argv[1])-3]=='b')
	{
		while(1)
		{
			fread(&ch, sizeof(ch), 1, fp);
			if(feof(fp))
				break;
			if(ch >= ':' && ch <= '}')
			{
				printf("%c", ch);
			}
		}
	}
	fclose(fp);
	return 0;
}