// $ gcc poly_add.c -o poly_add
// $ ./poly_add

#include<stdio.h>
#include<stdlib.h>

struct link 
{
    int coeff;
    int pow;
    struct link *next;
};

struct link *poly1=NULL, *poly2=NULL, *poly=NULL;

void create(struct link *node)
{
    char ch;
    do
    {
        printf("Enter the coefficient value:\n");
        scanf("%d",&node->coeff);
        printf("Enter the power value:\n");
        scanf("%d",&node->pow);
        node->next = (struct link*)malloc(sizeof(struct link));
        node = node->next;
        node->next = NULL;
        printf("\n Do you wish to continue(y/n) :");
        ch = getchar();

    }while (ch =='y' || ch =='Y');
}

void show(struct link *node)
{
    while(node->next != NULL)
    {
        printf("%dx^%d", node->coeff, node->pow);
        node =node->next;
        if(node->next != NULL)
            printf("+");

    }
}

void poly_add(struct link *poly1, struct link *poly2, struct link *poly)
{
    while(poly1 -> next && poly2 ->next)
    {
        if( poly1->pow > poly2->pow)
        {
            poly->pow = poly1->pow ;
            poly->coeff = poly1->coeff ;
            poly1 = poly1->next;
        }
        else if( poly1 -> pow < poly2 ->pow)
        {
            poly->pow = poly2->pow ;
            poly->coeff = poly2->coeff ;
            poly2 = poly2->next;
        }
        else
        {
            poly->pow = poly1->pow;
            poly->coeff = poly1->coeff + poly2->coeff;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }

        poly -> next = (struct link *)malloc(sizeof(struct link));
        poly = poly->next;
        poly->next = NULL;

    }
    while(poly1 -> next || poly2 ->next)
    {
        if(poly1 -> next)
        {
            poly->pow = poly1->pow ;
            poly->coeff = poly1->coeff ;
            poly1 = poly1->next;
        }
        if(poly2 -> next)
        {
            poly->pow = poly2->pow ;
            poly->coeff = poly2->coeff ;
            poly2 = poly2->next;
        }
        poly -> next = (struct link *)malloc(sizeof(struct link));
        poly = poly->next;
        poly->next = NULL;

    }
}
void main()
{
    char ch;
    do
    {
        poly1 = (struct link *)malloc(sizeof(struct link));
        poly2 = (struct link *)malloc(sizeof(struct link));
        poly  = (struct link *)malloc(sizeof(struct link));
        printf("Enter the 1st number:\n");
        create(poly1);
        printf("Enter the 2nd number:\n");
        create(poly2);
        printf("Display the 1st number:\n");
        show(poly1);
        printf("Display the 2nd number:\n");
        show(poly2);
        poly_add(poly1, poly2, poly);
        printf("Additon of the polynomials are :\n");
        show(poly);
        printf("Wish to add more numbers :");
        ch = getchar();

    }while (ch =='y' || ch =='Y');
}