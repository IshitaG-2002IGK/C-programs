// $ gcc postfix.c -o postfix
// $ ./postfix
 
#define SIZE 50
#include <ctype.h>
#include <stdio.h>
int s[SIZE];
int top = -1;
int push(int elem)
{ 
    s[top++] = elem;
}
int pop()
{
    return (s[top--]);
}

int main()
{
    char p[50], ch;
    int i=0, op1, op2 ;
    printf("Enter the expression :");
    scanf("%s",p);
    while ((ch = p[i++])!= '\0')
    {
        if (isdigit(ch))
            push(ch-'0');
        
        else
        {
            op2 = pop();
            op1 = pop();
            switch (ch)
            {
                case '+' : 
                            push(op1+op2);
                            break;
                case '-' : 
                            push(op1-op2);
                            break;
                case '*' : 
                            push(op1*op2);
                            break;
                case '/' : 
                            push(op1/op2);
                            break;
            }
        }
    }

    printf("\n Given Postfix Expn: %s\n",p);
    printf("\n Result after Evaluation: %d\n",s[top]);
 
}








// #define SIZE 50
// #include <ctype.h>
// #include <stdio.h>

// int s[SIZE];
// int top=-1;
// int push(int elem)
// {
// s[++top]=elem;
// }
// int pop()
// {
// return(s[top--]);
// }
// int main()
// {
// char pofx[50],ch;
// int i=0,op1,op2;
// printf("<-----Stack Application: Evaluating Postfix Expression----->\n");
// printf("\n\nEnter the Postfix Expression : ");
// scanf("%s",pofx);
// while( (ch=pofx[i++]) != '\0')
// {
//  if(isdigit(ch)) 
// push(ch-'0');
//  else
//  {
//  op2=pop();
//  op1=pop();
//  switch(ch)
//  {
//  	case '+':
//             push(op1+op2);
//             break;
//     case '-'
//             push(op1-op2);
//             break;
//  	case '*':
//             push(op1*op2);
//             break;
//  	case '/':
//             push(op1/op2);
//             break;
//  }
// }
// }
// printf("\n Given Postfix Expn: %s\n",pofx);
// printf("\n Result after Evaluation: %d\n",s[top]);
// }