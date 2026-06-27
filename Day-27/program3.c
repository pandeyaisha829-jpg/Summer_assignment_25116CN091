#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//program for salary management system
#define MAX_EMPLOYEES 100

struct Employee {
    int id;
    char name[50];
    char designation[30];
    float basic_salary;
    float allowance;
    float deduction;
    float gross_salary;
    float net_salary;
};

struct Employee employees[MAX_EMPLOYEES];
int employee_count = 0;

void calculate_salary(struct Employee *emp) {
    emp->gross_salary = emp->basic_salary + emp->allowance;
    emp->net_salary = emp->gross_salary - emp->deduction;
}

void add_employee() {
    if (employee_count >= MAX_EMPLOYEES) {
        printf("\nSystem database is full!\n");
        return;
    }

    struct Employee emp;
    printf("\nEnter Employee ID: ");
    scanf("%d", &emp.id);
    
    for (int i = 0; i < employee_count; i++) {
        if (employees[i].id == emp.id) {
            printf("Error: Employee ID already exists!\n");
            return;
        }
    }

    printf("Enter Name: ");
    getchar(); 
    fgets(emp.name, sizeof(emp.name), stdin);
    emp.name[strcspn(emp.name, "\n")] = 0;

    printf("Enter Designation: ");
    fgets(emp.designation, sizeof(emp.designation), stdin);
    emp.designation[strcspn(emp.designation, "\n")] = 0;

    printf("Enter Basic Salary: ");
    scanf("%f", &emp.basic_salary);
    printf("Enter Allowances: ");
    scanf("%f", &emp.allowance);
    printf("Enter Deductions: ");
    scanf("%f", &emp.deduction);

    calculate_salary(&emp);
    employees[employee_count++] = emp;
    printf("\nEmployee record added successfully!\n");
}

void display_employees() {
    if (employee_count == 0) {
        printf("\nNo employee records found.\n");
        return;
    }

    printf("\n====================================================================================\n");
    printf("%-5s %-20s %-15s %-10s %-10s %-10s %-10s\n", "ID", "Name", "Designation", "Basic", "Allow.", "Deduct.", "Net Salary");
    printf("====================================================================================\n");
    
    for (int i = 0; i < employee_count; i++) {
        printf("%-5d %-20s %-15s %-10.2f %-10.2f %-10.2f %-10.2f\n",
               employees[i].id, employees[i].name, employees[i].designation,
               employees[i].basic_salary, employees[i].allowance,
               employees[i].deduction, employees[i].net_salary);
    }
    printf("====================================================================================\n");
}

void search_employee() {
    if (employee_count == 0) {
        printf("\nNo records available to search.\n");
        return;
    }

    int id, found = 0;
    printf("\nEnter Employee ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < employee_count; i++) {
        if (employees[i].id == id) {
            printf("\n--- Employee Found ---");
            printf("\nID: %d", employees[i].id);
            printf("\nName: %s", employees[i].name);
            printf("\nDesignation: %s", employees[i].designation);
            printf("\nBasic Salary: %.2f", employees[i].basic_salary);
            printf("\nAllowances: %.2f", employees[i].allowance);
            printf("\nDeductions: %.2f", employees[i].deduction);
            printf("\nGross Salary: %.2f", employees[i].gross_salary);
            printf("\nNet Salary: %.2f\n", employees[i].net_salary);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("\nEmployee ID %d not found.\n", id);
    }
}

void update_employee() {
    if (employee_count == 0) {
        printf("\nNo records available to update.\n");
        return;
    }

    int id, found = 0;
    printf("\nEnter Employee ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < employee_count; i++) {
        if (employees[i].id == id) {
            printf("\nEnter New Name: ");
            getchar();
            fgets(employees[i].name, sizeof(employees[i].name), stdin);
            employees[i].name[strcspn(employees[i].name, "\n")] = 0;

            printf("Enter New Designation: ");
            fgets(employees[i].designation, sizeof(employees[i].designation), stdin);
            employees[i].designation[strcspn(employees[i].designation, "\n")] = 0;

            printf("Enter New Basic Salary: ");
            scanf("%f", &employees[i].basic_salary);
            printf("Enter New Allowances: ");
            scanf("%f", &employees[i].allowance);
            printf("Enter New Deductions: ");
            scanf("%f", &employees[i].deduction);

            calculate_salary(&employees[i]);
            printf("\nRecord updated successfully!\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("\nEmployee ID %d not found.\n", id);
    }
}

void delete_employee() {
    if (employee_count == 0) {
        printf("\nNo records available to delete.\n");
        return;
    }

    int id, found = 0;
    printf("\nEnter Employee ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < employee_count; i++) {
        if (employees[i].id == id) {
            for (int j = i; j < employee_count - 1; j++) {
                employees[j] = employees[j + 1];
            }
            employee_count--;
            printf("\nEmployee record deleted successfully!\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("\nEmployee ID %d not found.\n", id);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n*** SALARY MANAGEMENT SYSTEM ***\n");
        printf("1. Add Employee Record\n");
        printf("2. Display All Employee Records\n");
        printf("3. Search Employee Record\n");
        printf("4. Update Employee Record\n");
        printf("5. Delete Employee Record\n");
        printf("6. Exit\n");
        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_employee();
                break;
            case 2:
                display_employees();
                break;
            case 3:
                search_employee();
                break;
            case 4:
                update_employee();
                break;
            case 5:
                delete_employee();
                break;
            case 6:
                printf("\nExiting system. Goodbye!\n");
                exit(0);
            default:
                printf("\nInvalid option! Please try again.\n");
        }
    }
    return 0;
}
