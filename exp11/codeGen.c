#include<stdio.h>
#include<string.h>
int main(){
    char e[20][50],*p;
    int n=0,t=1,i;
    printf("Enter Expression (enter exit to stop):\n");
    while(scanf("%s",e[n])&&strcmp(e[n],"exit")!=0) n++;
    printf("\nIntermediate Code : \n");
    for(i=0;i<n;i++){
        p=e[i]+2;
        while(*p){
            if(*p=='*'||*p=='/'){
                printf("t%d=%c %c %c\n",t,p[-1],*p,p[1]);
                p[-1]='0'+ t++;
                p[0]=p[1]=' ';
            }
            p++;
        }
        p=e[i]+2;
        while(*p){
            if(*p=='+'||*p=='-'){
                printf("t%d=%c %c %c\n",t,p[-1],*p,p[1]);
                p[-1]='0'+ t++;
                p[0]=p[1]=' ';
            }
            p++;
        }
        printf("%c=t%d\n",e[i][0],t-1);
    }
    return 0;
}