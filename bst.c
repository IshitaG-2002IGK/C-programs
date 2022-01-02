//  $ gcc bst.c -o bst
//  $ ./bst

#include<stdio.h>
#include<stdlib.h>

struct tree
{
    int data;
    struct tree*lchild;
    struct tree*rchild;

}*t, *temp;

int element;
void inorder(struct tree*);
void preorder(struct tree*);
void postorder(struct tree*);
struct tree*create(struct tree*, int);
void find(struct tree*, int);
struct tree*insert(struct tree*, int);
struct tree*delete(struct tree*, int);
struct tree*findmin(struct tree*);
void main()
{
    int ch;
    do
    {
        printf("\nBINARY SEARCH TREEE!!\n");
        printf("\n1.Create \n2.Insert \n3.Delete \n4.Find \n5.Find minimum \n6.Inorder Traversal \n7.Preorder Traversal \n8.Postorder Traversal \n9.Exit\n");
        printf("\nEnter a choice:");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
                    printf("\nEnter the data element:");
                    scanf("%d", &element);
                    t=create(t,element);
                    inorder(t);
                    break;
            
            case 2:
                    printf("\nEnter the data element:");
                    scanf("%d", &element);
                    t=insert(t,element);
                    inorder(t);
                    break;

            case 3:
                    printf("\nEnter the data element:");
                    scanf("%d", &element);
                    t=delete(t,element);
                    inorder(t);
                    break;
                
            case 4:
                    printf("\nEnter the data element:");
                    scanf("%d", &element);
                    t=cfind(t,element);
                    break;
            
            case 5:
                    temp = findmin(t);
                    printf("\n Minimum element is:%d", t->data);
                    break;
            
            case 6:
                    inorder(t);
                    break;
            case 7:
                    preorder(t);
                    break;

            case 8:
                    postorder(t);
                    break;

            case 9: 
                    exit(0);
        

        }
    }while(ch <=9);
}