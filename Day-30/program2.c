#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100

struct Book {
    int id;
    char title[100];
    char author[100];
    float price;
};

struct Book library[MAX_BOOKS];
int bookCount = 0;

void addBook() {
    if (bookCount >= MAX_BOOKS) {
        printf("\nLibrary is full!\n");
        return;
    }
    
    printf("\nEnter Book ID: ");
    scanf("%d", &library[bookCount].id);
    getchar();
    
    printf("Enter Book Title: ");
    fgets(library[bookCount].title, sizeof(library[bookCount].title), stdin);
    library[bookCount].title[strcspn(library[bookCount].title, "\n")] = 0;
    
    printf("Enter Author Name: ");
    fgets(library[bookCount].author, sizeof(library[bookCount].author), stdin);
    library[bookCount].author[strcspn(library[bookCount].author, "\n")] = 0;
    
    printf("Enter Price: ");
    scanf("%f", &library[bookCount].price);
    
    bookCount++;
    printf("\nBook added successfully!\n");
}

void displayBooks() {
    if (bookCount == 0) {
        printf("\nNo books available in the library.\n");
        return;
    }
    
    printf("\n--- Library Collection ---\n");
    for (int i = 0; i < bookCount; i++) {
        printf("ID: %d\n", library[i].id);
        printf("Title: %s\n", library[i].title);
        printf("Author: %s\n", library[i].author);
        printf("Price: $%.2f\n", library[i].price);
        printf("-----------------------\n");
    }
}

void searchBook() {
    if (bookCount == 0) {
        printf("\nNo books available to search.\n");
        return;
    }
    
    int searchId;
    int found = 0;
    printf("\nEnter Book ID to search: ");
    scanf("%d", &searchId);
    
    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == searchId) {
            printf("\nBook Found:\n");
            printf("ID: %d\n", library[i].id);
            printf("Title: %s\n", library[i].title);
            printf("Author: %s\n", library[i].author);
            printf("Price: $%.2f\n", library[i].price);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("\nBook with ID %d not found.\n", searchId);
    }
}

int main() {
    int choice;
    
    while (1) {
        printf("\n=== Mini Library System ===\n");
        printf("1. Add Book\n");
        printf("2. Display All Books\n");
        printf("3. Search Book by ID\n");
        printf("4. Total Books Count\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                searchBook();
                break;
            case 4:
                printf("\nTotal books in library: %d\n", bookCount);
                break;
            case 5:
                printf("\nExiting system. Goodbye!\n");
                return 0;
            default:
                printf("\nInvalid choice! Please select between 1 and 5.\n");
        }
    }
    return 0;
}
