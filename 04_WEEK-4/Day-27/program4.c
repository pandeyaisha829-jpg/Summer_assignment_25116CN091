#include <stdio.h>
#include <string.h>
//marksheeet generation system
struct Student {
    int roll_no;
    char name[50];
    int math;
    int science;
    int english;
    int total;
    float percentage;
    char grade[5];
};

void calculate_marksheet(struct Student *s) {
    s->total = s->math + s->science + s->english;
    s->percentage = s->total / 3.0;

    if (s->percentage >= 90) {
        strcpy(s->grade, "A+");
    } else if (s->percentage >= 80) {
        strcpy(s->grade, "A");
    } else if (s->percentage >= 70) {
        strcpy(s->grade, "B");
    } else if (s->percentage >= 60) {
        strcpy(s->grade, "C");
    } else if (s->percentage >= 50) {
        strcpy(s->grade, "D");
    } else {
        strcpy(s->grade, "F");
    }
}

void print_marksheet(struct Student s) {
    printf("\n==========================================\n");
    printf("            STUDENT MARKSHEET             \n");
    printf("==========================================\n");
    printf(" Roll No : %-15d Name : %s\n", s.roll_no, s.name);
    printf("------------------------------------------\n");
    printf(" Subject          Max Marks   Obtained \n");
    printf("------------------------------------------\n");
    printf(" Mathematics      100         %d\n", s.math);
    printf(" Science          100         %d\n", s.science);
    printf(" English          100         %d\n", s.english);
    printf("------------------------------------------\n");
    printf(" Total Marks    : %d / 300\n", s.total);
    printf(" Percentage     : %.2f%%\n", s.percentage);
    printf(" Final Grade    : %s\n", s.grade);
    printf("==========================================\n");
}

int main() {
    struct Student s;

    printf("Enter Student Roll Number: ");
    scanf("%d", &s.roll_no);
    getchar();

    printf("Enter Student Name: ");
    fgets(s.name, sizeof(s.name), stdin);
    s.name[strcspn(s.name, "\n")] = 0;

    printf("Enter Marks for Mathematics: ");
    scanf("%d", &s.math);

    printf("Enter Marks for Science: ");
    scanf("%d", &s.science);

    printf("Enter Marks for English: ");
    scanf("%d", &s.english);

    calculate_marksheet(&s);
    print_marksheet(s);

    return 0;
}
