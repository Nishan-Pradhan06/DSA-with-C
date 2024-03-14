#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

// Define contants
#define MAX_STUDENT 4
#define MAX_LENGTH 50
#define PASSWORD_LENGTH 10
#define MAX_BOOK 5
#define TRUE 1
#define FALSE 0

// structure of student
typedef struct
{
    char name[MAX_LENGTH]; // username of student
    int library_id_no;
    char password[PASSWORD_LENGTH];
    //
} Student;

// structure of book
typedef struct
{
    char book_name[MAX_LENGTH]; // book's name
    int book_id;
    char book_list[MAX_BOOK][MAX_LENGTH]; // list of books in the library
} Book;

// add a boks array to store books in library
typedef struct
{
    Student students[MAX_STUDENT];
    Book books[MAX_BOOK];
} Library;

// function
int studentPortal(Library *lib, Student *std);
void createPassword(Student *std);
void isBookFull(Library *lib);
void addBook(Library *lib, int n);
void searchBook(Library *book);

// void studentPortal(Students students[]);
int studentPortal(Library *lib, Student *std)
{
    int choice;
    char password[PASSWORD_LENGTH];
    do
    {
        printf("\n.........Student Portal..........");
        printf("\n1. Add Books");
        printf("\n2. Owned Books Lists");
        printf("\n3. Return Books");
        printf("\n4. Change Password");
        printf("\n5. Logout\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("%s", lib->books[0].book_name);
            break;
        case 2:
            printf("Owned Books Lists are: ");
            break;
        case 3:
            printf("Return Books Lists");
            break;
        case 4:
        {
            printf("Please Enter your current Password %s", password);
            if (strcmp(password, "student") == 0)
            {
                createPassword(std);
            }
            else
            {
                printf("Invalid Password!!!\n");
            }
        }
        case 5:
            exit(0);
        default:
            printf("Wrong Choice!!! Please enter correct options \n");
        }
    } while (choice != 5);
    return TRUE;
}
void createPassword(Student *std)
{
    printf("Enter Your New Password: ");
    scanf("%s", std->password); // Store the new password in the student structure
}
void isBookFull(Library *lib)
{
    if (lib->books[0].book_list = MAX_BOOK - 1)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}
void addBook(Library *lib, Student *std, int n)
{
    if (isBookFull(lib))
    {
        /* code */
    }
}
void searchBook(Library *book)
{
    if (strcmp(book->books[0].book_name, "") == 0) // check if book array is empty
    {
        printf("There are no books in the library..\n");
    }
    else
    {
        printf("Available Books in Library are: %s\n", book->books[0].book_name); // dispay the alll book store in library
    }
}
void adminPortal()
{
}
int main()
{
    char librarian[PASSWORD_LENGTH];
    char stdpass[PASSWORD_LENGTH];
    int choice;
    printf("...........Welcome To INC Library...........");
    printf("1. Librarian\n2. Student");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
    {

        printf("Enter the Admin password: ");
        scanf("%s", librarian);
        if (strcmp(librarian, "librarian") == 0)
        {
            admin();
        }
        else
        {
            printf("Password Incorrect..!!");
        }
        break;
    }

    case 2:
    {
        printf("Enter the Admin password: ");
        scanf("%s", stdpass);
        if (strcmp(stdpass, "std") == 0)
        {
            // studentPortal(&Library,&Student);
        }
        else
        {
            printf("Password Incorrect..!!");
        }
        break;
    }

    default:
        printf("Invlaid choice");
        break;
    }
    return 0;
}