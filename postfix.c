// $ gcc postfix.c -o postfix
// $ ./postfix
 
#define SIZE 50
#include <stdio.h>
int s[SIZE];
int top = -1;
push(int elem)
{ 
    s[top++] = elem;
}
void pop()
{
    return (s[top--]);
}

main()
{
    char p[50], ch;
    int i=0, op1, op2 ;
    
}