#include<stdio.h>
int n,e;
int epsilon[10][10];
int closure[10][10];
void findclosure(int state,int start)
{
    int i;
    closure[start][state]=1;
    for(i=0;i<n;i++)
    {
        if(epsilon[state][i]==1&&closure[start][i]==0)
        {
        findclosure(i,start);
        }
    }
}
int main(){
    int i,j;
    printf("Enter the number of states:\n");
    scanf("%d",&n);
    printf("Enter the number of epsilon transitions:\n");
    scanf("%d",&e);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
        epsilon[i][j]=0;
        closure[i][j]=0;
        }
    printf("Enter the epsilon transitions(from to):\n");
    for(i=0;i<e;i++)
    {
        int from,to;
        scanf("%d%d",&from,&to);
        epsilon[from][to]=1;
    }
    for(i=0;i<n;i++)
    {
        findclosure(i,i);
    }
    printf("\nEpsilon closure of all states:\n");
    for(i=0;i<n;i++)
    {
        printf("epsilon closure (q%d)={",i);
        for(j=0;j<n;j++)
        {
        if(closure[i][j]==1)
            printf("q%d",j);
        }
        printf("}\n");
    }
    return 0;
}