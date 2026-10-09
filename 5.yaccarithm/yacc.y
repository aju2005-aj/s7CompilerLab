%{
#include <stdio.h>
#include <stdlib.h>

int yylex();
int yyerror(char *s);

int valid = 1;
%}

%token num id op

%%

start : id '=' s ';'
      ;
s : id x
  | num x
  | '-' num x
  | '(' s ')' x
  ;

x : op s
  | '-' s
  | 
  ;

%%

int yyerror(char *s)
{
    valid =0;
    printf("\nInvalid expression!");
    return 0;
}

int main(){
    printf("Enter the expression : \n");
    yyparse();

    if (valid) printf("\nValid expression!\n");
    return 0;
}