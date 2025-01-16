#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct {
    char question[256];
    char options[4][100];
    int correct_option;
} quiz_question;

void display_question(quiz_question q, int question_number);
int getAnswer();

int main() {
    int total_questions = 10;  // Now we have 10 questions
    int score = 0;

    quiz_question quiz[] = {
        {
            "What is the capital of India?",
            {"1. Mumbai", "2. New Delhi", "3. Chennai", "4. Hyderabad"},
            2
        },
        {
            "Which programming language is this code written in?",
            {"1. Python", "2. C++", "3. C", "4. JavaScript"},
            3
        },
        {
            "What does RAM stand for?",
            {"1. Random Access Memory", "2. Read And Modify", "3. Runtime Access Memory", "4. Rapid Action Module"},
            1
        },
        {
            "What data type is used to store decimal numbers?",
            {"1. float", "2. int", "3. char", "4. string"},
            1
        },
        {
            "How many countries are there currently in the world?",
            {"1. 190", "2. 206", "3. 183", "4. 195"},
            4
        },
        {
            "Which planet is known as the Red Planet?",
            {"1. Venus", "2. Earth", "3. Mars", "4. Jupiter"},
            3
        },
        {
            "What is the largest mammal in the world?",
            {"1. Elephant", "2. Blue Whale", "3. Giraffe", "4. Shark"},
            2
        },
        {
            "Which country is known as the Land of the Rising Sun?",
            {"1. China", "2. Japan", "3. South Korea", "4. India"},
            2
        },
        {
            "Who wrote the play 'Romeo and Juliet'?",
            {"1. Charles Dickens", "2. William Shakespeare", "3. Jane Austen", "4. Mark Twain"},
            2
        },
        {
            "What is the main ingredient in guacamole?",
            {"1. Tomato", "2. Avocado", "3. Onion", "4. Garlic"},
            2
        },
    };

    printf("Welcome to the Online Quiz System!\n\n");

    for (int i = 0; i < total_questions; i++) {
        display_question(quiz[i], i + 1);
        int userAnswer = getAnswer();

        if (userAnswer == quiz[i].correct_option) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Wrong! The correct answer was %d.\n", quiz[i].correct_option);
        }
    }

    printf("\nQuiz Completed!\n");
    printf("Your Score: %d out of %d\n", score, total_questions);
    return 0;
}

void display_question(quiz_question q, int question_number) {
    printf("Question %d: %s\n", question_number, q.question);
    for (int i = 0; i < 4; i++) {
        printf("%s\n", q.options[i]);
    }
    printf("Enter your answer (1-4): ");
}

int getAnswer() {
    int answer;
    while (1) {
        if (scanf("%d", &answer) == 1 && answer >= 1 && answer <= 4) {
            return answer;
        } else {
            printf("Invalid input. Please enter a number between 1 and 4: ");
            while (getchar() != '\n');  // Clear the buffer
        }
    }
}

