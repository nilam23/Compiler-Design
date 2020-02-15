#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    if(argc < 2){
	perror("Usage: ./a.out <filename>");
	exit(1);
    }
    int field_number;
    printf("Enter the Field Number: \n");
    scanf("%d", &field_number);
    FILE* file = fopen(argv[1], "r");
    if(file == NULL){
	perror("File Error\n");
	exit(1);
    }
    int count = 0;
    char ch, prev_c;
    while((ch = fgetc(file)) != EOF){
	if(ch == '\n'){
	    printf("\n");
	    count = 0;
	}
	if(ch == ' ' && prev_c != ' ' && prev_c != '\n'){
	    count++;
	}
	if(count == field_number - 1){
	    printf("%c", ch);
	}
	prev_c = ch;
	/*if(ch == '\n'){
	    printf("\n");
	    count = 0;
	    prev_c = ' ';
	}
	else
	    prev_c = ch;*/
    }

}
