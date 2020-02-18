%{
#include <stdio.h>
#include "token.h"
%}

%%
[\n \t] {continue;}
"int" {printf("--TOK_INT, %d>\n", TOK_INT);}
"if" {printf("--TOK_IF, %d>\n", TOK_IF);}
"=" {printf("--TOK_EQUAL, %d>\n", TOK_EQUAL);}
"==" {printf("--TOK_COMPARISON, %d>\n", TOK_COMPARISON);}
"else" {printf("--TOK_ELSE, %d>\n", TOK_ELSE);}
"(" {printf("--TOK_LEFTBKT, %d>\n", TOK_LEFTBKT);}
")" {printf("--TOK_RIGHTBKT, %d>\n", TOK_RIGHTBKT);}
"{" {printf("--TOK_LEFTCRL, %d>\n", TOK_LEFTCRL);}
"}" {printf("--TOK_RIGHTCRL, %d>\n", TOK_RIGHTCRL);}
";" {printf("--TOK_SEMICOLON, %d>\n", TOK_SEMICOLON);}
"return" {printf("--TOK_RETURN, %d>\n", TOK_RETURN);}
[0-9]+ {printf("%s--TOK_NUM, %d>\n", yytext, TOK_DIGIT);}
[a-zA-Z][a-zA-z0-9]* {printf("%s--TOK_ID, %d>\n", yytext, TOK_ID);}

%%

int main(){
    yylex();
}
