#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LENGTH 50

void addStudent(char names[MAX_STUDENTS][NAME_LENGTH], int rolls[MAX_STUDENTS], float marks[MAX_STUDENTS], int *count);
void displayStudents(char names[MAX_STUDENTS][NAME_LENGTH], int rolls[MAX_STUDENTS], float marks[MAX_STUDENTS], int count);
void searchStudent(char names[MAX_STUDENTS][NAME_LENGTH], int rolls[MAX_STUDENTS], float marks[MAX_STUDENTS], int count);
void calculateAverage(float marks[MAX_STUDENTS], int count);

int main() {
    char studentNames[MAX_STUDENTS][NAME_LENGTH];
    int studentRolls[MAX_STUDENTS];
    float studentMarks[MAX_STUDENTS];
    int studentCount = 0;
    int choice;

    do {
        printf("\n=== STUDENT DATABASE SYSTEM ===\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student by Roll Number\n");
        printf("4. Calculate Class Average\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(studentNames, studentRolls, studentMarks, &studentCount);
                break;
            case 2:
                displayStudents(studentNames, studentRolls, studentMarks, studentCount);
                break;
            case 3:
                searchStudent(studentNames, studentRolls, studentMarks, studentCount);
                break;
            case 4:
                calculateAverage(studentMarks, studentCount);
                break;
            case 5:
                printf("\nExiting program. Goodbye!\n");
                break;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void addStudent(char names[MAX_STUDENTS][NAME_LENGTH], int rolls[MAX_STUDENTS], float marks[MAX_STUDENTS], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("\nDatabase full! Cannot add more students.\n");
        return;
    }

    printf("\nEnter Student Name: ");
    scanf(" %[^\n]", names[*count]);
    printf("Enter Roll Number: ");
    scanf("%d", &rolls[*count]);
    printf("Enter Marks: ");
    scanf("%f", &marks[*count]);

    (*count)++;
    printf("\nStudent added successfully!\n");
}

void displayStudents(char names[MAX_STUDENTS][NAME_LENGTH], int rolls[MAX_STUDENTS], float marks[MAX_STUDENTS], int count) {
    if (count == 0) {
        printf("\nNo student records found.\n");
        return;
    }

    printf("\n%-5s %-30s %-10s\n", "Roll", "Name", "Marks");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-5d %-30s %-10.2f\n", rolls[i], names[i], marks[i]);
    }
}

void searchStudent(char names[MAX_STUDENTS][NAME_LENGTH], int rolls[MAX_STUDENTS], float marks[MAX_STUDENTS], int count) {
    if (count == 0) {
        printf("\nNo student records found.\n");
        return;
    }

    int searchRoll;
    int found = 0;

    printf("\nEnter Roll Number to search: ");
    scanf("%d", &searchRoll);

    for (int i = 0; i < count; i++) {
        if (rolls[i] == searchRoll) {
            printf("\nStudent Found:\n");
            printf("Name: %s\n", names[i]);
            printf("Roll Number: %d\n", rolls[i]);
            printf("Marks: %.2f\n", marks[i]);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nStudent with Roll Number %d not found.\n", searchRoll);
    }
}

void calculateAverage(float marks[MAX_STUDENTS], int count) {
    if (count == 0) {
        printf("\nNo records available to compute average.\n");
        return;
    }

    float sum = 0;
    for (int i = 0; i < count; i++) {
        sum += marks[i];
    }

    printf("\nTotal Students: %d\n", count);
    printf("Class Average Marks: %.2f\n", sum / count);
}
