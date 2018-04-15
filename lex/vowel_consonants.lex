%{
#include<stdio.h>
int vowel_count, consonant_count, other_count;
%}

%%
[aeiouAEIOU] vowel_count++;
[0-9] other_count++;
[a-zA-Z] consonant_count++;

"result" printf("\n\t Vowel Count: %d and Consonant Count: %d and Other Count: %d.", vowel_count, consonant_count, other_count);
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