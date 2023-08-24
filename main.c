/*
The CFG:
E --> TE^
T --> FT^
E^ --> +TE^ | NULL
T^ --> *FT^ | NULL
F --> (E) | a
*/
#include <stdio.h>
#include <string.h>

void E();
void ED();
void T();
void TD();
void F();
char in[100];
int count,flag;

int main(){
printf("The CFG:\n E --> TE^\n T --> FT^\n E^ --> +TE^ | NULL\n T^ --> *FT^ | NULL\n F --> (E) | a\n ");
printf("Enter a string to be parsed: ");
gets(in);
E();
if(count==strlen(in) && flag==0)
{
    printf("String is accepted");
}
else
{
    printf("String is rejected");
}
return 0;
}

void E(){
printf("Action: E --> TE^\n");
T();
ED();
}

void T(){
printf("Action: T --> FT^ \n");
F();
TD();
}

void ED(){
if(in[count]=='+'){
printf("Action: E^ --> +TE^  Matching: '+' \n");
count++;
T();
ED();
}
else
    printf("Action: E^ --> NULL \n");
}

void TD(){
if(in[count]=='*')
{
printf("Action: T^ --> *FT^   Matching: '*' \n");
count++;
F();
TD();
}
else
    printf("Action: T^ --> NULL \n");
}

void F(){
if(in[count]=='(')
{
printf("Action: F --> (E)   Matching: '(' \n");
count++;
E();
if(in[count]==')')
{count++;
   printf("Matching: ')' \n");
}

else{flag=1;}
}
else if(in[count]=='a')
{
printf("Action: F --> a   Matching: 'a'  \n");
count++;
}
else{flag=1;}
}
