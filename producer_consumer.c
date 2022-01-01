//  $ gcc producer_consumer.c -o producer_consumer
//  $ ./producer_consumer
 

#include<stdio.h>
int front=-1, rear=-1, buffer[5];
void consume()
{
    if(front==-1)
        printf("The consumer cannot consume until producer produces it!");
    else
    {
        printf("The consumed item is :%d", buffer[front]);
        if(front==rear)
            front=rear=-1;
        else
            front = ((front+1)%5);
    }
}
void producer(int x)
{
    if(front == ((rear+1)%5))
        printf("The producer cannot produce until consumer has it!");
    else
    {   
        if(front ==-1)
            front=rear=0;
        else
            rear = ((rear+1) %5);
            buffer[rear]= x;
            printf("The buffer item is :%d", buffer[rear]);

    }
}

void display()
{
    int i;
    if(rear >= front)
    {
        for(i=front;i<=rear;++i)
            printf("%d", buffer[i]);
    }
    else
    {
        for(i=front;i<=5;++i)
            printf("%d", buffer[i]);
        for(i=0;i<=rear;++i)
            printf("%d", buffer[i]);
    }
}

void main()
{
    int ch, z;
    do
    {
        printf("PRODUCER_CONSUMER PROBLEM\n");
        printf("Enter a choice");
        printf("\n1. Produce an item \n2.Consume an item \n3. Display items \n4 Exit");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: 
                    printf("Enter the item to insert into buffer");
                    scanf("%d",&z);
                    producer(z);
                    break;
                
            case 2:
                    consume();
                    break;
                
            case 3:
                    display();
                    break;
                
            case 4:
                    exit(0);
                    break;
                

        }

    }while (ch<=4);

}
