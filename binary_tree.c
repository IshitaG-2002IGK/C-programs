//  $ gcc binary_tree.c -o binary_tree
//  $ ./binary_tree

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int item;
    struct node*left;
    struct node*right;

};

void intrav(struct node*root)
{
    if(root == NULL)
        return;
    
    intrav(root->left);
    printf("%d->", root->item);
    intrav(root->right);
}

void pretrav(struct node*root)
{
    if(root == NULL)
        return;
    
    printf("%d->", root->item);
    intrav(root->left);
    intrav(root->right);
}

void posttrav(struct node*root)
{
    if(root == NULL)
        return;
    
    intrav(root->left);
    intrav(root->right);
    printf("%d->", root->item);
}

struct node*createNode(int value)
{
    struct node*newNode = malloc(sizeof(struct node));
    newNode->item = value;
    newNode->left = NULL;
    newNode->right = NULL;
}

struct node*insertLeft(struct node*root, int value)
{
    root->left = createNode(value);
    return root->left;
}

struct node*insertRight(struct node*root, int value)
{
    root->right = createNode(value);
    return root->right;
}

int main()
{
    struct node*root = createNode(1);
    insertLeft(root,2);
    insertRight(root,3);
    insertLeft(root->left,4);

    printf("Inorder traveral is:\n");
    intrav(root);
    printf("Preorder traveral is:\n");
    pretrav(root);
    printf("Postorder traveral is:\n");
    posttrav(root);
}