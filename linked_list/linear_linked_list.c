// linear linked list
// one way first bata suru bayara bich ma tungine

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct node *header = NULL; // define empty list..
//
struct node
{
    struct product data; // product struct ko data..
    struct node *next;   // self referencial structure../ yo node ko aafhani address hold garne field poiner xa./ arko data item lai point garne
};

//.....product ko struct..data varibale haru........
// struct product
// {
//     int id;
//     char name[50];
//     float price;
// };

// hamile deko node ko adar ma.. chaine ya bata thahunxa
struct node *getnode(int n)
{ // type casting

    struct node *ptrnew = (struct node *)malloc(sizeof(struct node)); // yasle hami lai jati byte chahinxa teti dinxa
    if (ptrnew == NULL)
    {
        printf("Memory Allocation failed..");
        getch();
        exit(0);
    }
    ptrnew->data = n; 
    ptrnew->next = NULL;
    return ptrnew;
};
// malloc le yo sruct node lai kati byte chahinxa teti byte resever garxa. ra tyo use garna pointer dinxa.. ra yaslai typecasting (struct node *) gareko xa

void insertLast(struct node *ptrnew)
{
    struct node *ptrthis = header;
    if (header == NULL)
    {
        header = ptrnew;
    }
    else
    {
        while (header->next != NULL)
        {
            ptrthis = ptrthis->next;
        }
        ptrthis->next = ptrnew;
    }
}

void display()
{
    struct node *ptrthis = header;
    if (header == NULL)
    {
        printf("List is Empty..");
    }
    else
    {
        printf("List Contains: \n");
        while (ptrthis !-NULL)
            printf("%d", ptrthis);
    }
}

void main()
{

    int choice;
    int i;
    printf(".............LINEAR LINKED LIST....................");
    for (i = 0; i < 10; i++)
    {
        insertLast(getnode(i + 1));
    }
    display();

    do
    {
        printf("Enter your choice\n");
        printf("1. Insert\n2. Remove\n3. Display\n4. Exit");
        // fflush(stdin);
        scanf("%d", &choice);
        switch (choice)
        {
        case 1: 
            
            break;
        case 2: 
            
            break;
        case 3: 
            
            break;
        case 4:
            exit(0);
            break;
        
        default:
        printf("Invlaid  Choice \n");
            break;
        }
    } while (1);
    

    getch();
}