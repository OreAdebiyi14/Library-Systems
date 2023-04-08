#define _CRT_SECURE_NO_WARNINGS 1
#define bool int
#define false 0
#include <ctype.h>
#define true (!false)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Oreoluwa Adebiyi
//C21360871

//function methods
void read();
void write();
void addBook();
void borrowBook();
void returnBook();
void deleteBooks();
void viewAllBooks();
void specificBook();
void viewPopularAndLeast();
void settings();
bool isEmpty();
void Option1();
void Option2();
void Option3();

int main()
{
    int option;
    read();
/**
 * A library wishes to keep a record of the books that it has
 * in stock. You need to create a system in C that displays 
 * a menu which allows the following options to be presented
 * to the user
*/

while (option != 9)
{
    printf("\nPlease select a menu option from below: \n");
    printf("------Library Menu-----\n");
    printf("1. Add a new book to the library\n");
    printf("2. Allow a customer to borrow a book\n");
    printf("3. Allow a customer to return a book\n");
    printf("4. Delete an old book from the library stock\n");
    printf("5. View all books\n");
    printf("6. View a specific book\n");
    printf("7. View details of most popular and least popular books\n");
    printf("8. Settings\n");
    printf("9. Exit the system\n");

    printf("\nPlease enter your option: ");
    scanf("%d", &option);

    switch (option) 
    {
            case 1:
                printf("You chose Option 1: Add a book\n");
                addBook();
                break;
            case 2:
                printf("You chose Option 2: Borrow a book\n");
                borrowBook();
                break;
            case 3:
                printf("You chose Option 3: Return a book\n");
                returnBook();
                break;
            case 4:
                printf("You chose Option 4: delete an old book\n");
                deleteBooks();
                break;
            case 5:
                printf("You chose Option 5: View all books\n");
                viewAllBooks();
              
                break;
            case 6:
                printf("You chose Option 6: View a specific book\n");
                specificBook();
                break;
            case 7:
                printf("You chose Option 7: View most and least popular book(s)\n");
                viewPopularAndLeast();
                break;
            case 8:
                printf("You chose Option 8 - Library settings\n");
                settings();
                break;
            case 9:
                printf("---GoodBye--- \n");
                write();
                break;
            default:
                printf("Invalid choice, try again.\n");
                break;
        }
}
return 0;
}

struct Book 
{
    char bookId[10];
    char name[30];
    char author[30];
    char custName[50];
    int year;
    char status[10];
    int borrowed;
    int amountBorrowed;

};

struct LinearNode 
{
    struct Book* element;
	struct LinearNode* next;
};

int bookNum = 0;
#define MAX_SIZE 5

// Global Variables
struct LinearNode* front = NULL; //front of the list
struct LinearNode* last = NULL; //end of the list
struct LinearNode* current = NULL;
struct LinearNode* previous;



bool isEmpty() 
{
	if (front == NULL && last == NULL)
		return true;
	else
		return false;
}

void addBook()
{
    /*
    1. a boolean to check the users input
    2. allocate memory for a new book (malloc)
    3. loop throught the linked list to get the current size of 
    the list and check if the size is below 5 or not
    4. if below the max size user can enter a new book id
    5. check if the id is already in the system
    6. check if the id is unique
    7. ask the user to enter a book name, author and year
    8. the year has to be below 2017
    9. set the books status to available
    10. set the book borrowed and amount to 0
    11. create a new linearNode and add the element of book to it
    12. then update the book Num to show a new book has been added
    
    */

    printf("\n");
    bool check = false;

    //create space for new data element
        struct Book *aBook = (struct Book *)malloc(sizeof(struct Book));
       //memory allocate

	// create space for new node
		 struct LinearNode *aNode = (struct LinearNode *)malloc(sizeof(struct LinearNode));
         struct LinearNode *number = front;
    int sizeN = 0;
while(number != NULL)
{
    sizeN++;
    number = number->next;
}
    if (sizeN == MAX_SIZE)
    {
        printf("Sorry - Library list is full\n");
        return;
    }
    else
    {
         printf("You are now going to create a book \n");
         do
         {
            printf("Please enter the book ID (in the format xxxx-xxxx): ");
            scanf("%s", aBook->bookId);

            //to double check the numbers entered in
            //if the first 4 is number 
            //if theres a dash
            //then if the last 4 are numbers 

        if (strlen(aBook->bookId) != 9)
        {
            printf("Sorry - Please enter the correct ID format (xxxx-xxxx)\n");
        }
        else if (aBook->bookId[4] != '-')
        {
            printf("Sorry - Please enter the correct ID format (xxxx-xxxx)\n");
        }
        else
        {
            for (int i = 0; i < strlen(aBook->bookId); i++) 
            {
                 if (i == 4) continue;
                
                 if (aBook->bookId[i] < '0' || aBook->bookId[i] > '9') 
                 {
                     printf("Sorry - Please enter in the format of (xxxx-xxxx) \n");
                     check = false;
                     break;
                 }  
                 else
                 {
                    check = true;
                 }
            }   
        }
    }while(!check);
}
    //check if book ID exists
    current = front;
    bool exists = false;
    while(current != NULL)
    {
        if (strcmp(current->element->bookId, aBook->bookId) == 0)
        {
             printf("Sorry - this Book id already exist\n");
             exists = true;
             return;
        }
        current = current->next;
    }
    
    if(exists)
    {
        do
        {
           printf("Please enter a new book Id (in the format xxxx-xxxx):");
           scanf("%s", aBook->bookId);

            exists = false;
            current = front;
            while(current != NULL)
            {
                if(strcmp(current->element->bookId, aBook->bookId) == 0)
                {
                    printf("ERROR - book id already exists\n");
                    exists = true;
                    break;
                }
                current = current->next;
            }

        } while (exists);
        
    }
     printf("\nValid ID format. \nYour ID number is %s.\n", aBook->bookId);

    
    printf("Please enter the book Name: ");
    scanf("%s", aBook->name);

    printf("Please enter the book's Author: ");
    scanf("%s", aBook->author);

    //printf("Please enter the customers name:");
    //scanf("%s", aBook->custName);

    do
    {
        printf("Please enter the year of publication - (cannot be older than 2017): ");
        scanf("%d", &aBook->year);
        if (aBook->year > 2017) 
            {
                printf("Sorry - Please enter a year below 2017 \n");
            } 
            else{
                break;
            }
        
    }while(aBook->year > 2017);

    strcpy(aBook->status, "available");

   /*
   printf("%c", newB.custLoan);
    aBook->custLoan = 0;
   */ 

    aBook->borrowed = 0;
    aBook->amountBorrowed = 0;

if(aNode == NULL || aBook == NULL)
{
    printf("ERROR - NO SPACE LEFT");
}
else
{
        aNode->element = aBook;
       if(isEmpty())
       {
            aNode->next = NULL;
            front = aNode; 
            last = aNode;
       }
       else
       {
            aNode->next = front;
            front = aNode;
            
       }
}
        // update bookNum
        bookNum++;
    

}

void borrowBook()
{
    /*
    - Method is to borrow a book from a library syatem
    1. user asked to enter a book Id they are searching for 
    2. check if the book is available
    4. if book is not found message is printed and return to menu
    5. if borrowed by someone message is printed and return to menu
    6. if book is available enter the customer name 
    7. updates book status to borrowed and print message
    */
   
    bool found = false;
    char id[10];
    
    printf("\n");
    printf("Enter Book id you are searching for: ");
    scanf("%s", id);

    current = front;
    while (current != NULL)
    {
        if(strcmp(current->element->bookId, id) == 0)
        {
            found = true;
            break;
        }
        current = current->next;
    }
    if(!found)
    {
        printf("Book is not found \n");
        return;
    }
    if(strcmp(current->element->status, "borrowed") == 0)
    {
        printf("Book is already borrowed by %s \n", current->element->custName);
        return;
    }


    printf("Enter Customer name: ");
    scanf("%s", current->element->custName); 

    strcpy(current->element->status, "borrowed");
    //current->element->borrowed = 1;
    current->element->amountBorrowed++;

    printf("The book %s has been borrowed by %s", current->element->bookId, current->element->custName);

    printf("\n");
}
  
void deleteBooks()
{
/*
1. Find the book that matches the id
2. if found set the next pointer of the previous node to the next pointer of the current book id
3. If the node to be deleted is the first node, update the head pointer to point to the next node.
4. update the status of the book to deleted
4. Free the memory occupied by the node to be deleted.
*/

    bool found = false;
    char id[10];
    printf("\n");
    printf("Please enter the Book ID you want to delete: ");
    scanf("%s", id);

    previous = NULL;
    current = front;
    while (current != NULL)
    {
        if(strcmp(current->element->bookId, id) == 0)
        {
            //to check if the book is published after 2010
            if (current->element->year > 2010)
            {
                printf("Cannot delete book as it was published after 2010\n");
                return;
            }
            found = true;
            break;
        }
       previous = current;
       current = current->next;
       //printf("Book id was found");
    }
    if (!found)
    {
        printf("Sorry book id does not exist\n");
        return;
    }

    strcpy(current->element->status, "Deleted");
    current->element->borrowed = 2;
    current->element->amountBorrowed--;
    if(previous != NULL)
    {
        previous->next = current->next;
    }
    else
    {
        front = current->next;
    }
    free(current);

    printf("Book with ID %s was deleted from the list\n", id);

}

void returnBook()
{
    /*
    - to return a borrowed book to a library sytem
    1. ask the user for the book id and checks if it exists
    2. if the book is not found message is printed and exists
    3. if its found asks user to input customer name of the borrower
    4. if the name doesnt match, print error message and exits
    5. if it matches, it updates the status to returned
    6. set the borrower name to "" 
    7. print a message confirming the book has been returned
    */
   char bookId[10];
   char custName[30];
   bool found = false;

    printf("\n");
    printf("Enter the book id:");
    scanf("%s", bookId);

    current = front;
    while (current != NULL) {
        if (strcmp(current->element->bookId, bookId) == 0) {
            found = true;
            break;
        }
        current = current->next;
    }

    if (!found) {
        printf("Book with ID %s is not found\n", bookId);
        return;
    }

    printf("Enter the customers name: ");
    scanf("%s", custName);
    
    if (strcmp(current->element->custName, custName) != 0) 
    {
        printf("Book is not borrowed by %s \n", custName);
        return;
    }

    strcpy(current->element->status, "Returned");
   // current->element->status = 1;
    strcpy(current->element->custName, "");

    printf("Book with ID %s has been returned by %s\n", bookId, custName);
    printf("\n");

}

void viewAllBooks()
{
    /*
    - to display all the books in the library system
    1. if the list is empty, print a message 
    2. if the list has books, print all the books details
    3. print all till the end of the list
    */
   if (isEmpty()) {
        printf("\nSorry - there are no books in the list\n");
    }
    else {
        printf("\nPrinting list of all books.......\n");
        int count = 0;
        current = front;
        while (current != NULL && count < MAX_SIZE)
        {
            printf("Name: %s\n", current->element->name);
            printf("Author: %s\n", current->element->author);
            printf("ID: %s\n", current->element->bookId);
            printf("Year: %d\n", current->element->year);
            printf("Customer Name: %s\n", current->element->custName);
            printf("Status: %s\n", current->element->status);
            printf("Amount of times borrowed: %d\n", current->element->amountBorrowed);
            printf("\n");
            current = current->next;
            count++;
        }
    }
}

void specificBook()
{
    /*
    - view the specific book the user wants
    1. ask for the book id and display the details of the book
    if it exists in the library system
    2. if not found will display an error message
    3. searches through the linked list for the book with ID
    */
    char bookId[10];

    printf("\nEnter a book Id: ");
    scanf("%s", bookId);

    current = front;
    int found = 0;
    while (current != NULL)
    {
        if (strcmp(current->element->bookId, bookId) == 0) 
        {
            printf("\n");
            printf("Name: %s\n", current->element->name);
            printf("Author: %s\n", current->element->author);
            printf("ID: %s\n", current->element->bookId);
            printf("Year: %d\n", current->element->year);
            printf("Customer Name: %s\n", current->element->custName);
            printf("Status: %s\n", current->element->status);
            printf("Amount of times borrowed: %d\n", current->element->amountBorrowed);
            
            found = 1;
        }
        current = current->next;
    }

     if(!found)
    {
        printf("ERROR - Book is not found");
    }

    printf("\n");

       /*
       printf("Please enter the customer name: ");
        scanf("%s", custName);
        
        if(strcmp(current->element->custName, custName) == 0)
        {
            printf("You have borrowed this book before");
        }
        else
        {
            printf("This is the first time being borrowed by you %s ", custName);
        }
       */
}

void viewPopularAndLeast()
{
    /*
    1. start by checking if the library is empty.
    2. If it is, the function prints an error message and returns. 
    3. If the library is not empty, the function initializes pointers for the most and least popular books, 
    and should set current to the front of the linked list.
    4. compares its number of times borrowed with the number of times 
    borrowed for the current most and least popular books.
    5. current book has been borrowed more times than the current most popular book, 
    the most popular book pointer is updated to point to the current book
    6.  if the current book has been borrowed fewer times than 
    the current least popular book, the least popular book pointer 
    is updated to point to the current book.
    7. prints the names and number of times 
    borrowed for the most and least popular books.
    */
    if(isEmpty())
    {
        printf("ERROR - library is empty\n");
        return;
    }

    struct LinearNode* most = front->next;
    struct LinearNode* least = front->next;
    current = front;

    while (current != NULL)
    {
        if(most == NULL || current->element->amountBorrowed > most->element->amountBorrowed)
        {
            most = current;
        }
        if(least == NULL || current->element->amountBorrowed < least->element->amountBorrowed)
        {
            least = current;
        }
        current = current->next;
    }

    if (most == least)
    {
        printf("\nAll books have been borrowed the same amount if times\n");
    
    }
    else
    {
        printf("\nMost popular book(s) is: \n");
        current = front;
        while (current != NULL)
        {
            if(current->element->amountBorrowed == most->element->amountBorrowed)
            {
                 printf("%s has been borrowed %d times \n", current->element->name, current->element->amountBorrowed);
            }
            current = current->next;
        }

        printf("\nLeast popular book(s) is: \n");
        current = front;
        while (current != NULL)
        {
            if(current->element->amountBorrowed == least->element->amountBorrowed)
            {
                 printf("%s has been borrowed %d times \n", current->element->name, current->element->amountBorrowed);
            }
            current = current->next;
        }

    }
    
} 

void settings()
{
 /*
 allows the userto choose from 4 dif./ menu options
 1. edit a book - user can edit an existing book in the system
 2. sort books - user can sort the books by name, author, year, ...
 3. delete All - user can delete all the books in the system
 4. exit - allows user to return back to the main menu
 */
    int option;

    printf("Welcome to the settings, please choose a setting(1-4):\n");
    printf("1. Edit a book\n");
    printf("2. Sort the books\n");
    printf("3. Delete ALL books\n");
    printf("4. Exit\n");
    printf("Option: ");
    scanf("%d", &option);

    switch (option) 
    {
            case 1:
                printf("You selected to edit a book.\n");
                Option1();
                break;
            case 2:
                printf("You selected to sort the books.\n");
                Option2();
                break;
            case 3:
                printf("Delete ALL books in the system.\n");
                Option3();
                break;
            case 4:
                printf("Exiting the settings menu.....\n");
                return;
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
    }

}

void Option1()
{
    /*
    user can edit the information of a book in the library system
    1. user is asked to enter a book id they want to edit
    2. search for the book and display its current details
    3. user can choose whic info they want to edit like title, year, author,....
    4. after changed the updated details are displayed
    5. if the user doesnt want to edit a book they can cancel the edit 
    and return to the main menu 
    */
    char bookId[10];
    bool found = false;
    int choice1;
    char confirm;

    printf("\nYou are about to enter the library settings\n");
    printf("\nDo you want to edit a book? (y/n): ");
    scanf(" %s", &confirm);

    if(confirm != 'y')
    {
        printf("Book edit is cancelled\n");
        return;
    }

    printf("\nEnter the book Id to edit: ");
    scanf("%s", bookId);

    current = front;
    while (current != NULL)
    {
        if (strcmp(current->element->bookId, bookId) == 0)
        {
            found = true;
            break;
        }
        current = current->next;
    }

    if (!found)
    {
        printf("\nERROR - Book with ID: (%s) is not found\n", bookId);
        return;
    }

    printf("\nCurrent Book Details:");
    printf("\nName: %s", current->element->name);
    printf("\nAuthor: %s", current->element->author);
    printf("\nID: %s", current->element->bookId);
    printf("\nYear: %d", current->element->year);
    printf("\nCustomer Name: %s", current->element->custName);
    printf("\nStatus: %s", current->element->status);
    printf("\nAmount of times borrowed: %d\n", current->element->amountBorrowed);

    printf("\nWhat information do you want to edit? (1-7): \n");
    printf("1. Name\n");
    printf("2. Author\n");
    printf("3. Year\n");
    printf("4. Customer Name\n");
    printf("5. Status\n");
    printf("6. Amount of times borrowed\n");
    printf("7. All\n");
    printf("Choice: ");
    scanf("%d", &choice1);

    printf("You chose: %d\n", choice1);
    switch (choice1)
    {
        case 1: 
        printf("Enter a new book title: ");
        scanf("%s", current->element->name);
        break;
        case 2:
            printf("Enter a new author: ");
            scanf("%s", current->element->author);
            break;
        case 3:
            printf("Enter a new year: ");
            scanf("%d", &current->element->year);
            break;
        case 4:
            printf("Enter a new customer name: ");
            scanf("%s", current->element->custName);
            break;
        case 5:
            printf("Enter a new status: ");
            scanf("%s", current->element->status);
            break;
        case 6:
            printf("Enter a new amount of times borrowed: ");
            scanf("%d", &current->element->amountBorrowed);
            break;
        case 7:
            printf("Enter a new name: ");
            scanf("%s", current->element->name);

            printf("Enter a new author: ");
            scanf("%s", current->element->author);

            printf("Enter a new year: ");
            scanf("%d", &current->element->year);

            printf("Enter a new customer name: ");
            scanf("%s", current->element->custName);

            printf("Enter a new status: ");
            scanf("%s", current->element->status);

            printf("Enter a new amount of times borrowed: ");
            scanf("%d", &current->element->amountBorrowed);
            break;
        default: 
            printf("ERROR - Wrong choice. \n");
            return;
    
    }
    printf("\nBook with ID (%s) has been updated:", bookId);

    printf("\nName: %s", current->element->name);
    printf("\nAuthor: %s", current->element->author);
    printf("\nID: %s", current->element->bookId);
    printf("\nYear: %d", current->element->year);
    printf("\nCustomer Name: %s", current->element->custName);
    printf("\nStatus: %s", current->element->status);
    printf("\nAmount of times borrowed: %d\n", current->element->amountBorrowed);

}

void Option2()
{
    /*
    allows user to sort the list of books stored 
    1. use a sorting alg to rearrange the books in the list
    2. user can choose what they want to sort the books by
    3. after sorting list of books are displayed in the new sorting order
    4. if 7 is entered the return to the main menu
    */
    bool found = false;
    int choice2;
    char confirm;

    printf("\nSort books by what criteria? (1-6):\n");
    printf("1. Name\n");
    printf("2. Author\n");
    printf("3. Year of publication\n");
    printf("4. Customer Name\n");
    printf("5. Status\n");
    printf("6. Amount of times borrowed\n");
    printf("7. Return to main menu\n");
    printf("Option: ");
    scanf("%d", &choice2);

    switch(choice2)
    {
        case 1: 
        for(struct LinearNode* i = front; i != NULL; i = i->next)
        {
             for(struct LinearNode* j = i->next; j != NULL; j = j->next)
             {
                printf("Sorting element: %s\n", i->element->name);
                if(strcmp(i->element->name, j->element->name) > 0)
                {
                    struct Book* tempElement = i->element;
                    i->element = j->element;
                    j->element = tempElement;
                }
             }
        }
        break;
        case 2:
        for (struct LinearNode* i = front; i != NULL; i = i->next) 
        {
                for (struct LinearNode* j = i->next; j != NULL; j = j->next) 
                {
                    if (strcmp(i->element->author, j->element->author) > 0) 
                    {
                        struct Book* tempElement = i->element;
                        i->element = j->element;
                        j->element = tempElement;
                    }
            }
        }
        break;
        case 3:
        for (struct LinearNode* i = front; i != NULL; i = i->next) 
        {
                for (struct LinearNode* j = i->next; j != NULL; j = j->next) 
                {
                    if ((i->element->year > j->element->year))
                    {
                        struct Book* tempElement = i->element;
                        i->element = j->element;
                        j->element = tempElement;
                    }
            }
        }
        break;
        case 4:
        for (struct LinearNode* i = front; i != NULL; i = i->next) 
        {
                for (struct LinearNode* j = i->next; j != NULL; j = j->next) 
                {
                    if (strcmp(i->element->custName, j->element->custName) > 0) 
                    {
                        struct Book* tempElement = i->element;
                        i->element = j->element;
                        j->element = tempElement;
                    }
            }
        }
        break;
        case 5:
        for (struct LinearNode* i = front; i != NULL; i = i->next) 
        {
                for (struct LinearNode* j = i->next; j != NULL; j = j->next) 
                {
                    if (strcmp(i->element->status, j->element->status) > 0) 
                    {
                        struct Book* tempElement = i->element;
                        i->element = j->element;
                        j->element = tempElement;
                    }
            }
        }
        break;
        case 6:
        for (struct LinearNode* i = front; i != NULL; i = i->next) 
        {
                for (struct LinearNode* j = i->next; j != NULL; j = j->next) 
                {
                    if ((i->element->amountBorrowed > j->element->amountBorrowed)) 
                    {
                        struct Book* tempElement = i->element;
                        i->element = j->element;
                        j->element = tempElement;
                    }
            }
        }
        break;
        case 7:
        printf("Exiting the sorting menu.....\n");
        return;
        break;
        default:
        printf("Invalid option. Please try again.\n");
        break;
    }

    printf("\nSorted Book List:\n");
    for (current = front; current != NULL; current = current->next) 
    {
        printf("\nName: %s\n", current->element->name);
        printf("Author: %s\n", current->element->author);
        printf("Year of publication: %d\n", current->element->year);
        printf("Customer Name: %s\n", current->element->custName);
        printf("Status: %s\n", current->element->status);
        printf("Amount of times borrowed: %d\n", current->element->amountBorrowed);
    }

}

void Option3()
{
    /*
    to delete all the books in the system
    1. asks the user are they sure they want to delete to confirm
    2. if yes, checks if the list is empty
    3. then loops through the list and deletes each from the list 
    and freeing the space
    4. set the front and last pointers to NULL
    5. if the user says no, then message is printed 
    and returned to the main menu

    */
    char answer;
    printf("This is to delete ALL the books in the library system!!\n");
    printf("Are you sure you want to delete all books (Y/N):");
    scanf("%s", &answer);

    if(answer == 'Y' || answer == 'y')
    {
        if (front == NULL) {
            printf("The list is already empty.\n");
            return;
        }
        current = front;
        while(current != NULL)
        {
            struct LinearNode* next = current->next;
            current->next = NULL;
            free(current->element);
            free(current);
            current = next;
        }
        front = NULL;
        last = NULL;

         printf("Books are ALL deleted");
    }
    else
    {
        printf("To delete all books cancelled....\n");
        return;
    }
}

void read()
{
    FILE *file = fopen("book.dat", "rb");
    if(file == NULL)
    {
        printf("There was no database of any books found\n");
        return;
    }
    
    struct Book *aBook = (struct Book *)malloc(sizeof(struct Book));
    if(aBook == NULL)
    {
        printf("Memory allocation failed\n");
        fclose(file);
        return;
    }

   struct LinearNode *newNode;
    while(fread(aBook, sizeof(struct Book), 1, file) == 1)
    {
        newNode = (struct LinearNode *)malloc(sizeof(struct LinearNode));
        if(newNode == NULL)
        {
            printf("Memory allocation failed\n");
            fclose(file);
            free(aBook);
            return;
        }
    newNode->element = aBook;
        newNode->next = NULL;

        if (front == NULL)
        {
            front = newNode;
            previous = newNode;
        }
        else
        {
            previous->next = newNode;
            previous = newNode;
        }

        // allocate new memory for next book
        aBook = (struct Book *)malloc(sizeof(struct Book));
        if(aBook == NULL)
        {
            printf("Memory allocation failed\n");
            fclose(file);
            return;
        }
    }

    printf("The system has now been updated with books from the data file.\n");
    fclose(file);
}

void write()
{
   FILE *file = fopen("book.dat", "wb");

    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    current = front;

    while (current != NULL)
    {
       if(current->element != NULL)
        {
            fwrite (current->element, sizeof(struct Book), 1, file);
        }
        else
        {
            printf("ERROR: element is null");
        }
        current  = current->next;
    
    }

    printf("Books have been saved successfully to the data file. \n");

    fclose(file);
}