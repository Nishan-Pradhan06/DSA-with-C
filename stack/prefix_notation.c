// WAP to convert infix notation of an expression to Prefix Notation  using stack (array)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100

struct Stack
{
    int top;
    char items[MAX_STACK_SIZE];
};

void push(struct Stack *stack, char item)
{
    if (stack->top == MAX_STACK_SIZE - 1)
    {
        printf("Stack Overflow\n");
        exit(EXIT_FAILURE);
    }
    stack->items[++stack->top] = item;
}

char pop(struct Stack *stack)
{
    if (stack->top == -1)
    {
        printf("Stack Underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack->items[stack->top--];
}

int isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '$');
}

int getPrecedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '$')
        return 3;
    else
        return 0;
}

int isdigitorchar(char c)
{
    return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

// Function to reverse a string
void reverseString(char str[])
{
    int length = strlen(str);
    int start = 0;
    int end = length - 1;

    while (start < end)
    {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

// Function to convert infix expression to prefix expression
void infixToPrefix(char infix[], char prefix[])
{
    reverseString(infix);

    struct Stack stack;
    stack.top = -1;

    int i = 0, j = 0;

    while (infix[i] != '\0')
    {
        if (isdigitorchar(infix[i]))
        {
            while (isdigitorchar(infix[i]))
            {
                prefix[j++] = infix[i++];
            }
            prefix[j++] = ' ';
        }
        else if (infix[i] == ')')
        {
            push(&stack, infix[i++]);
        }
        else if (infix[i] == '(')
        {
            while (stack.top != -1 && stack.items[stack.top] != ')')
            {
                prefix[j++] = pop(&stack);
            }
            pop(&stack); // Pop the ')'
            i++;
        }
        else if (isOperator(infix[i]))
        {
            while (stack.top != -1 && getPrecedence(stack.items[stack.top]) > getPrecedence(infix[i]))
            {
                prefix[j++] = pop(&stack);
            }
            push(&stack, infix[i++]);
        }
        else
        {
            i++;
        }
    }

    while (stack.top != -1)
    {
        prefix[j++] = pop(&stack);
    }

    prefix[j] = '\0';

    // Reverse the result to get the final prefix expression
    reverseString(prefix);
}

int main()
{
    char infixExpression[100];
    char prefixExpression[100];

    printf("Enter an infix expression: ");
    fgets(infixExpression, sizeof(infixExpression), stdin);

    infixToPrefix(infixExpression, prefixExpression);

    printf("Prefix expression: %s\n", prefixExpression);

    return 0;
}