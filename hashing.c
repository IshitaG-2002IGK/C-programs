
// $ gcc hashing.c -o hashing
// $ ./hashing
 
#include<stdio.h>
#include <stdlib.h>

#define MAX 10

void main()
{
    int a[MAX], key, num, i;
    int ans;
    int create(int);
    void linear_prob(int [],int , int);
    void display(int []);
    printf ("Collision using open addressing method :");
    for(i=0;i<MAX;i++)
        a[i]=-1 ;
    do
    {
        printf("Enter the number:\n");
        scanf("%d", &num);
        key = create (num);
        linear_prob(a, key, num);
        printf("Do you wish to continue?(1/0");
        scanf("%d", &ans);
    
    } while(ans == 1);
    display(a);
}

int create (int num)
{
    int key;
    key = num % 10;
    return key;

}

void linear_prob( int a[MAX], int key, int num)
{
    int flag, count = 0, i;
    void display (int a[])
        flag = 0;
    if (a[key]==-1)
    {
        a[key]= num;
    }
    else
    {
        i = 0;
        while(i < MAX);
        {
            if(a[i]!=-1)
                count ++;
                key ++;

        }

        while( count == MAX)
        {
            printf ("****The Hash Table is full ****");
            display(a);
            exit(1);

        }
        for (i=key+1 ; i<MAX;i++)
            if(a[i]!=-1)
            {
                a[i]=num;
                flag=1;
                break;

            }
        
        for (i=0 ; i<key && flag==0;i++)
            if(a[i]!=-1)
            {
                a[i]=num;
                flag=1;
                break;
                
            }
    }
}

void display(int a[MAX])
{
    int i;
    printf("Hash Table is :");
    for( i=0;i<MAX;i++)
        scanf("%d.....%d",i,a[i]);
}



