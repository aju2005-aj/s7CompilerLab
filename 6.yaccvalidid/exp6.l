%{
#include "y.tab.h"
%}

%%
[a-zA-Z_][a-zA-z_0-9]*  return letter;
[0-9]+                  return digit;
\n                      return 0;
.                       return yytext[0];
%%

int yywrap(void){
    return 1;
}