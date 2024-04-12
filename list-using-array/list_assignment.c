#include <stdio.h>
#include <conio.h>
#include <string.h>

#define MAX_STUDENT 100
#define MAX_NAME_LENGTH 50
#define TRUE 1
#define FALSE 0

// structure for student
typedef struct student
{
    char name[MAX_NAME_LENGTH];
    int id;
    char faculty[MAX_NAME_LENGTH];
} Student;

// structure for list of students
typedef struct list
{
    Student students[MAX_STUDENT];
    int count;
} List;

//...............function for empty or full.................................
int isFull(List *lst);  // check weather list is full
int isEmpty(List *lst); // chech if list is empty

//.........................insert functions.................................
int insertFront(List *lst, Student std); // insert from top
int insertEnd(List *lst, Student std);   // insert from end

//...................... remove functions...................................
int removeFront(List *lst);                   // remove form top
int removeLast(List *lst);                    // remove from last
int removeAny(List *lst, int id, char *name); // remove any

//......................search functions...................................
int searchList(List *lst, int id); // search list from id

//............................display list..................................
void displayList(List *lst);

//..........................check list is full or not.......................
int isFull(List *lst)
{
    return lst->count == MAX_STUDENT;
}

//....................... check list if empty  or not............................
int isEmpty(List *lst)
{
    return lst->count == 0;
}

// ...........................insert list from front.............................
int insertFront(List *lst, Student std)
{
    if (isFull(lst))
    {
        printf("Student List is Full...");
        return FALSE;
    }
    printf("\nEnter Student ID: ");
    scanf("%d", &std.id);
    printf("\nEnter Student Name: ");
    scanf("%s", std.name);
    printf("\nEnter Student Faculty: ");
    scanf("%s", std.faculty);
    int i;
    for (i = lst->count; i > 0; i--)
    {
        lst->students[i] = lst->students[i - 1];
    }
    lst->students[0] = std;
    lst->count++;
    return TRUE;
}

//................................. insert list from End............................
int insertEnd(List *lst, Student std)
{
    if (isFull(lst))
    {
        printf("Student List is Full...");
        return FALSE;
    }
    printf("\nEnter Student ID: ");
    scanf("%d", &std.id);
    printf("\nEnter Student Name: ");
    scanf("%s", std.name);
    printf("\nEnter Student Faculty: ");
    scanf("%s", std.faculty);
    lst->students[lst->count] = std;
    lst->count++;
    return TRUE;
}

// ....................................remove front list.........................
int removeFront(List *lst)
{
    int i;
    if (isEmpty(lst))
    {
        printf("\n....Student List is Empty....");
        return FALSE;
    }
    for (i = 0; i < lst->count - 1; i++)
    {

        lst->students[i] = lst->students[i + 1];
    }
    lst->count--;
    printf("\nStudent Removed:\n\nID\t\t Name\n%d\t\t%s", lst->students[lst->count].id, lst->students[lst->count].name);
    return TRUE;
}

//...........................remove from end.......................................
int removeEnd(List *lst)
{
    if (isEmpty(lst))
    {
        printf("\n....Student List is Empty....");
        return FALSE;
    }
    lst->count--;
    printf("\nStudent Removed:\n\nID\t\t Name\n%d\t\t%s", lst->students[lst->count].id, lst->students[lst->count].name);
    return TRUE;
}

//..........................remove any list with id ...............................
int removeAny(List *lst, int id, char *name)
{
    int i;
    if (isEmpty(lst))
    {
        printf("\n....Student List is Empty....");
        return FALSE;
    }
    for (i = 0; i < lst->count; i++)
    {
        if (lst->students[i].id == id)
        {
            lst->students[i] = lst->students[i + 1];
        }
        lst->count--;
        printf("\nStudent Removed:\n\nID\t\t Name\n%d\t\t%s", id, name);
        return TRUE;
    }
}

//................display all the list of  students.................................
void displayList(List *lst)
{
    if (isEmpty(lst))
    {
        printf("\n....Student List is Empty....\n");
        return;
    }
    printf("\n.................Students List..................\n");
    printf("\n................................................");
    printf("\nID\t\t Name\t\tFaculty\n");
    for (int i = 0; i < lst->count; i++)
    {
        printf("%d\t\t%s\t\t%s\n", lst->students[i].id, lst->students[i].name, lst->students[i].faculty); // display name  and ID of each student in the list.
    }
    printf(".....................................................");
}

//.......................search list................................
int searchList(List *lst, int id)
{
    if (isEmpty(lst))
    {
        printf(".....Student list is empty......");
    }
    for (int i = 0; i < lst->count; i++)
    {
        if (lst->students[i].id == id)
        {
            printf("\nStudent Found:\n\nID\t\t Name\n%d\t\t%s", lst->students[i].id, lst->students[i].name); // display search items
            return TRUE;
        }
    }
    printf("\nStudent with ID %d not found.\n", id);
    return FALSE;
}

// Main functions
int main()
{
    int id;
    char name[MAX_NAME_LENGTH];
    int choice;
    List studentList;
    Student newStudent;
    studentList.count = 0;

    while (1)
    {
        printf("\n\nStudent List  Program\n");
        printf("1: Insert Front\n2: Insert End\n3: Remove Front\n4: Remove Last\n5: Remove Any\n6: Display List\n7: Search Lists\n8: Exit Program");
        printf("\nEnter Your Choice:  ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insertFront(&studentList, newStudent); // insesrt from front
            printf("\n.....Student List Insert Front Successfully......\n\n");
            break;
        case 2:
            insertEnd(&studentList, newStudent); // insert from end
            printf("\n.....Student List Insert End Successfully......\n\n");
            break;
        case 3:
            removeFront(&studentList); // remove list from front
            break;
        case 4:
            removeEnd(&studentList); // remove list from last
            break;
        case 5:
            printf("Enter Student ID to Removed: ");
            scanf("%d", &id);
            removeAny(&studentList, id, name);
            break;
        case 6:
            displayList(&studentList); // dispaly all the list
            break;
        case 7:
            printf("Enter Student ID to Search: ");
            scanf("%d", &id);
            searchList(&studentList, id); // search list
            break;
        case 8:
            printf("\nExiting the program...\n");
            return 0;
        default:
            printf("\n!!!!!!!!!!!!!!!--Invalid Input! Please Enter Again.--!!!!!!!!!!!!!!!!!!!!!\n\n");
            break;
        }
    }
    return 0;
}
