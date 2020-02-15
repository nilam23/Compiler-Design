#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *fp=fopen("file.txt", "r");
	if(fp==NULL)
	{
		perror("FOPEN error:");
		exit(1);
	}
	char buffer[50];
	int count=1;
	//printf("%d ",count);
	while(1)
	{
		if(feof(fp))
			break;
		else{
			fgets(buffer, sizeof(buffer), fp);
			printf("%d %s",count,buffer);
			count++;
			//printf("%d ",count);
		}
	}	
}