#include <stdio.h>
#include <conio.h>
#define MAX 100
#define TRUE 1
#define FALSE 0
#define UP 78
#define DOWN 80
#define product

int insertBefore(struct list *, struct product, int);
int insertAfter(struct list *, struct product, int);
int removeFromFront(struct list *);
int removeFromLast(struct list *);
int removeAny(struct list *, int);
int saveToDisk(struct list *, char *);
int readToDisk(struct list *, char *);
void display(struct list *);



int saveToDisk(struct list *, char *){
    FILE *fp;
    fp = fopen(name, "wb");
    fwrite(lst, sizeof(struct product), lst->count, fp);
    printf("Saved..");
}

int readToDisk(struct list *, char *){
    FILE *fp;
    fp = open(name, "rb");
    while (feof(fp))
    {
    fread(lst, sizeof(struct product), lst->count, fp);
    if()*





    
    }
    
}

    int isFull(struct list *lst)
{
    if (list->count == MAX - 1)
    {
        printf("List is Full...");
    }
    else
    {
        return FALSE;
    }
}
int isEmpty(struct list *lst)
{
    if (list->count = -1)
    {
        printf("List is Empty");
    }
    else
    {
        return FALSE;
    }
}

int readFromDisk(struct list *lst)
{
}

struct product newProduct()
{
    struct product p;
    printf("Enter Product code: ");
    scanf("%d", &p.id);
};

void display(struct list *lst)
{
    int i;
    if (isEmpty(lst))
    {
        printf("List Contains: ");
        printf("P. Code\tProduct Name\tPrice\tQuantity")
        for (i = 0; i < = lst->count; i++)
        {
            printf("")
        }
    }
}

void main()
{
}