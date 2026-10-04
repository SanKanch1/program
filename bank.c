# include <stdio.h>

struct BankAccount {
	char name[50];
	char accountNumber[20];
	char bankName[50];
	double balance;
};
int main() {
	struct BankAccount account;
	
	printf("Enter account holder name:");
    scanf(" %[^\n]", account.name);
    
    printf("Enter account number:");
    scanf("%19s", account.accountNumber);
    
    printf("Enter bank name:");
    scanf(" %[^\n]", account.bankName);
    
    printf("Enter account balance:");
    scanf("%lf", &account.balance);

printf("\n--- Bank Details ---\n");
    printf("Name: %s\n", account.name);
    printf("Account Number: %s\n", account.accountNumber);
    printf("Bank Name: %s\n", account.bankName);
    printf("Balance: %.2f\n", account.balance);

    return 0;
}


