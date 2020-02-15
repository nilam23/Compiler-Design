#include<stdio.h>
#include<stdlib.h>
int main(int argc, char *argv[])
{
	if(argc<2)
	{
		printf("Some arguments arent provided.\n");
		exit(1);
	}
	FILE *fp;
	if((fp=fopen(argv[1],"wb"))==NULL)
	{
		perror("FOPEN error:");
		exit(1);
	}
	char name[20];
	int roll, i=0;
	while(i<10)
	{
		printf("Enter name and roll no of the student %d", (i+1));
		scanf("%s %d", name, &roll);
		fwrite(name, sizeof(name), 1, fp);
		fwrite(&roll, sizeof(roll), 1, fp);
		i++;
	}
	fclose(fp);
	return 0;
}