#include <stdio.h>
#include <string.h>

#define MAX_ACCOUNTS 100

struct BankAccount {
    int accountNumber;
    char name[100];
    double balance;
};

struct BankAccount accounts[MAX_ACCOUNTS];
int totalAccounts = 0;

void createAccount() {
    if (totalAccounts >= MAX_ACCOUNTS) {
        printf("\nSystem full. Cannot create more accounts.\n");
        return;
    }

    struct BankAccount newAccount;
    printf("\nEnter Account Number: ");
    scanf("%d", &newAccount.accountNumber);

    for (int i = 0; i < totalAccounts; i++) {
        if (accounts[i].accountNumber == newAccount.accountNumber) {
            printf("\nAccount number already exists!\n");
            return;
        }
    }

    printf("Enter Account Holder Name: ");
    scanf(" %[^\n]s", newAccount.name);
    
    printf("Enter Initial Deposit Amount: ");
    scanf("%lf", &newAccount.balance);

    if (newAccount.balance < 0) {
        printf("\nInvalid deposit amount!\n");
        return;
    }

    accounts[totalAccounts] = newAccount;
    totalAccounts++;
    printf("\nAccount created successfully!\n");
}

int findAccountIndex(int accNum) {
    for (int i = 0; i < totalAccounts; i++) {
        if (accounts[i].accountNumber == accNum) {
            return i;
        }
    }
    return -1;
}

void depositMoney() {
    int accNum;
    double amount;

    printf("\nEnter Account Number: ");
    scanf("%d", &accNum);

    int index = findAccountIndex(accNum);
    if (index == -1) {
        printf("\nAccount not found!\n");
        return;
    }

    printf("Enter Amount to Deposit: ");
    scanf("%lf", &amount);

    if (amount <= 0) {
        printf("\nInvalid amount! Must be greater than 0.\n");
        return;
    }

    accounts[index].balance += amount;
    printf("\nSuccessfully deposited. New Balance: %.2f\n", accounts[index].balance);
}

void withdrawMoney() {
    int accNum;
    double amount;

    printf("\nEnter Account Number: ");
    scanf("%d", &accNum);

    int index = findAccountIndex(accNum);
    if (index == -1) {
        printf("\nAccount not found!\n");
        return;
    }

    printf("Enter Amount to Withdraw: ");
    scanf("%lf", &amount);

    if (amount <= 0) {
        printf("\nInvalid amount! Must be greater than 0.\n");
        return;
    }

    if (amount > accounts[index].balance) {
        printf("\nInsufficient balance!\n");
        return;
    }

    accounts[index].balance -= amount;
    printf("\nSuccessfully withdrawn. Remaining Balance: %.2f\n", accounts[index].balance);
}

void checkBalance() {
    int accNum;

    printf("\nEnter Account Number: ");
    scanf("%d", &accNum);

    int index = findAccountIndex(accNum);
    if (index == -1) {
        printf("\nAccount not found!\n");
        return;
    }

    printf("\n--- Account Details ---");
    printf("\nAccount Number: %d", accounts[index].accountNumber);
    printf("\nHolder Name   : %s", accounts[index].name);
    printf("\nBalance       : %.2f\n", accounts[index].balance);
}

int main() {
    int choice;

    do {
        printf("\n=== BANK ACCOUNT SYSTEM ===");
        printf("\n1. Create Account");
        printf("\n2. Deposit Money");
        printf("\n3. Withdraw Money");
        printf("\n4. Check Balance");
        printf("\n5. Exit");
        printf("\nEnter choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                depositMoney();
                break;
            case 3:
                withdrawMoney();
                break;
            case 4:
                checkBalance();
                break;
            case 5:
                printf("\nThank you for using our banking system!\n");
                break;
            default:
                printf("\nInvalid selection. Try again.\n");
        }
    } while (choice != 5);

    return 0;
}
