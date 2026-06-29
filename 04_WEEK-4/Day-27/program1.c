#include <stdio.h>
#include <string.h>
//student record management system
#define MAX 100

typedef struct {
    int id;
    char name[50];
    int age;
    float gpa;
} Student;

Student db[MAX];
int cnt = 0;

void add() {
    if (cnt >= MAX) return;
    printf("\nID: "); scanf("%d", &db[cnt].id);
    printf("Name: "); scanf(" %[^\n]s", db[cnt].name);
    printf("Age: "); scanf("%d", &db[cnt].age);
    printf("GPA: "); scanf("%f", &db[cnt].gpa);
    cnt++;
}

void view() {
    for (int i = 0; i < cnt; i++)
        printf("ID: %d | Name: %s | GPA: %.2f\n", db[i].id, db[i].name, db[i].gpa);
}

void del() {
    int id, found = 0;
    printf("\nEnter ID to delete: "); scanf("%d", &id);
    for (int i = 0; i < cnt; i++) {
        if (db[i].id == id) {
            for (int j = i; j < cnt - 1; j++) db[j] = db[j + 1];
            cnt--; found = 1; break;
        }
    }
    if(found) printf("Deleted.\n");
}

int main() {
    int c;
    do {
        printf("\n1.Add 2.View 3.Delete 4.Exit\nChoice: ");
        scanf("%d", &c);
        if(c==1) add();
        else if(c==2) view();
        else if(c==3) del();
    } while (c != 4);
    return 0;
}
