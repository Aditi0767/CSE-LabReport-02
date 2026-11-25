#include <stdio.h>

int checkBalance(double balance, double amount) {
   if (balance >= amount) {
        return 1;
    } else {
        return 0;
    }
}    

int validateWithdrawal(double amount) {
    int wholeAmount = (int)amount;

    if (amount > 0 && amount == wholeAmount && wholeAmount % 500 == 0) {
        return 1;
    } else {
        return 0;
    }
}

double withdrawMoney(double balance, double amount) {
    return balance - amount;
}

void displayTransaction(int isValid, int hasSufficientFunds, double amount, double balance) {
    printf("\n");

    if (isValid == 1 && hasSufficientFunds == 1) {
        double updatedBalance = withdrawMoney(balance, amount);
        printf("Transaction Status : Successful\n");
        printf("Amount Withdrawn   : Tk %.lf\n", amount);
        printf("Remaining Balance  : Tk %.lf\n", updatedBalance);
    } else {
        printf("Transaction Status : Failed\n");
        printf("Amount Withdrawn   : Tk 0\n");
        printf("Remaining Balance  : Tk %.lf\n", balance);
    }
}

int main() {
    double balance, amount;

    printf("Enter account balance: ");
    scanf("%lf", &balance);
    printf("Enter withdrawal amount: ");
    scanf("%lf", &amount);

    int valid = validateWithdrawal(amount);
    int sufficient = checkBalance(balance, amount);

    displayTransaction(valid, sufficient, amount, balance);
    return 0;
}
