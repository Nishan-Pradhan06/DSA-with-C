#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define Max 100
#define TRUE 1
#define FALSE 0
struct stack
{
    int tos;
    char items[Max];
};

// created empty stack
int isEmpty(struct stack *s)
{
    return s->tos == -1;
}
// for push
int push(struct stack *s, char ch)
{
    if (s->tos == Max - 1)
    {
        {
            printf("Stack Overflow.");
            getch();
            exit(0);
        }
    }
    s->items[++s->tos] = ch;
}

char pop(struct stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack Overflow.");
        getch();
        exit(0);
    }
    return s->items[s->tos--];
}

int main()
{
    char exp[Max];
    struct stack s;
    char symb;
    int i = 0, valid = TRUE;
    s.tos = -1;
    printf("Ener your Expression: ");
    gets(exp);
    while (i < strlen(exp))
    {
        symb = exp[i];
        if (symb == '(' || symb == '{' || symb == '[')
        {
            push(&s, symb);
        }
        else if (symb == ')' || symb == '}' || symb == ']')
        {
            if (isEmpty(&s))
            {
                valid = FALSE;
            }
            else
            {
                // poppedsymb = pop(&s);
                // if ()
                // {
                //     /* code */
                // }
            }
        }
    }
}