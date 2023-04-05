#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 100

struct customer {
    int account_number;
    char name[50];
    float balance;
};

struct customer customers[MAX_CUSTOMERS];
int num_customers = 0;

void add_customer() {
    struct customer c;
    printf("Enter account number: ");
    scanf("%d", &c.account_number);
    printf("Enter name: ");
    scanf("%s", c.name);
    printf("Enter balance: ");
    scanf("%f", &c.balance);
    customers[num_customers] = c;
    num_customers++;
    printf("Customer added successfully!\n");
}

void view_customers() {
    printf("Customers:\n");
    for (int i = 0; i < num_customers; i++) {
        struct customer c = customers[i];
        printf("Account Number: %d\n", c.account_number);
        printf("Name: %s\n", c.name);
        printf("Balance: $%.2f\n", c.balance);
        printf("\n");
    }
}

void search_customer() {
    int account_number;
    printf("Enter account number: ");
    scanf("%d", &account_number);
    for (int i = 0; i < num_customers; i++) {
        struct customer c = customers[i];
        if (c.account_number == account_number) {
            printf("Name: %s\n", c.name);
            printf("Balance: $%.2f\n", c.balance);
            return;
        }
    }
    printf("Customer not found!\n");
}

void deposit() {
    int account_number;
    printf("Enter account number: ");
    scanf("%d", &account_number);
    for (int i = 0; i < num_customers; i++) {
        struct customer *c = &customers[i];
        if (c->account_number == account_number) {
            float amount;
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            c->balance += amount;
            printf("Deposit of $%.2f successful\n", amount);
            return;
        }
    }
    printf("Customer not found!\n");
}

void withdraw() {
    int account_number;
    printf("Enter account number: ");
    scanf("%d", &account_number);
    for (int i = 0; i < num_customers; i++) {
        struct customer *c = &customers[i];
        if (c->account_number == account_number) {
            float amount;
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);
            if (c->balance < amount) {
                printf("Insufficient balance\n");
                return;
            } else {
                c->balance -= amount;
                printf("Withdrawal of $%.2f successful\n", amount);
                return;
            }
        }
    }
    printf("Customer not found!\n");
}

void delete_customer() {
    int account_number;
    printf("Enter account number: ");
    scanf("%d", &account_number);
    for (int i = 0; i < num_customers; i++) {
        struct customer *c = &customers[i];
        if (c->account_number == account_number) {
            memmove(c, c+1, (num_customers-i-1)*sizeof(struct customer));
            num_customers--;
            printf("Customer deleted successfully!\n");
            return;
        }
    }
    printf("Customer not found!\n");
}

int main() {
    int choice;
    while (1) {
        printf("\nBank Management System\n");
        printf("        1. Add Customer\n");
        printf("        2. View Customers\n");
        printf("        3. Search Customer\n");
        printf("        4. Deposit\n");
        printf("        5. Withdraw\n");
        printf("        6. Delete Customer\n");
        printf("        7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_customer();
                break;
            case 2:
                view_customers();
                break;
            case 3:
                search_customer();
                break;
            case 4:
                deposit();
                break;
            case 5:
                withdraw();
                break;
            case 6:
                delete_customer();
                break;
            case 7:
                printf("Thank you for using our bank management system\n");
                exit(0);
            default:
                printf("Invalid choice, please try again!\n");
        }
    }
    return 0;
}
