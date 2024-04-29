#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *next;
    struct node *prev;
};

struct node *header = NULL;

struct node *getnode(int n)
{
    struct node *ptrnew;
    ptrnew = malloc(sizeof(struct node));
    if (ptrnew == NULL)
    {
        printf("Memory Allocation Failed..");
        exit(0);
    }
    ptrnew->info = n;
    ptrnew->next = NULL;
    ptrnew->prev = NULL;
    return ptrnew;
}

void insertAtFront()
{
    int n;
    struct node *ptrnew;
    printf("Enter a number: ");
    scanf("%d", &n);
    ptrnew = getnode(n);
    if (header == NULL)
    {
        header = ptrnew;
        ptrnew->next = ptrnew;
        ptrnew->prev = ptrnew;
    }
    else
    {
        ptrnew->next = header;
        ptrnew->prev = header->prev;
        header->prev->next = ptrnew;
        header->prev = ptrnew;
        header = ptrnew;
    }
    printf("%d Inserted at the front.\n", n);
}

void insertAtEnd()
{
    int n;
    struct node *ptrnew;
    printf("Enter a number: ");
    scanf("%d", &n);
    ptrnew = getnode(n);
    if (header == NULL)
    {
        header = ptrnew;
        ptrnew->next = ptrnew;
        ptrnew->prev = ptrnew;
    }
    else
    {
        ptrnew->next = header;
        ptrnew->prev = header->prev;
        header->prev->next = ptrnew;
        header->prev = ptrnew;
    }
    printf("\n%d Inserted at the end.", n);
}

void insertAfter()
{
    int key, n;
    struct node *ptrthis, *ptrnew;
    if (header == NULL)
    {
        printf("List is empty");
    }
    else
    {
        printf("Enter a number after which you want to insert a new number: ");
        scanf("%d", &key);
        ptrthis = header;
        do
        {
            if (ptrthis->info == key)
            {
                printf("Enter a new number you want to insert: ");
                scanf("%d", &n);
                ptrnew = getnode(n);
                ptrnew->prev = ptrthis;
                ptrnew->next = ptrthis->next;
                ptrthis->next->prev = ptrnew;
                ptrthis->next = ptrnew;
                break;
            }
            ptrthis = ptrthis->next;
        } while (ptrthis != header);
        if (ptrthis == header)
            printf("\nThere is no node with key value %d\n", key);
    }
}

void removeAtFront()
{
    struct node *ptrthis;
    if (header == NULL)
    {
        printf("List is Empty..");
    }
    else if (header == header->next)
    {
        free(header);
        header = NULL;
        printf("Removed from front");
    }
    else
    {
        ptrthis = header->next;
        header->next = ptrthis->next;
        ptrthis->next->prev = header;
        free(ptrthis);
        printf("Removed from front");
    }
}

void removeFromEnd()
{
    struct node *ptrthis;
    if (header == NULL)
    {
        printf("List is empty.");
    }
    else if (header == header->next)
    {
        free(header);
        header = NULL;
        printf("Removed from end.");
    }
    else
    {
        ptrthis = header->prev;
        header->prev = ptrthis->prev;
        ptrthis->prev->next = header;
        free(ptrthis);
        printf("Removed from end.");
    }
}

void removeFromAny()
{
    int key;
    struct node *ptrthis, *temp;
    if (header == NULL)
    {
        printf("List is empty.");
    }
    else
    {
        printf("Enter the key of the node you want to remove: ");
        scanf("%d", &key);
        ptrthis = header;
        do
        {
            if (ptrthis->info == key)
            {
                if (ptrthis == header)
                {
                    if (header->next == header)
                    {
                        free(header);
                        header = NULL;
                        return;
                    }
                    temp = header->next;
                    header->next = temp->next;
                    temp->next->prev = header;
                    free(temp);
                    header = header->next;
                    return;
                }
                else
                {
                    ptrthis->prev->next = ptrthis->next;
                    ptrthis->next->prev = ptrthis->prev;
                    free(ptrthis);
                    return;
                }
            }
            ptrthis = ptrthis->next;
        } while (ptrthis != header);
        printf("Node with key value %d not found.", key);
    }
}

void display()
{
    struct node *temp;
    if (header == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        temp = header;
        printf("List elements: ");
        do
        {
            printf("%d ", temp->info);
            temp = temp->next;
        } while (temp != header);
        printf("\n");
    }
}

int main()
{
    char choice;
    header = NULL;
    do
    {
        printf("\n ________Enter your choice_______\n");
        printf("|\t1. Insert At Front\t|\n|\t2. Insert from after\t|\n|\t3. Insert at last\t|\n|\t4. Remove From Front\t|\n|\t5. Remove From Last\t|\n|\t6. Remove from any \t|\n|\t7. Display\t\t|\n|\t8. Exit\t\t\t|");
        printf("\n---------------------------------\n");
        printf("--> ");
        scanf(" %c", &choice);
        switch (choice)
        {
        case '1':
            insertAtFront();
            break;
        case '2':
            insertAfter();
            break;
        case '3':
            insertAtEnd();
            break;
        case '4':
            removeAtFront();
            break;
        case '5':
            removeFromEnd();
            break;
        case '6':
            removeFromAny();
            break;
        case '7':
            display();
            break;
        case '8':
            printf("Program Exit Successfully...");
            exit(0);
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (1);

    return 0;
}
