#include<stdio.h>
#include<string.h>
char op[2],arg1[5],arg2[5],result[5];
void main()
{
    FILE *fp1;
    fp1=fopen("inputB.txt","r");

    while(!feof(fp1))
    {

        fscanf(fp1,"%s%s%s%s",op,arg1,arg2,result);
        if(strcmp(op,"+")==0)
        {
            printf("\nMOV R0,%s",arg1);
            printf("\nADD R0,%s",arg2);
            printf("\nMOV %s,R0",result);
        }
        if(strcmp(op,"*")==0)
        {
            printf("\nMOV R0,%s",arg1);
            printf("\nMUL R0,%s",arg2);
            printf("\nMOV %s,R0",result);
        }
        if(strcmp(op,"-")==0)
        {
            printf("\nMOV R0,%s",arg1);
            printf("\nSUB R0,%s",arg2);
            printf("\nMOV %s,R0",result);
        }
        if(strcmp(op,"/")==0)
        {
            printf("\nMOV R0,%s",arg1);
            printf("\nDIV R0,%s",arg2);
            printf("\nMOV %s,R0",result);
        }
        if(strcmp(op,"=")==0)
        {
            printf("\nMOV R0,%s",arg1);
            printf("\nMOV %s,R0",result);
        }
    }
    fclose(fp1);
}