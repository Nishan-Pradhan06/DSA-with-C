#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *prev;
    struct node *next;
};

struct node *header;

struct node *getNode(int data)
{
    struct node *ptrnew;
    ptrnew = (struct node *)malloc(sizeof(struct node));
    if (ptrnew == NULL)
    {
        printf("\nMemory allocation failed.");
        exit(0);
    }
    ptrnew->info = data;
    ptrnew->prev = ptrnew->next = NULL;
    return ptrnew;
}

void insertAtEnd()
{
    int data;
    struct node *newNode, *ptrthis;
    printf("Enter a number:");
    scanf("%d", &data);
    newNode = getNode(data);
    if (header == NULL)
    {
        header = newNode;
        printf("Inserted at the front.");
    }
    else
    {
        for (ptrthis = header; ptrthis->next != NULL; ptrthis = ptrthis->next)
            ; // move to last node
        ptrthis->next = newNode;
        newNode->prev = ptrthis;
        printf("Inserted at the end.");
    }
}

void insertAtFront()
{
    int data;
    struct node *newNode;
    printf("Enter a number:");
    scanf("%d", &data);
    newNode = getNode(data);
    if (header == NULL)
        header = newNode;
    else
    {
        newNode->next = header;
        header->prev = newNode;
        header = newNode;
    }
    printf("Inserted at the front.");
}

void insertAfter()
{
    struct node *newNode, *ptrthis;
    int data, key;
    if (header == NULL)
        printf("List is empty.");
    else
    {
        printf("Enter a key number after which you want to insert new node:");
        scanf("%d", &key);
        for (ptrthis = header; ptrthis != NULL; ptrthis = ptrthis->next)
        {
            if (ptrthis->info == key)
            {
                printf("Enter a number:");
                scanf("%d", &data);
                newNode = getNode(data);
                if (ptrthis->next != NULL)
                {
                    newNode->next = ptrthis->next;
                    (ptrthis->next)->prev = newNode;
                }
                ptrthis->next = newNode;
                newNode->prev = ptrthis;
                printf("Inserted after %d", ptrthis->info);
                return;
            }
        }
        printf("Node not found with key value %d", key);
    }
}

void insertBefore()
{
    struct node *newNode, *ptrthis;
    int data, key;
    if (header == NULL)
        printf("List is empty.");
    else
    {
        printf("Enter a key number before which you want to insert new node:");
        scanf("%d", &key);
        for (ptrthis = header; ptrthis != NULL; ptrthis = ptrthis->next)
        {
            if (ptrthis->info == key)
            {
                printf("Enter a number:");
                scanf("%d", &data);
                newNode = getNode(data);
                newNode->prev = ptrthis->prev;
                newNode->next = ptrthis;
                if (ptrthis->prev != NULL)
                {
                    (ptrthis->prev)->next = newNode;
                }
                else
                {
                    header = newNode;
                }
                ptrthis->prev = newNode;
                printf("Inserted before %d", ptrthis->info);
                return;
            }
        }
        printf("Node not found with key value %d", key);
    }
}

void removeFromFront()
{
    int data;
    if (header == NULL)
        printf("List is empty.");
    else
    {
        data = header->info;
        if (header->next == NULL)
        {
            free(header);
            header = NULL;
        }
        else
        {
            header = header->next;
            free(header->prev);
            header->prev = NULL;
        }
        printf("%d was removed from the front.", data);
    }
}

void removeFromEnd()
{
    struct node *ptrthis;
    if (header == NULL)
    {
        printf("List is empty.");
    }
    else
    {
        if (header->next == NULL)
        {
            free(header);
            header = NULL;
        }
        else
        {
            ptrthis = header;
            while (ptrthis->next != NULL)
                ptrthis = ptrthis->next;
            if (ptrthis->prev != NULL)
                (ptrthis->prev)->next = NULL;
            free(ptrthis);
        }
        printf("Item removed from end.");
    }
}

void removeAny()
{
    int key;
    struct node *ptrthis;
    if (header == NULL)
        printf("List is empty.");
    else
    {
        printf("Enter a number you want to remove:");
        scanf("%d", &key);
        for (ptrthis = header; ptrthis != NULL; ptrthis = ptrthis->next)
        {
            if (ptrthis->info == key)
            {
                if (ptrthis == header)
                {
                    header = header->next;
                    if (header != NULL)
                        header->prev = NULL;
                }
                else if (ptrthis->next == NULL)
                    (ptrthis->prev)->next = NULL;
                else
                {
                    (ptrthis->prev)->next = ptrthis->next;
                    (ptrthis->next)->prev = ptrthis->prev;
                }
                free(ptrthis);
                printf("Item removed from list.");
                return;
            }
        }
        printf("Item does not exist in the list.");
    }
}

void display()
{
    struct node *ptrthis;
    if (header == NULL)
        printf("List is empty.");
    else
    {
        printf("\nList contains:\n");
        for (ptrthis = header; ptrthis != NULL; ptrthis = ptrthis->next)
            printf("%d\t", ptrthis->info);
    }
}

int main()
{
    char choice;
    header = NULL;
    do
    {
        printf("\nSelect your choice:");
        printf("\n1. Insert at front \n2. Insert at end\n3. Insert after \n4. Insert before\n5. Remove From Front\n6. Remove From End\n7. Remove Any\n8. Display\n9. Exit\n");
        printf("enter your choice:");
        fflush(stdin);
        choice = getchar();
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
            insertBefore();
            break;
        case '5':
            removeFromFront();
            break;
        case '6':
            removeFromEnd();
            break;
        case '7':
            removeAny();
            break;
        case '8':
            display();
            break;
        case '9':
            return 0;
        default:
            printf("Wrong selection. Try again!");
        }
        
    }
    while(1);
}