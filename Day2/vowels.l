%{
	#include <stdio.h>

	int vow = 0,con=0;
%}
%%
[ \t\n ]+             ;
[aeiouAEIOU]    	  { vow++; }
[b-df-hj-np-tv-zB-DF-HJ-NP-TV-Z] { con++; }
.                     ;
%%

int main(void)
{
	printf("Enter input string: ");
	yylex();
	printf("Number of vowels = %d \n",vow);
	printf("Number of constants = %d \n",con);
	return 0;
	
}

int yywrap(void){
	return 1;
}