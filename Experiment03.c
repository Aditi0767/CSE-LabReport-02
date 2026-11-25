#include <stdio.h>

double calculateDiscount(double amount) {
    if (amount >= 5000) {
        return amount * 0.10;
    } else if (amount >= 3000 && amount <= 4999) {
        return amount * 0.05;
    } else {
        return 0.0;
    }
}

double calculateFinalAmount(double amount, double discount) {
    return amount - discount;
}

void displayReceipt(char name[], double amount, double discount, double finalAmount) {
    int rate = 0;
    if (amount >= 5000){
    rate = 10;
    }
    else if (amount >= 3000 && amount <= 4999){
    rate = 5;
    }

    printf("\n------ Receipt ------\n");
    printf("Customer Name  : %s\n", name);
    printf("Purchase Amount: Tk %.2f\n", amount);
    printf("Discount (%d%%)  : Tk %.2f\n", rate, discount);
    printf("Final Payable  : Tk %.2f\n", finalAmount);
}

int main() {
    char name[100];
    double amount;

    printf("Enter customer name: ");
    scanf(" %99[^\n]", name);
    printf("Enter purchase amount: ");
    scanf("%lf", &amount);

    if (amount < 0.0) {
        printf("Invalid input\n");
        return 1;
    }

    double discount = calculateDiscount(amount);
    double finalAmount = calculateFinalAmount(amount, discount);

    displayReceipt(name, amount, discount, finalAmount);
    return 0;
}
