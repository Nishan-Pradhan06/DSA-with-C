#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define Max 10
#define TRUE 0
#define FALSE 1
struct queue
{
    int front;
    int rear;
    int items[Max];
};
int getNextIndex(int i)
{
    if (i == Max - 1)
        return TRUE;
    else
        return i + 1;
}
int isEmpty(struct queue *q)
{
    if (q->front == q->rear)
        return TRUE;
    else
        return FALSE;
    // return q->front==q->rear;
}
int isFull(struct queue *q)
{
    if (q->front == getNextIndex(q->rear)) // if rear meets front on increment it is full conditions
        return TRUE;
    else
        return FALSE;
}
void isInsert(struct queue *q, int n)
{
    if (isFull(q))
    {
        printf("Queue is Full.");
        getch();
        return;
    }
    q->rear == getNextIndex(q->front); // increment rear
    q->items[q->rear] = n;             // insert element in the next of rear index
    printf("Element inserted successfully.\n");
}
void isDelete(struct queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is Empty.");
        getch();
        return;
    }
    q->front = getNextIndex(q->front);
    printf("Items Delete Sucessufully.");
}
void isDisplay(struct queue *q)
{
    int i;
    if (isEmpty(q))
    {
        printf("Queue is Empty.");
        getch();
        return;
    }
    i = getNextIndex(q->front);
    printf("\nElements are : \n");
    do
    {
        printf("%d\t", q->items[i]);
        i = getNextIndex(i);
    } while (i != q->rear);
}
void main()
{
    struct queue q;
    int num;
    int choice;
    q.front = q.rear = Max - 1; // create empty queue initialization
    printf("enter your choice");
    printf("\n1.Push \n2.Delete \n3.Display \n4.exit\n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
    {
        printf("\nEnter the Number: ");
        scanf("%d", &num);
        isInsert(&q, num);
        break;
    }
    case 2:
        isDelete(&q);
        break;
    case 3:
        isDisplay(&q);
        break;
    case 4:
        exit(0);
    default:
        printf("Invalid choice");
    }
}