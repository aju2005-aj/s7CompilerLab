%{
    #include <stdio.h>
    int sc=0,wc=0,lc=0,cc=0;
%}
%%
[\n]      { lc++; cc+=yyleng; }
[ \t]+    { sc++; cc+=yyleng; }
[^ \t\n]+ { wc++; cc+=yyleng; }
%%
int main(int argc ,char* argv[ ])
{
    printf("enter the input:\n");
    yylex();
    printf("the number of lines=%d\n",lc);
    printf("the number of spaces=%d\n",sc);
    printf("the number of words=%d\n",wc);
    printf("the number of characters are=%d\n",cc);
}
int yywrap( )
{
    return 1;	 	
}
