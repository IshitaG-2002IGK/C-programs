// $ gcc listadt_array.c -o listadt_array
// $ ./listadt_array

#include<stdio.h>
#include<stdlib.h>
#define MAX 10
void create();
void insert();
void delete();
void search();
void display();
int a, b[20], n, p, e, f, i ,pos, flag;
void main()
{
    int ch;
    printf("\n LIST ADT using ARRAY :\n");
    printf("**********MENU**********");
    printf("\n1.Create \n2.Insert \n3.Delete \4.Search \5.Display \6.Exit \n");
    do
    {
        printf("\nEnter your choice:\n");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
                    create();
                    break;
            case 2:
                    insert();
                    break;
            case 3:
                    delete();
                    break;

            case 4:
                    search();
                    break;

            case 5:
                    display();
                    break;

            case 6:
                    exit(0);
                    break;       
            
            default :
                    printf("\nWRONG OPTION!");
                
        }
    } while (ch <= 10);
    
}

void create()
{
    printf("\nEnter the nodes:");
    scanf("%d", &n);
    for(i=0;i<n;i++)
    {
        printf("Enter the elements");
        scanf("%d", &b[i]);


    }
}

void delete()
{
    printf("\nEnter the position you want to delete element in:\n");
    scanf("%d",&pos);
    if(pos >n)
    {
        printf("\nElement not found!");
    }
    else
    {

        for( i =pos+1; i>0; i++)
        {
            b[i-1]= b[i];

        }
        n--;

    }
    printf("The deleted elements are:\n");
    for (i=0;i<n;i++)
        printf("%d", b[i]);


}

void search()
{
    printf("\nEnter the element to be searched for:");
    scanf("%d",&e);
    for(i=0;i<n;i++)
    {
        if(b[i] == e)
        {
            flag=1;
            break;

        }
        if(flag == 1)
        {
            printf("\nElement found at :%d",i);
        }
        else
        {
            printf("\nElement %d not found in list !",e);
        }
    }
}

void insert()
{
    printf("\nEnter the position you want to insert element in:\n");
    scanf("%d",&pos);
    if(pos >n)
    {
        printf("\nElement cannot be inserted!");
    }
    else
    {

        for( i=MAX-1;i>pos-1;i--)
        {
            b[i+1]= b[i];

        }
        printf("\nEnter element to be inserted:");
        scanf("%d", &p);
        b[pos]= p;
        n++;

    }

    printf("The list after insertion:\n");
    display();
  
}


void display()
{
    printf("List elements are:\n");
    for(i=0;i<n;i++)
    {
        printf("%d",b[i]);
    }
}