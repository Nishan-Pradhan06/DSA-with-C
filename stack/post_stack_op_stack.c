#include <stdio.h>
#include <conio.h>
#include <string.h>
#define MAX 100
#define FALSE 0
typedef struct
{
    char items[MAX];
    int tos;
} stack;
int isEmpty(stack *s)
{
    return s->tos == -1;
}
int isFull(stack *s)
{
    return s->tos == MAX - 1;
}
void push(stack *s, char ch)
{
}

void pop(stack *s)
{
    if (isEmpty(s))
    {
        printf("Void Delection");
        getch();
        exit(0);
    }
    s->tos--;
}
char peek(stack *s)
{
    if (isEmpty(s))
    {
        printf("void access");
        getch();
        exit(0);
    }
    return s->items[s->tos];
}
int getPrecedence(stack *s)
{

}
int main()
{
    stack opstack, poststack;
    char infix[MAX], ch;
    int i;
    opstack.tos = poststack.tos = -1;
    printf("\nEnter the expression : ");
    gets(infix);
    for (i = 0; i < strlen(infix); i++)
    {
        ch = infix[i];
        if (ch == '(')
        {
            push(&opstack, ch); // push the opener into opstack
        }
        else if (isaNumber(ch)) // push the operand into the poststack
        {
            push(&poststack, ch);
        }
        else if (ch == ')') // if sacn char is closing parenthesis
        {
            while (peek(&opstack) != '(') // see if opstack top contains openner
            {
                push(&poststack, pop(&opstack) ); //if not then pop and push into 
            }
            pop( &opstack); // remove the opening bracket from opstack
        }
        else
        {
            while (getPrecendence(peek(&opstack))>=getPrecedence(ch))
            {
                push (&poststack,pop(&opstack));//pop opstack and push in post stack
            }
            
        }
        
        
    }
}