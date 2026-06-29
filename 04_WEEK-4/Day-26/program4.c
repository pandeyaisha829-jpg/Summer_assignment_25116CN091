#include <stdio.h>
#include <ctype.h>
//program to create quize application
typedef struct {
    char text[256];
    char options[4][128];
    char correct;
} Question;

int main() {
    Question quiz[3] = {
        {
            "Which programming language is known as the mother of all languages?",
            {"A. Python", "B. C", "C. Java", "D. Assembly"},
            'B'
        },
        {
            "What is the correct format specifier for an integer in C?",
            {"A. %f", "B. %c", "C. %d", "D. %s"},
            'C'
        },
        {
            "Which of the following is not a valid data type in C?",
            {"A. string", "B. int", "C. float", "D. char"},
            'A'
        }
    };

    int score = 0;
    char guess;

    printf("=== WELCOME TO THE C PROGRAMMING QUIZ ===\n\n");

    for (int i = 0; i < 3; i++) {
        printf("Question %d: %s\n", i + 1, quiz[i].text);
        
        for (int j = 0; j < 4; j++) {
            printf("%s\n", quiz[i].options[j]);
        }

        printf("Your answer (A, B, C, or D): ");
        scanf(" %c", &guess);
        
        guess = toupper(guess);

        if (guess == quiz[i].correct) {
            printf("Correct!\n\n");
            score++;
        } else {
            printf("Wrong! The correct answer was %c.\n\n", quiz[i].correct);
        }
    }

    printf("=== QUIZ FINISHED ===\n");
    printf("Your final score: %d out of 3\n", score);

    return 0;
}
