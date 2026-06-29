#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//employee management system
#define MAX_EMPLOYEES 100

struct Employee {
    int id;
    char name[50];
    char department[50];
    float salary;
};

struct Employee employees[MAX_EMPLOYEES];
int employeeCount = 0;

void addEmployee() {
    if (employeeCount >= MAX_EMPLOYEES) {
        printf("\nSystem full. Cannot add more employees.\n");
        return;
    }
    
    struct Employee emp;
    printf("\nEnter Employee ID: ");
    scanf("%d", &emp.id);
    
    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].id == emp.id) {
            printf("Error: Employee ID already exists.\n");
            return;
        }
    }
    
    printf("Enter Name: ");
    scanf(" %[^\n]s", emp.name);
    printf("Enter Department: ");
    scanf(" %[^\n]s", emp.department);
    printf("Enter Salary: ");
    scanf("%f", &emp.salary);
    
    employees[employeeCount] = emp;
    employeeCount++;
    printf("Employee added successfully!\n");
}

void displayEmployees() {
    if (employeeCount == 0) {
        printf("\nNo records found.\n");
        return;
    }
    
    printf("\n%-10s %-20s %-20s %-10s\n", "ID", "Name", "Department", "Salary");
    printf("------------------------------------------------------------\n");
    for (int i = 0; i < employeeCount; i++) {
        printf("%-10d %-20s %-20s %-10.2f\n", 
               employees[i].id, employees[i].name, employees[i].department, employees[i].salary);
    }
}

void searchEmployee() {
    if (employeeCount == 0) {
        printf("\nNo records available to search.\n");
        return;
    }
    
    int id, found = 0;
    printf("\nEnter Employee ID to search: ");
    scanf("%d", &id);
    
    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].id == id) {
            printf("\nRecord Found:\n");
            printf("ID: %d\nName: %s\nDepartment: %s\nSalary: %.2f\n", 
                   employees[i].id, employees[i].name, employees[i].department, employees[i].salary);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Employee with ID %d not found.\n", id);
    }
}

void updateEmployee() {
    if (employeeCount == 0) {
        printf("\nNo records available to update.\n");
        return;
    }
    
    int id, found = 0;
    printf("\nEnter Employee ID to update: ");
    scanf("%d", &id);
    
    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].id == id) {
            printf("Enter New Name: ");
            scanf(" %[^\n]s", employees[i].name);
            printf("Enter New Department: ");
            scanf(" %[^\n]s", employees[i].department);
            printf("Enter New Salary: ");
            scanf("%f", &employees[i].salary);
            printf("Employee record updated successfully!\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Employee with ID %d not found.\n", id);
    }
}

void deleteEmployee() {
    if (employeeCount == 0) {
        printf("\nNo records available to delete.\n");
        return;
    }
    
    int id, found = 0;
    printf("\nEnter Employee ID to delete: ");
    scanf("%d", &id);
    
    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].id == id) {
            for (int j = i; j < employeeCount - 1; j++) {
                employees[j] = employees[j + 1];
            }
            employeeCount--;
            printf("Employee deleted successfully!\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Employee with ID %d not found.\n", id);
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n=== Employee Management System ===\n");
        printf("1. Add Employee\n");
        printf("2. Display All Employees\n");
        printf("3. Search Employee\n");
        printf("4. Update Employee\n");
        printf("5. Delete Employee\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input format.\n");
            exit(1);
        }
        
        switch (choice) {
            case 1: addEmployee(); break;
            case 2: displayEmployees(); break;
            case 3: searchEmployee(); break;
            case 4: updateEmployee(); break;
            case 5: deleteEmployee(); break;
            case 6: printf("\nExiting program.\n"); exit(0);
            default: printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

