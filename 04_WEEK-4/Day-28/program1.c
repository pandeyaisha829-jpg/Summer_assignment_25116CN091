#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    int id;
    char title[50];
    char author[50];
    int is_issued;
};

void addBook(struct Book library[], int *count);
void displayBooks(const struct Book library[], int count);
void searchBook(const struct Book library[], int count);
void issueBook(struct Book library[], int count);
void returnBook(struct Book library[], int count);

int main() {
    struct Book library[100];
    int count = 0;
    int choice;

    do {
        printf("\n=== Library Management System ===\n");
        printf("1. Add Book\n");
        printf("2. Display All Books\n");
        printf("3. Search Book by ID\n");
        printf("4. Issue Book\n");
        printf("5. Return Book\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }

        switch (choice) {
            case 1:
                addBook(library, &count);
                break;
            case 2:
                displayBooks(library, count);
                break;
            case 3:
                searchBook(library, count);
                break;
            case 4:
                issueBook(library, count);
                break;
            case 5:
                returnBook(library, count);
                break;
            case 6:
                printf("Exiting system.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 6);

    return 0;
}

void addBook(struct Book library[], int *count) {
    if (*count >= 100) {
        printf("Library is full!\n");
        return;
    }

    struct Book b;
    printf("Enter Book ID: ");
    scanf("%d", &b.id);
    
    for (int i = 0; i < *count; i++) {
        if (library[i].id == b.id) {
            printf("Error: A book with this ID already exists.\n");
            return;
        }
    }

    getchar(); 
    printf("Enter Book Title: ");
    fgets(b.title, sizeof(b.title), stdin);
    b.title[strcspn(b.title, "\n")] = '\0';

    printf("Enter Author Name: ");
    fgets(b.author, sizeof(b.author), stdin);
    b.author[strcspn(b.author, "\n")] = '\0';

    b.is_issued = 0;
    library[*count] = b;
    (*count)++;
    
    printf("Book added successfully!\n");
}

void displayBooks(const struct Book library[], int count) {
    if (count == 0) {
        printf("No books available in the library.\n");
        return;
    }

    printf("\n%-10s %-30s %-25s %-15s\n", "Book ID", "Title", "Author", "Status");
    printf("--------------------------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-10d %-30s %-25s %-15s\n", 
               library[i].id, 
               library[i].title, 
               library[i].author, 
               library[i].is_issued ? "Issued" : "Available");
    }
}

void searchBook(const struct Book library[], int count) {
    if (count == 0) {
        printf("No books available to search.\n");
        return;
    }

    int searchId;
    printf("Enter Book ID to search: ");
    scanf("%d", &searchId);

    for (int i = 0; i < count; i++) {
        if (library[i].id == searchId) {
            printf("\nBook Found:\n");
            printf("ID: %d\nTitle: %s\nAuthor: %s\nStatus: %s\n", 
                   library[i].id, library[i].title, library[i].author, 
                   library[i].is_issued ? "Issued" : "Available");
            return;
        }
    }
    printf("Book with ID %d not found.\n", searchId);
}

void issueBook(struct Book library[], int count) {
    int issueId;
    printf("Enter Book ID to issue: ");
    scanf("%d", &issueId);

    for (int i = 0; i < count; i++) {
        if (library[i].id == issueId) {
            if (library[i].is_issued) {
                printf("Book is already issued.\n");
            } else {
                library[i].is_issued = 1;
                printf("Book issued successfully!\n");
            }
            return;
        }
    }
    printf("Book with ID %d not found.\n", issueId);
}

void returnBook(struct Book library[], int count) {
    int returnId;
    printf("Enter Book ID to return: ");
    scanf("%d", &returnId);

    for (int i = 0; i < count; i++) {
        if (library[i].id == returnId) {
            if (!library[i].is_issued) {
                printf("Book was not issued.\n");
            } else {
                library[i].is_issued = 0;
                printf("Book returned successfully!\n");
            }
            return;
        }
    }
    printf("Book with ID %d not found.\n", returnId);
}
