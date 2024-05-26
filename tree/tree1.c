#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
    int info;
    int father;
    int son;
    int next;
};

struct treenode
{
    int info;
    struct treenode *father;
    struct treenode *son;
    struct treenode *next;
};

typedef struct treenode *nodeptr;
