%{
#include<stdio.h>
#include <ctype.h>
%}

%%
[a-z] {
printf("%c", toupper(yytext[0]));
}
. {
ECHO;
}

%%

int yywrap(void)
{
return 1;
}
int main(void)
{
yylex();
return 0;
}
