#include<stdio.h>
#include<string.h>

char input[100];
int pos = 0;
int error = 0;

void E();
void Ep();
void T();
void Tp();
void F();

void E()
{
T();
Ep();
}

void Ep()
{
if (input[pos] == '+')
{
pos++;
T();
Ep();
}
}

void T()
{
F();
Tp();
}

void Tp()
{
if(input[pos] == '*')
{
pos++;
F();
Tp();
}
}




void F()
{
if(input[pos] == 'i')
{
pos++;
}
else if(input[pos] == '(')
{
pos++;
E();

if(input[pos] == ')')
pos++;
else
error = 1;
}
else
{
error = 1;
}
}

int main()
{
printf("Enter expression : ");
scanf("%s", input);
E();

if(error == 0 && input[pos] == '\0')
printf("Valid Expression\n");
else
printf("Invalid Expression\n");

return 0;
}