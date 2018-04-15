%{
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define YYSTYPE double
%}
%token num
%left '+''-'
%left '*''/'
%%
st: st expr '\n' {printf("VALID");}
|st '\n'
|
|error '\n' {printf("INVALID");}
;
expr: num
|expr '+' expr
|expr '/' expr
%%
int main()
{
	yyparse();
}
yylex()
{
	int ch;
	while((ch=getchar())==' ');
	if(isdigit(ch)|ch=='.')
	{
	ungetc(ch,stdin);
	scanf("%lf",&yylval);
	return num;
	}
	return ch;
}
yyerror(char *s)
{
	printf("%s", s);
}