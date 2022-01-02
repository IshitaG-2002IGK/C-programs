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
                    find(t,element);
                    break;
            
            case 5:
                    temp = findmin(t);
                    printf("\n Minimum element is:%d", temp->data);
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
        
            default:
                    printf("Wroong option!");
        }
    }while(ch <=9);
}

struct tree*create(struct tree*t, int element)
{
    t= (struct tree*)malloc(sizeof(struct tree));
    t->data= element;
    t->lchild =NULL;
    t->rchild =NULL;
    return t;

}
void find(struct tree*t, int element)
{
    if(t==NULL)
    {
        printf("\nElement not found\n");
    }
    else if(element < t->data)
    {
        find(t->lchild,element);
    }
    else if(element > t->data)
    {
        find(t->rchild,element);
    }
    else 
    {
        printf("\nElement found at position:%d", t->data);
        return;
    }

}

struct tree*findmin(struct tree*t)
{
    if(t ==NULL)
        return NULL;
    else
    {
        if(t->lchild ==NULL)
            return t;
        else
            return (findmin(t->lchild));
    }
}

struct tree*insert(struct tree*t, int element)
{
    if(t==NULL)
    {
        t=(struct tree*)malloc(sizeof(struct tree));
        t->data= element;
        t->lchild =NULL;
        t->rchild =NULL;
        return t;
    }   
    else
    {
        if(element< t->data)
        {
            t->lchild = insert(t->lchild, element);
            
        }
        else if(element> t->data)
        {
            t->rchild = insert(t->rchild, element);
            
        }
        else if (element == t->data)
        {
            printf("\nAlready exisiting!");
        }
        return t;

    }

}

struct tree*delete(struct tree*t, int element)
{
    if(t==NULL)
    {
        printf("\nElement not found!");
    }
    else if( element <t->data)
    {
        t->lchild = delete(t->lchild, element);
    }
    else if( element > t->data)
    {
        t->rchild = delete(t->rchild, element);
    }
    else if(t->lchild && t->rchild)
    {
        temp =findmin(t->rchild);
        t->data = temp->data;
        t->rchild = delete(t->rchild, t->data);

    }
    else
    {
        temp=t;
        if(t->lchild == NULL)
            t= t->rchild;
        else if(t->rchild == NULL)
        {
            t= t->lchild;
            free(temp);
        }

    }
    return t;


}

void inorder(struct tree*t)
{
    if(t == NULL)
        return;
    else
    {
        inorder(t->lchild);
        printf("%d\n", t->data);
        inorder(t->rchild);
    }
}


void preorder(struct tree*t)
{
    if(t == NULL)
        return;
    else
    {
        printf("%d\n", t->data);
        preorder(t->lchild);
        preorder(t->rchild);
    }
}


void postorder(struct tree*t)
{
    if(t == NULL)
        return;
    else
    {
        postorder(t->lchild);
        postorder(t->rchild);
        printf("%d\n", t->data);
    }
}