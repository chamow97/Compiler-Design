%{
#include<stdio.h>
int alphabet, digit;
%}

%%
[a-zA-Z] alphabet++;
[0-9] digit++;
"result" printf("\n\tAlphabets: %d and Digit: %d", alphabet, digit);
%%

int main()
{
	yylex();
	return 0;
}

int yywrap()
{
	return 0;
}