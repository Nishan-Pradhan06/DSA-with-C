#include <stdio.h>
#include <conio.h>
#define TRUE 1
#define FALSE 0
#define MAX 100
#define UP 72
#define DOWN 80
#define ENTER 13
struct product
{
    int pId;
    char pName[50];
    float price;
    int stockQty;
};
struct list
{
    int count;                 // holds the count of items in the list
    struct product items[MAX]; // total capacity of the list to hold items
};
int isEmpty(struct list *);
int isFull(struct list *);
// All insert functions return TRUE/FALSE based on
// whether the insert was successful
int insertAtFront(struct list *, struct product);
int insertAtEnd(struct list *, struct product);
int insertBefore(struct list *, struct product, int);
int insertAfter(struct list *, struct product, int);
// All remove functions return TRUE/FALSE based on
// whether the removal was successful
int removeFromFront(struct list *);
int removeFromLst(struct list *);
int removeAny(struct list *, int);
// display function list all items in the list
void display(struct list *);
// saveToDisk saves all list data into a data file and returns TRUE/FALSE
// to indicate the status of success/failure
int saveToDisk(struct list *lst)
{
    int i;
    FILE *fp;
    fp = fopen("product", "wb");
    for (i = 0; i <= lst->count; i++)
        fwrite(&lst->items[i], sizeof(struct product), 1, fp);
    fclose(fp);
    printf("Saved.");
}
// readFromDisk reads data from disk to list
int readFromDisk(struct list *lst)
{
    FILE *fp;
    struct product p;
    fp = fopen("product", "rb");
    while (feof(fp))
    {
        if (fread(&p, sizeof(struct product), 1, fp))
        {
            lst->count++;
            lst->items[lst->count] = p;
        }
    }
    fclose(fp);
}
struct product newProduct()
{
    struct product p;
    printf("Enter product code:");
    scanf("%d", &p.pId);
    printf("Enter product name:");
    scanf("%s", p.pName);
    printf("Enter price:");
    scanf("%f", &p.price);
    printf("Enter quantity:");
    scanf("%d", &p.stockQty);
    return p;
}
void main()
{
    char choice;
    int y, selected = 1;
    struct list myList;
    myList.count = -1; // initially there is no items in the list
    readFromDisk(&myList);
    do
    {
        clrscr();
        y = 7; // reset menu location
        gotoxy(12, y++);
        printf("Select your choice:");
        gotoxy(12, y++);
        if (selected == 1)
            printf("[X] Insert At Front");
        else
            printf("[1] Insert At Front");
        gotoxy(12, y++);
        if (selected == 2)
            printf("[X] Insert At End");
        else
            printf("[2] Insert At End");
        gotoxy(12, y++);
        if (selected == 3)
            printf("[X] Insert Before");
        else
            printf("[3] Insert Before");
        gotoxy(12, y++);
        if (selected == 4)
            printf("[X] Insert After");
        else
            printf("[4] Insert After");
        gotoxy(12, y++);
        if (selected == 5)
            printf("[X] Remove From Front");
        else
            printf("[5] Remove From Front");
        gotoxy(12, y++);
        if (selected == 6)
            printf("[X] Remove From End");
        else
            printf("[6] Remove From End");
        gotoxy(12, y++);
        if (selected == 7)
            printf("[X] Remove Any");
        else
            printf("[7] Remove Any");
        gotoxy(12, y++);
        if (selected == 8)
            printf("[X] Display List");
        else
            printf("[8] Display List");
        gotoxy(12, y++);
        if (selected == 9)
            printf("[X] Exit");
        else
            printf("[9] Exit");
        gotoxy(12, y++);
        fflush(stdin);
        choice = getch();
        if (!choice)
            choice = getch();
        if (choice == UP)
        {
            selected--;
            if (selected == 0)
                selected = 9;
        }
        else if (choice == DOWN)
        {
            selected++;
            if (selected == 10)
                selected = 1;
        }
        else if (choice == ENTER)
        {
            switch (selected)
            {
            case 1: // do insert at front related task
                break;
            case 2: // do insert at end related task
                insertAtEnd(&myList, newProduct());
                break;
            case 3: // do insert before related task
                break;
            case 4: // do insert after related task
                break;
            case 5: // do delete from front related task
                break;
            case 6: // do delete from end related task
                break;
            case 7: // do remove any item related task
                break;
            case 8: // do list items related task
                display(&myList);
                break;
            case 9: // it is time to quit app
                saveToDisk(&myList);
                return;
            }
            getch();
        }

    } while (TRUE);
}
int isFull(struct list *lst)
{
    if (lst->count == MAX - 1)
        return TRUE;
    else
        return FALSE;
}
int isEmpty(struct list *lst)
{
    if (lst->count == -1)
        return TRUE;
    else
        return FALSE;
}
int insertAtEnd(struct list *lst, struct product p)
{
    if (isFull(lst))
    {
        printf("List is full.");
        return FALSE;
    }
    else
    {
        lst->count++;
        lst->items[lst->count] = p;
        printf("Product inserted at the end.");
        return TRUE;
    }
}
void display(struct list *lst)
{
    int i;
    if (isEmpty(lst))
        printf("List is empty.");
    else
    {
        printf("List contains:\n");
        printf("P Code\tProduct Name\tPrice\tQuantity");
        for (i = 0; i <= lst->count; i++)
        {
            printf("\n%d\t%s\t%f\t%d", lst->items[i].pId, lst->items[i].pName, lst->items[i].price, lst->items[i].stockQty);
        }
    }
}