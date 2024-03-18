
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MAX 10
#define TRUE 0
#define FALSE 1

struct stack
{
    int tos;
    int items[MAX];
};
int isFull(struct stack *s)
{
    if (s->tos == MAX - 1)
    {
        return 1;
    }
    return 0;
}

void Push(struct stack *s, int n)
{
    if (isFull(s) != 1)
    {
        printf("Items pushed...");
        s->tos++;
        s->items[s->tos] = n;
    }
    else
    {
        printf("Items cannot be  addded beacuse stack is full..");
    }
}

void isPop(struct stack *s, int num)
{
}
void isEmpty(struct stack *s)
{
    // if (s->items == MAX - 1)
    // {
    //     printf("Stack is Full..\n Please Pop the Items..");
    // }
    // return 1;
}
void display(struct stack *s)
{
    for (int i = 0; i < MAX; i++)
    {
        printf("%d  ", s->items[i]);
    }
}
int main()
{
    struct stack s;
    s.tos = -1;
    int choice;
    int num;
    while (TRUE)
    {
        printf("\n1.Push\n2.Pop\n3.Delete\n4.Exit\n5.display\n");
        printf(".........Enter your Choice..........");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            printf("Enter the Number: ");
            scanf("%d", &num);
            Push(&s, num);
            break;
        }
        case 2:
        {
            isPop(&s, num);
            break;
        }
        case 3:
        {
            isEmpty(&s);
            break;
        }
        case 4:
        {
            exit(0);
            break;
        }
        case 5:
        {

            display(&s);
            break;
        }

        default:
            break;
        }
    }
    return 0;
}