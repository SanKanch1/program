#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure definition
struct Book
{
    int Book_ID;
    char Title[100];
    char Author[100];
    float Price;
    int Availability_Status; // 1 = Available, 0 = Issued
};

struct Book *create(int n);
void display(struct Book *books, int n);
void search(struct Book *books, int n);
void issueBook(struct Book *books, int n);
void returnBook(struct Book *books, int n);

int main()
{
    struct Book *books = NULL;
    int n = 0;
    int choice;

    do
    {
        printf("\n===== LIBRARY MANAGEMENT SYSTEM =====\n");
        printf("1. Add Book Records\n");
        printf("2. Display All Book Records\n");
        printf("3. Search Book by ID\n");
        printf("4. Issue Book\n");
        printf("5. Return Book\n");
        printf("6. Exit\n");
        printf("=====================================");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter number of books: ");
            scanf("%d", &n);

            if (books != NULL)
                free(books);

            books = create(n);
            break;

        case 2:
            if (books == NULL)
                printf("\n No book records available.\n");
            else
                display(books, n);
            break;

        case 3:
            if (books == NULL)
                printf("\n No book records available.\n");
            else
                search(books, n);
            break;

        case 4:
            if (books == NULL)
                printf("\n No book records available.\n");
            else
                issueBook(books, n);
            break;

        case 5:
            if (books == NULL)
                printf("\n No book records available.\n");
            else
                returnBook(books, n);
            break;

        case 6:
            printf("\n Exiting the program...\n");
            break;

        default:
            printf("\n Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    free(books); // Release dynamically allocated memory
    return 0;
}

struct Book *create(int n)
{
    struct Book *books;
    int i;

    books = (struct Book *)malloc(n * sizeof(struct Book));

    if (books == NULL)
        {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    for (i = 0; i < n; i++)
    {
        printf("\n Enter details of Book %d\n", i + 1);
        printf("Book ID: ");
        scanf("%d", &books[i].Book_ID);

        printf("Title: ");
        scanf(" %[^\n]", books[i].Title);

        printf("Author: ");
        scanf(" %[^\n]", books[i].Author);

        printf("Price: ");
        scanf("%f", &books[i].Price);

        printf("Availability Status (1=Available, 0=Issued): ");
        scanf("%d", &books[i].Availability_Status);
    }
    printf("\n Book records added successfully! \n");
    return books;
}

void display(struct Book *books, int n)
{
    int i, found = 0;
    printf("\n ===== AVAILABLE BOOKS ===== \n");

    for (i = 0; i < n; i++)
    {
        if (books[i].Availability_Status == 1)
        {
            printf("\n Book ID     : %d", books[i].Book_ID);
            printf("\n Title       : %s", books[i].Title);
            printf("\n Author      : %s", books[i].Author);
            printf("\n Price       : %.2f", books[i].Price);
            printf("\n Status      : Available\n");
            found = 1;
        }
    }

    if (found == 0)
    {
        printf("\n No books are currently available.\n");
    }
}

void search(struct Book *books, int n)
{
    int id, i, found = 0;

    printf("\n Enter Book ID to search: ");
    scanf("%d", &id);

    for (i = 0; i < n; i++)
    {
        if (books[i].Book_ID == id)
        {
            printf("\n ===== BOOK DETAILS =====\n");
            printf("Book ID : %d\n", books[i].Book_ID);
            printf("Title   : %s\n", books[i].Title);
            printf("Author  : %s\n", books[i].Author);
            printf("Price   : %.2f\n", books[i].Price);
            if (books[i].Availability_Status == 1)
                printf("Status  : Available\n");
            else
                printf("Status  : Issued\n");
            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("\nBook with ID %d not found.\n", id);
    }
}

void issueBook(struct Book *books, int n)
{
    int id, i, found = 0;

    printf("\nEnter Book ID to issue: ");
    scanf("%d", &id);

    for (i = 0; i < n; i++)
    {
        if (books[i].Book_ID == id)
        {
            found = 1;
            if (books[i].Availability_Status == 1)
            {
                books[i].Availability_Status = 0;
                printf("\nBook '%s' has been issued successfully.\n", 
                        books[i].Title);
            }
            else
            {
                printf("\nBook '%s' is already issued.\n", books[i].Title);
            }
            break;
        }
    }

    if (found == 0)
    {
        printf("\nBook with ID %d not found.\n", id);
    }
}

// Function to return a book
void returnBook(struct Book *books, int n)
{
    int id, i, found = 0;

    printf("\nEnter Book ID to return: ");
    scanf("%d", &id);

    for (i = 0; i < n; i++)
    {
        if (books[i].Book_ID == id)
        {
            found = 1;
            if (books[i].Availability_Status == 0)
            {
                books[i].Availability_Status = 1;
                printf("\n Book '%s' has been returned successfully.\n", 
                        books[i].Title);
            }
            else
            {
                printf("\nBook '%s' is already available in the library.\n", 
                        books[i].Title);
            }
            break;
        }
    }

    if (found == 0)
    {
        printf("\n Book with ID %d not found.", id);
    }
}

