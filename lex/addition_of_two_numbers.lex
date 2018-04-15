%{
	#include<stdio.h>
	int firstNumber, result, secondNumber;	
%}

%%
"ip1" printf("\n\t Enter first number: "); scanf("%d", &firstNumber);
"ip2" printf("\n\t Enter second number: "); scanf("%d", &secondNumber);
"result" printf("\n\t Result: %d", firstNumber + secondNumber);
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