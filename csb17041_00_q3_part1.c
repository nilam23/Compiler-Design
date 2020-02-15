#include<stdio.h>
#include<stdlib.h>
int main(int argc, char *argv[])
{
	if(argc<2)
	{
		printf("Some arguments are missing.\n");
		exit(1);
	}
	FILE *fp=fopen(argv[1], "w");
	if(fp == NULL)
	{
		perror("FOPEN error:");
		exit(1);
	}
	char name[21], roll_no[11];
	int roll, i;
	while(i<10){
		printf("Enter the name of the student %d:",(i+1));
		scanf("%s", name);
		printf("Enter the roll no of the student %d:", (i+1));
		scanf("%d", &roll);
		fputs(name, fp);
		fputc(' ', fp);
		sprintf(roll_no, "%d", roll);
		fputs(roll_no, fp);
		fputc('\n', fp);
		i++;
	}
}