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
        printf("\nMemory allocation failed");
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
    printf("Enter a number: ");
    scanf("%d", &data);
    newNode = getNode(data);
    if (header == NULL)
    {
        header = newNode;
        printf("Inserted at the front\n");
    }
    else
    {
        for (ptrthis = header; ptrthis->next != NULL; ptrthis = ptrthis->next)
            ;
        ptrthis->next = newNode;
        newNode->prev = ptrthis;
        printf("Inserted at end\n");
    }
}
void insertBefore()
{
    int data;
    struct node *newNode, *prthis;
}

void removeFromFront()
{
    if (header == NULL)
        printf("List is empty\n");
    else if (header->next == NULL)
    {
        printf("%d was removed from the front\n", header->info);
        free(header);
        header = NULL;
    }
    else
    {
        struct node *temp = header;
        header = header->next;
        header->prev = NULL;
        printf("%d was removed from the front\n", temp->info);
        free(temp);
    }
}
void removeFromEnd()
{
    struct node *ptrthis;
    if (header == NULL) // list is empty
    {
        printf("List is empty");
    }
    else // if the list contains one or more items
    {
        if (header->next == NULL) // if there is only one items in the list
        {
            free(header);
            header = NULL;
        }
        else // if list containsmore than one items
        {
            ptrthis = header;
            while (ptrthis->next != NULL) // until we reach the last mode
            {
                ptrthis = ptrthis->next; // go forward one node.
            }
            (ptrthis->prev)->next = NULL;
            free(ptrthis); // freeing the last node
        }
        printf("Items removed frm end");
    }
}
void removeAny()
{
    int key;
    struct node *ptrthis;
    if (header ==NULL)

    {
        printf("List is empty");
    }
    else{
        printf("Enter a number you want to remove");
        scanf("%d",&key);
        for (ptrthis = header; ptrthis != NULL;ptrthis=ptrthis->next)
        {
            if (ptrthis->info==key) //if node found
            {
                if (ptrthis==header) //if it is first items
                {
                    /* code */
                    header = header->next;
                    if (header!=NULL)
                    {
                        header->prev = NULL;
                    }
                    
                }
                else if (ptrthis->next==NULL)//if it is last item
                {
                   (ptrthis->prev)->prev
                }
                
                
                
              
            }
            
        }
        }
    
}

void display()
{
    struct node *ptrthis;
    if (header == NULL)
        printf("List is empty.\n");
    else
    {
        printf("\nList contains: \n");
        for (ptrthis = header; ptrthis != NULL; ptrthis = ptrthis->next)
            printf("%d\t", ptrthis->info);
        printf("\n");
    }
}

int main()
{
    char choice;
    header = NULL; // initialize empty list;

    do
    {
        printf("Select Your Choice: ");
        printf("\n1.Insert From End \n2.Insert From front\n3.Insert From mid\n4.Remove from front\n5.Remove from end \n6.Display \n7.Exit\n");
        fflush(stdin);
        choice = getchar();
        switch (choice)
        {
        case '1':
            insertAtEnd();
            break;
        case '2':

            break;
        case '3':

            break;
        case '4':
            removeFromFront();
            break;
        case '5':
            removeFromEnd();
            break;
        case '6':
            display();
            break;
        case '7':
            return 0;
            break;
        default:
            printf("Wrong Selection. Try Again.\n");
        }
        getchar();
    } while (1);

    return 0;
}