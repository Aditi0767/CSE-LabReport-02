#include <stdio.h>

struct Employee {
    int id;
    char name[100];
    double basic;
    double houseRent;
    double medical;
    double gross;
};

int main() {
    struct Employee e[100];
    int n, i;

    printf("Enter number of employees: ");
    scanf("%d", &n);

    if (n <= 0 || n > 100) {
        printf("Invalid number of employees.\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("Employee %d (ID name basic house-rent medical): ", i + 1);
        scanf("%d %99s %lf %lf %lf", &e[i].id, e[i].name, &e[i].basic, &e[i].houseRent, &e[i].medical);
        e[i].gross = e[i].basic + e[i].houseRent + e[i].medical;
    }

    printf("\nID\tName\t\tBasic\t\tHouseRent\tMedical\t\tGross\n");

    for (i = 0; i < n; i++) {
        printf("%d\t%s\t\t%.2f\t%.2f\t%.2f\t\t%.2f\n", e[i].id, e[i].name, e[i].basic, e[i].houseRent, e[i].medical, e[i].gross);
    }

    return 0;
}
