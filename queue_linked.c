// $ gcc queue_linked.c -o queue_linked
// $ ./queue_linked

#include<stdio.h>
#include<stdlib.h>
 
struct node
{
    int data;
    struct node*next;

}*front=NULL, *rear=NULL;

void enQueue(int);
void deQueue();
void display();
void main()
{
    int ch, value;
    printf("\nQueue ADT using Linked Lists\n");
    printf("*****MENU******");
    printf("\n1.Enqueue \n2.Dequeue \n3.Display \n4.Exit\n");
    while(1)
    {
        printf("\nEnter your choice:\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                    printf("\nEnter to enqueue:");
                    scanf("%d",&value);
                    enQueue(value);
                    break;
            case 2:
                    deQueue();
                    break;
            case 3: 
                    display();
                    break;
            case 4: 
                    exit(0);
                    break;
            default:
                    printf("\nWrong option!");

        }
    }
}

void enQueue(int value)
{
    struct node*newNode;
    newNode=(struct node)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;
    if(front ==NULL)
        front=rear=0;
    else
    {
        rear = rear->next;
        rear = newNode;
    
    }
        
}


void deQueue()
{
    if(front == NULL)
        printf("\nQueue is empty");
    else
    {
        struct node*temp = front;
        printf("\nThe deleted element is:%d", temp->data);
        front = front->next;
        free(temp);

    }
}

void display()
{
    if( front == NULL)
        printf("\nThe queue is empty");
    else
    {
        struct node*temp = front;
        if(temp->next!= NULL)
        {

            printf("%d-->", temp->data);
            temp = temp->next;
        }
    }
    printf("%d-->NULL", temp->data);
}