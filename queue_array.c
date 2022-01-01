// $ gcc queue_array.c -o queue_array
// $ ./queue_array

#include<stdio.h>
#include<stdlib.h>
void enQueue(int);
void deQueue();
void display();
int n, queue[100], front = -1,rear =-1;
void main()
{
    int value, choice ;
    printf("\nQueue ADT using array\n");
    printf("\nEnter the size of array\n");
    scanf("%d", &n);
    printf("******MENU********");
    printf("\n1.Enqueue \n2.Dequeue \n3.Display \n4.Exit \n");
    while(1)
    {
        printf("\nEnter your choice :\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 :
                    printf("\nEnter value to be inserted:\n");
                    scanf("%d", &value);
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
                    printf("Wrong option!");
                    
        }
    }
}

void enQueue(int value)
{
    if(rear == n-1)
    {
        printf("\nThe Queue is full, insertion not possible!\n");
    }
    else
    {
        if(front==-1)
            front =0;
        rear ++;
        queue[rear] = value ;
        printf("\nInsertion success!");

    }
}

void deQueue()
{
    if(front ==-1 && front>rear)
    {
        printf("\nQueue is empty, deletion not possible\n");
    }
    else
    {
        printf("Deleted element is:%d", queue[front]);
        front ++;

    }
}

void display()
{
    if(rear == -1)
    {
        printf("\nQueue is empty!!\n");
    }
    int i;
    for(i=front; i<rear; i++)
        printf("%d\n", queue[i]);
}