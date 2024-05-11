#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string>

struct item
{
    int x;
    int y;
    char caption[50];
};

struct menu
{
    struct item menuitem;
    struct menu *next;
    struct menu *prev;
};

struct menu *header,*seleceted;
struct menu  *getnode(struct item itm)
{
    
}

