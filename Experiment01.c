#include <stdio.h>

float calculateBill(int units) {
    float charge = 0;
    if (units == 100) {
        charge = units * 5.00;
    } else if (units>=101 && units <= 200) {
        charge = (100 * 5.00) + ((units - 100) * 6.00);
    } else {
        charge = (100 * 5.00) + (100 * 6.00) + ((units - 200) * 8.00);
    }
    return charge;
}

float calculateVAT(float charge) {
    return charge * 0.05;
}

void displayBill(int id, char name[], int units, float charge, float vat, float total) {
    printf("\n------ Electricity Bill ------\n");
    printf("Customer ID        : %d\n", id);
    printf("Customer Name      : %s\n", name);
    printf("Units Consumed     : %d\n", units);
    printf("Electricity Charge : Tk %.2f\n", charge);
    printf("VAT (5%%)           : Tk %.2f\n", vat);
    printf("Final Bill         : Tk %.2f\n", total);
}

int main() {
    int id, units;
    char name[100];

    printf("Enter customer ID: ");
    scanf("%d", &id);
    printf("Enter customer name: ");
    scanf(" %[^\n]", name);
    printf("Enter units consumed: ");
    scanf("%d", &units);

    if (units < 0) {
        printf("Invalid input\n");
        return 1;
    }
    
    float charge = calculateBill(units);
    float vat = calculateVAT(charge);
    float total = charge + vat;
    displayBill(id, name, units, charge, vat, total);
    return 0;
}
