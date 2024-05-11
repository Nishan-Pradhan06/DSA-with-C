#include <stdio.h>
#include <conio.h>

struct node
{
    int data;
    struct node *father;
    struct node *left;
    struct node *right;
};

struct node *CreateRoot(int data)
{
    struct node *newRoot = (struct node *)malloc(sizeof(struct node));
    if (!newRoot)
    {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    newRoot->data = data;
    newRoot->left = newRoot->right = NULL;
    return newRoot;
}

void bstInsert()
{
    int n;
    struct node *ptrnew;
    printf("\nEnter a number: ");
    scanf("%d", &n);
    ptrnew = getnode(n);
}

void main()
{
    char choice;
    
}