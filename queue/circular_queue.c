#include <stdio.h>
#include <conio.h>
#define Max 5
#define TRUE 0
#define FALSE 1
struct queue
{
    int front;
    int rear;
    int items[Max];
};

void front(struct queue *s)
{
}
void rare(struct queue *s)
{
}
void main()
{
    struct queue q;
    q.front = q.rear = Max - 1; // create empty queue initialization
}