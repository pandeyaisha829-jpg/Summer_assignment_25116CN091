#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

struct Student {
    int id;
    char name[50];
    float gpa;
};

void addStudent(struct Student system[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("\nSystem database is full.\n");
        return;
    }
    
    printf("\nEnter Student ID: ");
    scanf("%d", &system[*count].id);
    getchar();
    
    printf("Enter Student Name: ");
    fgets(system[*count].name, sizeof(system[*count].name), stdin);
    system[*count].name[strcspn(system[*count].name, "\n")] = '\0';
    
    printf("Enter GPA: ");
    scanf("%f", &system[*count].gpa);
    
    (*count)++;
    printf("Record added successfully!\n");
}

void displayStudents(struct Student system[], int count) {
    if (count == 0) {
        printf("\nNo records found.\n");
        return;
    }
    
    printf("\n--- Student Records ---\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d | Name: %s | GPA: %.2f\n", system[i].id, system[i].name, system[i].gpa);
    }
}

void searchStudent(struct Student system[], int count) {
    if (count == 0) {
        printf("\nNo records available to search.\n");
        return;
    }
    
    int searchId;
    int found = 0;
    
    printf("\nEnter Student ID to search: ");
    scanf("%d", &searchId);
    
    for (int i = 0; i < count; i++) {
        if (system[i].id == searchId) {
            printf("\nRecord Found:\n");
            printf("ID: %d\nName: %s\nGPA: %.2f\n", system[i].id, system[i].name, system[i].gpa);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("\nStudent with ID %d not found.\n", searchId);
    }
}

int main() {
    struct Student system[MAX_STUDENTS];
    int count = 0;
    int choice;
    
    do {
        printf("\n=== Student Record System ===\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student by ID\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addStudent(system, &count);
                break;
            case 2:
                displayStudents(system, count);
                break;
            case 3:
                searchStudent(system, count);
                break;
            case 4:
                printf("\nExiting system.\n");
                break;
            default:
                printf("\nInvalid selection. Try again.\n");
        }
    } while (choice != 4);
    
    return 0;
}
