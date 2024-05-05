#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
#define TRUE 1
#define FALSE 0
typedef struct
{
    /* data */
    int tos;
    char items[MAX];
} stack;

int isEmpty(stack *s)
{
    return s->tos == -1;
}

int isFull(stack *s)
{
    return s->tos == MAX - 1;
}

char pop(stack *s) // one must check whether the stack is empty before calling pop
{
    if (isEmpty(s))
    {
        printf("Illegal attempt to pop an item from the empty stack.");
        getch();
        exit(0);
    }
    return s->items[s->tos--];
}

void push(stack *s, char ch)
{
    if (isFull(s))
    {
        printf("Illegal attempt to push an item into the full stack.");
        getch();
        exit(0);
    }
    s->items[++s->tos] = ch; // put new item at the next position of tos.
}

int main()
{
    stack st;
    char exp[MAX];
    char symb, poppedSymb;
    int valid = TRUE; // initially we assume that the expression is valid
    int i;
    st.tos = -1; // empty stack
    printf("Enter your expression: ");
    gets(exp);
    for (i = 0; i < strlen(exp); i++) // read all characters in the expression one by one
    {
        symb = exp[i];
        if (symb == '(' || symb == '{' || symb == '[')
        {
            push(&st, symb);
        }

        else if (symb == ')' || symb == '}' || symb == ']')
        {
            if (isEmpty(&st)) // if nothing is in the stack
            {
                valid = FALSE;
                break;
            }

            poppedSymb = pop(&st);
            if ((symb == ')' && poppedSymb != '(') || (symb == '}' && poppedSymb != '{') || (symb == ']' && poppedSymb != '['))
            {
                valid = FALSE;
                break;
            }
        }
    }

    if (!isEmpty(&st)) // no. of opener is more than no. of closing brackets
        valid = FALSE;
    if (valid)
    {
        printf("Expression is valid.");
    }

    else
    {
        printf("Expression is invalid");
    }
    return 0;
}