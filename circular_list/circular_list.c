#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *next;
};

struct node *header;
struct mode *getnode(int);
void insertAtFront();
void insertAtEnd();
void insertAtAfer();
void removeFromFront();
void removeFromEnd();
void removeFromany();
void display();

void main()
{
    char choice;
    header = NULL;
    do
    {
        printf("Select and option:\n1. Insert at Front\n2. Insert at end");
        printf("\n3. Insert at before\n4. Remove From Front");
        printf("\n5. Remove From end\n6. Remove from any\n7. Display List\n8. Exit");
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
            insertAtAfer();
            break;

        case '4':
            removeFromFront();

            break;

        case '5':
            removeFromEnd();
            break;

        case '6':
            removeFromany();
            break;

        case '7':
            display();
            break;
        case '8':
            exit(0);
            break;

        default:
            printf("Invalid Choice \n");
            break;
        }
    } while (1);
}

struct node *getnode(int n)
{
    struct node *ptrnew;
    ptrnew = (struct node *)malloc(sizeof(struct node));
    if (ptrnew == NULL)
    {
        printf("Memory allocation Failed.\n");
        getch();
        exit(0);
    }
    ptrnew->info = n;
    ptrnew->next = NULL;
}

void insertAtFront()
{
    int data;
    struct node *ptrnew;
    printf("Enter a number: ");
    scanf("%d", &data);
    ptrnew = getnode(data);
    if (header == NULL)
    {
        header = ptrnew;
        ptrnew->next = ptrnew; // point to self as this is the first and last node.
    }
    else
    {
        // if list contains one or many  items
        ptrnew->next = ptrnew;
    }
    printf("Items insert  at front successfully\n");
}