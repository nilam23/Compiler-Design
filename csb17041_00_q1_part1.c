#include<stdio.h>
#include<stdlib.h>
int main()
{
  FILE *fp=fopen("file.txt","r");
  if(fp==NULL)
  {
    printf("Cant open the file.\n");
    exit(1);
  }
  char ch;
  int count=1;
  printf("%d ", count);
  while(1)
  {
    ch=fgetc(fp);
    if(feof(fp))
      break;
    else if(ch=='\n')
    {
      count++;
      printf("\n%d ", count);
    }
    else
      printf("%c", ch);
  }
  fclose(fp);
  return 0;
}
