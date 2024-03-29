// $ gcc stack_array.c -o stack_array
// $ ./stack_array

#include<stdio.h>
#include<stdlib.h>
void push(int);
void pop();
void display();
int n, stack[100], top =-1;
void main()
{
    int value, choice;
    printf("\nStack ADT using array\n");
    printf("\nEnter the size of array\n");
    scanf("%d", &n);
    printf("******MENU********");
    printf("\n1.Push \n2.Pop \n3.Display \n4.Exit \n");
    while(1)
    {
        printf("\nEnter your choice :\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: 
                    printf("\n Enter the value to be inserted:\n");
                    scanf("%d",&value);
                    push(value);
                    break;
            
            case 2:
                    pop();
                    break;
            
            case 3: 
                    display();
                    break;
            
            case 4:
                    exit(0);
                    break;
            default:
                    printf("Wrong option!");
                
        }
    }

}

void push(int value)
{
    if(top == n-1)
    {
        printf("The stack is full, insertion is not possible \n");
    }
    else
    {
        top ++;
        stack[top] = value;
        printf("inertion Success!");

    }
}

void pop()
{
    if(top == -1)
    {
        printf("The stack is empty, deletion is not possible\n");
    }
    else
    {
        printf("The deleted element is :%d", stack[top]);
        top -- ;

    }
}

void display()
{
    if(top == -1)
    {
        printf("The stack is empty!\n");
    }
    int i;
    printf("The stack elements are:\n");
    for(i=top ;i>=0; i--)
    {
        printf("|%d|\n", stack[i]);
    }
}