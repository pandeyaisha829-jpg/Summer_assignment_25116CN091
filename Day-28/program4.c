#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "contacts.txt"

typedef struct {
    char name[50];
    char phone[20];
    char email[50];
} Contact;

void addContact() {
    FILE *file = fopen(FILE_NAME, "ab");
    if (file == NULL) return;
    Contact c;
    printf("Enter Name: "); scanf(" %[^\n]", c.name);
    printf("Enter Phone: "); scanf(" %[^\n]", c.phone);
    printf("Enter Email: "); scanf(" %[^\n]", c.email);
    fwrite(&c, sizeof(Contact), 1, file);
    fclose(file);
    printf("Contact added!\n");
}

void viewContacts() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (file == NULL) { printf("No contacts.\n"); return; }
    Contact c;
    while (fread(&c, sizeof(Contact), 1, file))
        printf("Name: %s | Phone: %s | Email: %s\n", c.name, c.phone, c.email);
    fclose(file);
}

void searchContact() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (file == NULL) return;
    char name[50];
    printf("Enter Name to search: "); scanf(" %[^\n]", name);
    Contact c;
    while (fread(&c, sizeof(Contact), 1, file)) {
        if (strcasecmp(c.name, name) == 0) {
            printf("Found: %s, %s, %s\n", c.name, c.phone, c.email);
            fclose(file); return;
        }
    }
    printf("Not found.\n");
    fclose(file);
}

void editContact() {
    FILE *file = fopen(FILE_NAME, "rb+");
    if (file == NULL) return;
    char name[50];
    printf("Enter Name to edit: "); scanf(" %[^\n]", name);
    Contact c;
    while (fread(&c, sizeof(Contact), 1, file)) {
        if (strcasecmp(c.name, name) == 0) {
            printf("New Name: "); scanf(" %[^\n]", c.name);
            printf("New Phone: "); scanf(" %[^\n]", c.phone);
            printf("New Email: "); scanf(" %[^\n]", c.email);
            fseek(file, -sizeof(Contact), SEEK_CUR);
            fwrite(&c, sizeof(Contact), 1, file);
            break;
        }
    }
    fclose(file);
}

void deleteContact() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (file == NULL) return;
    FILE *temp = fopen("temp.txt", "wb");
    char name[50];
    printf("Enter Name to delete: "); scanf(" %[^\n]", name);
    Contact c;
    while (fread(&c, sizeof(Contact), 1, file)) {
        if (strcasecmp(c.name, name) != 0) fwrite(&c, sizeof(Contact), 1, temp);
    }
    fclose(file); fclose(temp);
    remove(FILE_NAME); rename("temp.txt", FILE_NAME);
}

int main() {
    int choice;
    while (1) {
        printf("\n1.Add 2.View 3.Search 4.Edit 5.Delete 6.Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addContact(); break;
            case 2: viewContacts(); break;
            case 3: searchContact(); break;
            case 4: editContact(); break;
            case 5: deleteContact(); break;
            case 6: exit(0);
        }
    }
    return 0;
}
