%{
#include "y.tab.h"
%}

%%
[a-zA-Z_][a-zA-Z0-9]*           return id;
[0-9]+(\.[0-9]+)?               return num;
[+*/]                           return op;

"="                             return '=';
";"                             return ';';
"-"                             return '-';
"("                             return '(';
")"                             return ')';

[\t]                            ;       /* Ignore spaces and tabs*/
\n                              return 0;

.                               return yytext[0];
%%

int yywrap()
{
    return 1;
}