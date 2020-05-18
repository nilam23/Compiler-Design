%{
	#include<stdio.h>
	#include<stdlib.h>
	#include<string.h>

	int yylex();
	void yyerror(char *msg);

	char temp_buffer[10];
	int tempCount = 0;
	void getTemporary(){
    	sprintf(temp_buffer, "T[%d]", tempCount++);
	}
	
	char label1[10] = "B.true";
	char label2[10] = "B.false";
%}

%union{
    struct attributes{
		char* True;
		char* False;
		char* num;
		char* id;
		char* code;
		char* addr;
	}attributes;
}

%token ob
%token cb
%token oc
%token cc
%token CmpOp
%token WHILE
%token sc
%token ID NUM 
%left '+'
%left '*'
%nonassoc '='
%type <attributes> ID Stmt Expr NUM B St Expr1 Expr2

%%

St 	 : WHILE ob B cb oc Stmt cc {
									char buffer[100];
									sprintf(buffer, "\nBegin:\n\t%s\n%s:\n\t%s\n\tgoto Begin\n%s", $3.code, $3.True, $6.code, $3.False);
									$$.code = buffer;
								}
	 ;

B 	 : Expr1 CmpOp Expr2 		{
									$$.True = strdup(label1);
									$$.False = strdup(label2);
									char buffer[100];
									sprintf(buffer, "\nBEGIN:\n\tif %s >= %s goto %s\n\telse goto %s", $1.addr, $3.addr, $$.True, $$.False);
									$$.code = buffer;
									printf("%s\n", buffer);
								}
	 ;

Stmt : ID '=' Expr sc 			{
									char buffer[100];
									sprintf(buffer, "%s\n\t%s = %s", $3.code, $1.id, $3.addr);
									$$.code = buffer;
									printf("B.true:\n\t%s\n\tgoto BEGIN\nB.false:\n", buffer);
								}
  	 ;

Expr : Expr1 '*' Expr2			{
									char buffer[100];
  									getTemporary();
  									$$.addr = strdup(temp_buffer);
  									sprintf(buffer, "%s = %s * %s", $$.addr, $1.addr, $3.addr);
			           				$$.code = buffer;
								}

	 | Expr1 '+' Expr2			{
									char buffer[100];
  									getTemporary();
  									$$.addr = strdup(temp_buffer);
  									sprintf(buffer, "%s = %s + %s", $$.addr, $1.addr, $3.addr);
			           				$$.code = buffer;
								}								

	 ;

Expr1 : ID						{
     								$$.addr=$1.id; $$.code="";
     							}

  	  | NUM 					{
  	 								$$.addr=$1.num; $$.code="";
  	 							}
  
  	  ;

Expr2 : ID						{
     								$$.addr=$1.id; $$.code="";
     							}

  	  | NUM 					{
  	 								$$.addr=$1.num; $$.code="";
  	 							}
  
  	  ;

%%

#include "lex.yy.c"

void yyerror(char *msg){
	fprintf(stderr, "Error Message: %s\n", msg);
	return ;
}

int main() {
    printf("Enter while loop in one line as a whole:\n");
    yyparse();
    return 0;
}