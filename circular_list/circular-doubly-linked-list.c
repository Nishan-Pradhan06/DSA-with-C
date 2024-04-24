#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

struct node
{
    int info;
    struct node *prev;
    struct node *next;
};

typedef struct node NodeType;
NodeType *first = NULL;
NodeType *last = NULL;

void insertAtFront();
void insertAtEnd();
void removeAtFront();
void removeAtlast();
void display();

void main()
{
    char choice;

    do
    {
        printf("\n ________Enter your choice_______\n");
        printf("|\t1. Insert At Front\t|\n|\t2. Insert from after\t|\n|\t3. Insert at last\t|\n|\t4. Remove From Front\t|\n|\t5. Remove From Last\t|\n|\t6. Remove From Any\t|\n|\t7. Display\t\t|\n|\t8. Exit\t\t\t|");
        printf("\n---------------------------------\n");
        printf("--> ");
        fflush(stdin);
        choice = getche();
        switch (choice)
        {
        case '1':
            insertAtFront();
            break;
        case '2':
            // insertAfter();
            break;
        case '3':
            insertAtEnd();
            break;
        case '4':
            removeAtFront();
            break;
        case '5':
            removeAtlast();
            break;
        case '6':
            // removeAtAny();
            break;
        case '7':
            display();
            break;
        case '8':
            exit(0);
            printf("Program Exit Successfully...");
            break;

        default:
            break;
        }
    } while (TRUE);
}

void insertAtFront()
{
    int data;
    NodeType *Newnode = (NodeType *)malloc(sizeof(NodeType));
    printf("\nEnter the Number: ");
    scanf("\n%d", &data);
    Newnode->info = data;
    if (first == NULL)
    {
        first = last = Newnode;
        Newnode->next = Newnode;
        Newnode->prev = Newnode;
    }
    else
    {
        Newnode->next = first;
        first->prev = Newnode;
        first = Newnode;
        last->next = first;
        first->prev = last;
    }
    printf("--> Items %d Insert At Front Successfully..", data);
}

void insertAtEnd()
{
    int data;
    NodeType *Newnode = (NodeType *)malloc(sizeof(NodeType));
    printf("\nEnter the Number: ");
    scanf("\n%d", &data);
    Newnode->info = data;
    if (first == NULL)
    {
        first = last = Newnode;
        Newnode->next = Newnode;
        Newnode->prev = Newnode;
    }
    else
    {
        Newnode->next = first;
        first->prev = Newnode;
        last->next = Newnode;
        Newnode->prev = last;
        last = Newnode;
    }
    printf("--> Items %d Insert At Last Successfully..", data);
}

void removeAtFront()
{
    NodeType *data;
    data = first;
    if (first == NULL)
    {
        printf("Empty Circular doubly stack...");
    }
    else if (first == last)
    {
        data = first;
        first = last = NULL;
    }
    else
    {
        data = first;
        first = first->next;
        first->prev = last;
        last->next = first;
    }
    free(data);
    printf("\nItems %d Removed at front Successfully...", data);
}

void removeAtlast()
{
    NodeType *data;
    data = first;
    if (first == NULL)
    {
        printf("Empty Circular Doubly Stack...");
    }
    else if (first == last)
    {
        first = NULL;
        last = NULL;
        free(data);
    }
    else
    {
        while (data->next != last)
        {
            data = data->next;
        }
        last = data;
        last->next = first;
        first->prev = last;
        free(data->next);
    }
    printf("\nItems %d Removed at End Successfully...", data->info);
}

void display()
{
    NodeType *ptr;
    ptr = first;
    if (first == NULL)
    {
        printf("Empty Circular Doubly Linked List");
    }
    else
    {
        printf("\n __________________________________________");
        printf("\n|___Circular Doubly Linked List Contain___|\n");

        do
        {
            printf("\t|\t%d\t|\n", ptr->info);
            ptr = ptr->next;
        } while (ptr != first);
        printf("\t|_______________|\n");
    }
}
