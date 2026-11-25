#include <stdio.h>

int calculateTotal(int m1, int m2, int m3, int m4, int m5) {
    return m1 + m2 + m3 + m4 + m5;
}

double calculateAverage(int total) {
    return total / 5;
}

void calculateGrade(float avg) {
    if (avg >= 80 && avg <= 100) {
        printf("Grade   : A+\n");
        printf("GPA     : 4.00\n");
    } else if (avg >= 70 && avg <= 79) {
        printf("Grade   : A\n");
        printf("GPA     : 3.50\n");
    } else if (avg >= 60 && avg <= 69) {
        printf("Grade   : A-\n");
        printf("GPA     : 3.00\n");
    } else if (avg >= 50 && avg <= 59) {
        printf("Grade   : B\n");
        printf("GPA     : 2.50\n");
    } else if (avg >= 40 && avg <= 49) {
        printf("Grade   : C\n");
        printf("GPA     : 2.00\n");
    } else if(avg <40){
        printf("Grade   : F\n");
        printf("GPA     : 0.00\n");
    }
}

void displayResult(char name[], int id, int m1, int m2, int m3, int m4, int m5, int total, float avg) {
    printf("\n------ Student Result ------\n");
    printf("Name    : %s\n", name);
    printf("ID      : %d\n", id);
    printf("Total   : %d\n", total);
    printf("Average : %.2f\n", avg);

    calculateGrade(avg);

    if (m1 < 40 || m2 < 40 || m3 < 40 || m4 < 40 || m5 < 40 || avg < 40.0) {
        printf("Result  : Fail\n");
    } else {
        printf("Result  : Pass\n");
    }
}

int main() {
    char name[100];
    int id;
    int m1, m2, m3, m4, m5;

    printf("Enter student name: ");
    scanf(" %99[^\n]", name);
    printf("Enter student ID: ");
    scanf("%d", &id);
    printf("Enter marks of 5 subjects: ");
    scanf("%d %d %d %d %d", &m1, &m2, &m3, &m4, &m5);

    if (m1 < 0 || m1 > 100 || m2 < 0 || m2 > 100 || m3 < 0 || m3 > 100 || m4 < 0 || m4 > 100 || m5 < 0 || m5 > 100) {
        printf("Invalid marks\n");
        return 1;
    }

    int total = calculateTotal(m1, m2, m3, m4, m5);
    float avg = calculateAverage(total);

    displayResult(name, id, m1, m2, m3, m4, m5, total, avg);

    return 0;
}