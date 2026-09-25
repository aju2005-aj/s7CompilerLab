#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

int n;

struct expr{
    char op[5];
    char op1[20];
    char op2[20];
    char res[20];
    int flag;
}arr[10];

void change(int p,char *res){
    int i;
    for(i=p+1;i<n;i++){
        if(strcmp(arr[p].res,arr[i].op1)==0){
            strcpy(arr[i].op1,res);
        }
        if(strcmp(arr[p].res,arr[i].op2)==0){
            strcpy(arr[i].op2,res);
        }
    }
}


void input(){
    int i;
    printf("\nEnter the maximum number of expressions: ");
    scanf("%d",&n);
    printf("\nEnter the input : \n");
    for(i=0;i<n;i++){
        scanf("%4s",arr[i].op);
        scanf("%19s",arr[i].op1);
        scanf("%19s",arr[i].op2);
        scanf("%19s",arr[i].res);
        arr[i].flag=0;
    }
}

void constant(){
    int op1,op2,res;
    char op;
    char res1[20];
    for(int i=0;i<n;i++){
        if(isdigit((unsigned char)arr[i].op1[0]) && isdigit((unsigned char)arr[i].op2[0])){
            op1=atoi(arr[i].op1);
            op2=atoi(arr[i].op2);
            op=arr[i].op[0];
            switch(op){
                case '+':res=op1+op2;break;
                case '-':res=op1-op2;break;
                case '*':res=op1*op2;break;
                case '/':if(op2==0){
                            printf("\nError:Division by zero");
                            continue;
                        }res=op1/op2;break;
                default:continue;
            }
            sprintf(res1,"%d",res);
            arr[i].flag=1;
            change(i,res1);
        }else if(strcmp(arr[i].op,"=")==0 && isdigit((unsigned char)arr[i].op1[0])){
            strcpy(res1,arr[i].op1);
            arr[i].flag=1;
            change(i,res1);
        }
    }
}



void output(){
    int i;
    printf("\n\nOptimized code is : \n");
    for(i=0;i<n;i++){
        if(arr[i].flag==0){
            printf("%s %s %s %s\n",arr[i].op,arr[i].op1,arr[i].op2,arr[i].res);
        }
    }
}

int main(){
    input();
    constant();
    output();
    return 0;
}