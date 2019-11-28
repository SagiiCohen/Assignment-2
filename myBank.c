#include "myBank.h"
#include <stdio.h>
#define accounts 50 //numbers of rows in our matrix.
#define col 2 //numbers of columns in our matrix.
double bank[accounts][col]; //bank[row][0] = will storage the account money. and bank[row][1] = will storage the account state(open/close).
int number_of_open_accounts = 0; //keeping track of open accounts so we will not go over 50.

void openAccount(double init_deposit)
{
    for (int i = 0; i < accounts; i++)
    {
        if (bank[i][1] == 0 && number_of_open_accounts < 50) //account is closed in this bank location and there is no more then 50 open accounts.
        {
            bank[i][0] = myRound(init_deposit); //rounding the money so only two digits after the decimal point will enter the account.
            bank[i][1] = 1; //this account is now open.
            number_of_open_accounts++;
            printf("Welcome to our bank client %d ! We successfully added your initial deposit.\n", i+901);
            return;
        }
    }
}
void getBalance(int acc_number)
{
    if(acc_number < 901 || acc_number > 950 || bank[acc_number-901][1] != 1) printf("We have no account with such number\n"); //checking if the account exist and open in our bank system.
    else printf("The balance for account : %d, is : %0.2lf\n", acc_number, bank[acc_number-901][0]);
    return;
}
void deposit(int acc_number, double amount)
{
    if(acc_number < 901 || acc_number > 950 || bank[acc_number-901][1] != 1) printf("We have no account with such number\n"); //checking if the account exist and open in our bank system.
    else
    {
        bank[acc_number-901][0] += amount; //adding deposit to the account balance.
        printf("The balance after deposit for account : %d is : %0.2lf\n", acc_number, bank[acc_number-901][0]); //printing the new balance.
    }
}
void withdraw(int acc_number, double withdraw_amount)
{
    if(acc_number < 901 || acc_number > 950 || bank[acc_number-901][1] != 1) printf("We have no account with such number\n"); //checking if the account exist and open in our bank system.
    else
    {
        if (bank[acc_number - 901][0] >= withdraw_amount) //checking if there is enough money in the bank account.
        {
            bank[acc_number - 901][0] -= withdraw_amount;
            printf("The balance after withdraw for account : %d is : %0.2lf\n", acc_number,
                   bank[acc_number - 901][0]); //printing the new balance.
        }
        else printf("Not enough money in the bank account to complete the withdraw\n");
    }
}
void closeAccount(int acc_number)
{
    if(acc_number < 901 || acc_number > 950 || bank[acc_number-901][1] != 1) printf("There is no account in: %d\n",acc_number);
    else
    {
        bank[acc_number - 901][1] = 0; //closing the account.
        bank[acc_number - 901][0] = 0; //resetting the account money to zero.
        number_of_open_accounts--; //lowering the variable that keeps the count of open accounts.
        printf("Successfully closed account: %d \n", acc_number);
    }
}
void addInterest(double interest)
{
    double current_amount = 0;
    for(int i = 0; i < accounts; i++) //running throw all of the bank open accounts and add the interest.
    {
        if(bank[i][1] == 1)
        {
            current_amount = bank[i][0];
            bank[i][0] += (current_amount/100)*interest;
        }
    }
    printf("Interest rate of : %lf, was successfully added to all bank accounts.\n", interest);
}
void printOpenBankAccounts()
{
    int counter = 0;
    for(int i = 0; i < accounts; i++) //running throw all of the bank open accounts and add the interest.
    {
        if(bank[i][1] == 1)
        {
            getBalance(i+901);
            counter++;
        }
    }
    if(counter==0) printf("There are no open accounts in the bank.\n");
}
void closeBank() //close all the accounts.
{
    printf("Closing bank...\n");
    for(int i = 0; i < accounts; i++)
	{		
		if(bank[i][1] == 1) closeAccount(i+901);
	} 
}
//private function that will take only two digits after the decimal point.
double myRound(double val)
{
    int temp = (int)(val*100);
    return temp/100.0;
}

