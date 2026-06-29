#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
            printf("Error: ID already exists.\n");
            return;
        }
    }
    
    printf("Enter Name: ");
    getchar(); 
    fgets(emp.name, sizeof(emp.name), stdin);
    emp.name[strcspn(emp.name, "\n")] = 0;
    
    printf("Enter Department: ");
    fgets(emp.department, sizeof(emp.department), stdin);
    emp.department[strcspn(emp.department, "\n")] = 0;
    
    printf("Enter Salary: ");
    scanf("%f", &emp.salary);
    
    employees[employeeCount] = emp;
    employeeCount++;
    printf("Employee added successfully!\n");
}

void listEmployees() {
    if (employeeCount == 0) {
        printf("\nNo records found.\n");
        return;
    }
    
    printf("\nID\tName\t\tDepartment\tSalary\n");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < employeeCount; i++) {
        printf("%d\t%-15s\t%-15s\t%.2f\n", 
               employees[i].id, employees[i].name, 
               employees[i].department, employees[i].salary);
    }
}

void searchEmployee() {
    if (employeeCount == 0) {
        printf("\nNo records found.\n");
        return;
    }
    
    int id;
    printf("\nEnter Employee ID to search: ");
    scanf("%d", &id);
    
    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].id == id) {
            printf("\nRecord Found:\n");
            printf("ID: %d\n", employees[i].id);
            printf("Name: %s\n", employees[i].name);
            printf("Department: %s\n", employees[i].department);
            printf("Salary: %.2f\n", employees[i].salary);
            return;
        }
    }
    printf("Employee with ID %d not found.\n", id);
}

void deleteEmployee() {
    if (employeeCount == 0) {
        printf("\nNo records found to delete.\n");
        return;
    }
    
    int id;
    printf("\nEnter Employee ID to delete: ");
    scanf("%d", &id);
    
    int index = -1;
    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].id == id) {
            index = i;
            break;
        }
    }
    
    if (index == -1) {
        printf("Employee with ID %d not found.\n", id);
        return;
    }
    
    for (int i = index; i < employeeCount - 1; i++) {
        employees[i] = employees[i + 1];
    }
    
    employeeCount--;
    printf("Employee record deleted successfully!\n");
}

int main() {
    int choice;
    
    while (1) {
        printf("\n*** Employee Management System ***\n");
        printf("1. Add Employee\n");
        printf("2. List All Employees\n");
        printf("3. Search Employee\n");
        printf("4. Delete Employee\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                listEmployees();
                break;
            case 3:
                searchEmployee();
                break;
            case 4:
                deleteEmployee();
                break;
            case 5:
                printf("\nExiting system. Goodbye!\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
    return 0;
}
