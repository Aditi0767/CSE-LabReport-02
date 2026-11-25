#include <stdio.h>

struct Patient {
    int id;
    char name[50];
    int age;
    char disease[50];
    double fee;
};

int main() {
    struct Patient p[100];
    int n, i;
    double totalFees = 0.0;

    printf("Enter number of patients: ");
    scanf("%d", &n);

    if (n <= 0 || n > 100) {
        printf("Invalid number of patients.\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("Patient %d (ID name age disease fee): ", i + 1);
        scanf("%d %49s %d %49s %lf", &p[i].id, p[i].name, &p[i].age, p[i].disease, &p[i].fee);
        totalFees = totalFees + p[i].fee;
    }

    printf("\n%-6s %-12s %-6s %-14s %-10s\n", "ID", "Name", "Age", "Disease", "Fee");

    for (i = 0; i < n; i++) {
        printf("%-6d %-12s %-6d %-14s %-10.2f\n", p[i].id, p[i].name, p[i].age, p[i].disease, p[i].fee);
    }

    printf("\nTotal consultation fees collected = Tk %.2f\n", totalFees);

    return 0;
}
