// $ gcc stack_linked.c -o stack_linked
// $ ./stack_linked

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node*next;
}*top =NULL;

void push(int);
void pop();
void display();
void main()
{
    int value, ch;
    printf("\nStack ADT using Linked Lists!\n");
    printf("*****MENU******");
    printf("\n1.PUSH \n2.POP \n3. DISPLAY \4.EXIT\n");
    while(1)
    {
        printf("\nEnter you choice:\n");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: 
                    printf("\nEnter the element to be pushed:");
                    scanf("%d", &value);
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
            default("\nWrong option!");
        }
    }
}

void push(int value)
{
    struct node*newNode;
    newNode = (struct node*)malloc(sizeof(stucr node));
    newNode->data = element;
    if(top == NULL)
        newNode->next=NULL;
    else    
        newNode->next=top;
    
    top= newNode;
    printf("\nInsetion Success");
}

void pop()
{
    if(top == NULL)
        printf("Stack is empty");
    else
    {   
        struct node*temp =top;
        printf("Deleted element is:%d", temp->data);
        top = temp->next;
        free(temp);
    }


}

void display()
{
    if(top==NULL)
    {
        printf("\nStack is empty");
    }
    else
    {
        struct node*temp= top;
        while(temp=>next!=NULL)
        {
            printf("|%d|-->", temp->data);
            temp = temp->next;

        }
    }
    printf("|%d|--<NULL", temp->data);
    

}