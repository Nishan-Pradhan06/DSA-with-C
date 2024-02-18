#include <stdio.h>

#define MAX 10
#define TRUE 1
#define FALSE 0

struct stack
{
    int tos;        // top of the stack
    int items[MAX]; // array is used as storehouse of stack
};

int isEmpty(struct stack *s)
{
    // return s-> tos =-1;
    if (s->tos == -1)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

int isFull(struct stack *s)
{
    if (s->tos == MAX - 1)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

int push(struct stack *s, int num)
{
    if (isFull(s))
    {
        return FALSE;
    }
    else
    {
        s->tos++;
        s->items[s->tos] = num;
        return TRUE;
    }
}

int pop(struct stack *s)
{
    if (isEmpty(s))
    {
        return -1; // Stack underflow
    }
    else
    {
        return s->items[s->tos--];
    }
}

int peek(struct stack *s)
{
    return s->items[s->tos];
}

void display(struct stack *s)
{
    int i;
    if (isEmpty(s))
    {
        printf("\nStack is Empty.");
    }
    else
    {
        printf("\nStack contains:\n");
        for (i = s->tos; i >= 0; i--)
        {
            printf("%d\n", s->items[i]);
        }
    }
}

int main()
{
    struct stack s;
    char choice;
    int num;
    s.tos = -1; // empty stack initialized
    do
    {
        printf("\nSelect an option :\n1.push\n2.pop\n3.List\n4.Exit\n");
        fflush(stdin);
        choice = getchar();
        switch (choice)
        {
        case '1':
            printf("\nEnter a number: ");
            scanf("%d", &num);
            if (push(&s, num))
            {
                printf("\nItem pushed into the stack successfully");
            }
            else
            {
                printf("\nStack overflow. Pop some items before push.");
            }
            break;
        case '2':
            num = pop(&s);
            if (num == -1)
            {
                printf("\nStack underflow. Nothing to pop.");
            }
            else
            {
                printf("\n%d was popped from the stack", num);
            }
            break;
        case '3':
            display(&s);
            break;
        case '4':
            printf("\nSorry to see you go. ");
            return 0;
        default:
            printf("\nInvalid option. Please select again.");
            break;
        }
    } while (TRUE);
}
