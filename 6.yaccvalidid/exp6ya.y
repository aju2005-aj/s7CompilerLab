%{
#include <stdio.h>
int yylex(void);
int yyerror(char *);

int valid=1;
%}

%token letter digit

%%
start : letter s ;

s : letter s
  | digit s
  | /* empty */
  ;
%%

int yyerror(char *s){
    printf("Its not an identifier\n");
    valid=0;
    return 0;

}

int main(){
    printf("Enter an identifier : ");
    yyparse();

    if (valid){
        printf("Its an identifier\n");
    }
    return 0;
}