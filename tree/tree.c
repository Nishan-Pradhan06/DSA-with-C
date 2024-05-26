#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *father;
    struct node *left;
    struct node *right;
};
struct node *root;
struct node *getnode(int n)
{
    struct node *ptrnew;
    ptrnew = (struct node *)(malloc(sizeof(struct node)));
    if (ptrnew == NULL)

    {
        printf("Memory allocation failed.");
        getch();
        exit(0);
    }
    ptrnew->info = n;
    ptrnew->father = NULL;
    ptrnew->left = NULL;
    ptrnew->right = NULL;
    return ptrnew;
}
void bstInsert()
{
    int n;
    struct node *ptrnew, *curr = root, *parent = NULL;
    printf("\nEnter a number:");
    scanf("%d", &n);
    ptrnew = getnode(n);
    while (1)
    {
        if (curr == NULL) // it is time to insert new node
        {
            if (root == NULL) // if it is the first node in the bst,then node then make it root
            {
                root = ptrnew;
                printf("%d Inserted as the root node", n);
            }
            else // new node will be inserted as either left or right son of parent
            {
                if (n < parent->info) // insert as the left son
                {
                    parent->left = ptrnew;
                    printf("%d Inserted as left son of %d", n, parent->info);
                }
                else
                {
                    parent->right = ptrnew;
                    printf("%d Inserted as the right son of %d", n, parent->info);
                }
                ptrnew->father = parent;
            }
            return;
        }
        else if (n < curr->info) // if new value is less than current  node then go to left
        {
            parent = curr;
            curr = curr->left;
        }
        else // move to right
        {
            parent = curr;
            curr = curr->right;
        }
    }
}
void inorder(struct node *r)
{
    if (r != NULL)
    {
        inorder(r->left);
        printf("\t%d", r->info);
        inorder(r->right);
    }
}
void preorder(struct node *r)
{
    if (r != NULL)
    {
        printf("\t%d", r->info);
        preorder(r->left);
        preorder(r->right);
    }
}

void main()
{
    char choice;
    root = NULL; // initialize empty binary tree
    do
    {
        // printf("Select an option.");
        printf("\n1. Insert item\n2. Inorder traversal\n3.Preorder traversal\n4. Postorder traversal\n5. Search item \n6. Rempove item\n7.Exit");
        fflush(stdin);
        choice = getch();
        switch (choice)
        {
        case '1':
            bstInsert();
            break;
        case '2':
            inorder(root);
            break;
        case '3':
            preorder(root);
            break;
        case '4':
            break;
        case '5':
            break;
        case '6':
            break;
        case '7':
            break;
        default:
            printf("\nInvalid decleration");
        }
        getch();

    } while (1);
}