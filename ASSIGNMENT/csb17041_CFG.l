%{
	#include<stdio.h>
	#include<stdlib.h>
	#include<string.h>
	
%}

%option noyywrap

NUM [0-9]+
ID [a-z][a-z0-9]*

%%

"("			{ return ob; }
")"			{ return cb; }
"{"			{ return oc; }
"}"			{ return cc; }

">="		{ return CmpOp; }

"while" 	{ return WHILE; }
";" 		{ return sc; }
{ID}    	{yylval.attributes.id = strdup(yytext); return ID; }
{NUM}   	{yylval.attributes.num = strdup(yytext); return NUM;}
[=+*,]	{return *yytext;}
[\t\n]+ ;

%%