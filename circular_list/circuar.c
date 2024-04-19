// singly circular list implementation
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *next;
};
struct node *header;
struct node *getnode(int);
void insertAtFront();
void insertAtEnd();
void insertAfter();
void removeFromFront();
void removeFromEnd();
void removeAny();
void display();
void main()
{
    char choice;
    header = NULL; // initialize empty list
    do
    {
        clrscr();
        printf("Select an option:\n1. Insert at front\n2. Insert at end");
        printf("\n3. Insert after\n4. Remove from front\n5. Remove from end");
        printf("\n6. Remove any\n7. Display list\n8. Exit");
        fflush(stdin);
        choice = getche();
        switch (choice)
        {
        case '1':
            insertAtFront();
            break;
        case '2':
            insertAtEnd();
            break;
        case '3':
            insertAfter();
            break;
        case '4':
            removeFromFront();
            break;
        case '5':
            removeFromEnd();
            break;
        case '6':
            removeAny();
            break;
        case '7':
            display();
            break;
        case '8':
            return;
        }
        getch();
    } while (1);
}
struct node *getnode(int n)
{
    struct node *ptrnew;
    ptrnew = (struct node *)malloc(sizeof(struct node));
    if (ptrnew == NULL)
    {
        printf("Memory allocation failed.");
        getch();
        exit(0);
    }
    ptrnew->info = n;
    ptrnew->next = NULL;
    return ptrnew;
}
void insertAtFront()
{
    int data;
    struct node *ptrnew;
    printf("Enter a number:");
    scanf("%d", &data);
    ptrnew = getnode(data);
    if (header == NULL)
    {
        header = ptrnew;
        ptrnew->next = ptrnew; // point to self as this is the first and last node.
    }
    else // if list contains one or many items
    {
        ptrnew->next = header->next;
        header->next = ptrnew;
    }
    printf("Item inserted at the front.");
}
void insertAtEnd()
{
    int data;
    struct node *ptrnew;
    printf("Enter a number:");
    scanf("%d", &data);
    ptrnew = getnode(data);
    if (header == NULL)
    {
        header = ptrnew;
        ptrnew->next = ptrnew; // point to self as this is the first and last node.
    }
    else // if list contains one or many items
    {
        ptrnew->next = header->next;
        header->next = ptrnew;
        header = header->next; // simply advance header by one position
    }
    printf("Item inserted at the end.");
}
void insertAfter()
{
    int data, key;
    struct node *ptrnew, *ptrthis;
    if (header == NULL)
        printf("List is empty.");
    else
    {
        printf("\nEnter a number after which you want to insert:");
        scanf("%d", &key);
        ptrthis = header->next; // start from first item
        do
        {
            if (ptrthis->info == key) // if item found, then insert after it.
            {
                printf("Enter new number:");
                scanf("%d", &data);
                ptrnew = getnode(data);
                ptrnew->next = ptrthis->next;
                ptrthis->next = ptrnew;
                if (ptrthis == header) // if item is inserted after last node, then make the newly inserted node as last node.
                    header = header->next;
                printf("Item inserted after %d", key);
                return; // return immediately after inserting new item.
            }
            ptrthis = ptrthis->next; // move to next item
        } while (ptrthis != header->next); // until we complete one cycle
    }
}
void removeFromFront()
{
}
void removeFromEnd()
{
}
void removeAny()
{
}
void display()
{
    struct node *ptrthis;
    if (header == NULL)
        printf("List is empty.");
    else
    {
        printf("\nList contains:\n");
        ptrthis = header->next;
        do
        {
            printf("%d\t", ptrthis->info);
            ptrthis = ptrthis->next;
        } while (ptrthis != header->next);
    }
}
