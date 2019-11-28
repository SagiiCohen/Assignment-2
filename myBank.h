#ifndef ASSIGNMENT2_MYBANK_H
#define ASSIGNMENT2_MYBANK_H
void openAccount(double init_deposit); //this function will open an account with the initial deposit given.
void getBalance(int acc_number); //this function will print the balance of the given account only if this account is open.
void deposit(int acc_number, double deposit_amount); //this function will print the new balance after deposit given only if account is open.
void withdraw(int acc_number, double withdraw_amount); //this function will print the new balance after withdraw(if there is enough money) and only if account is open.
void closeAccount(int acc_number); //this function will close the account of given account number only if account is open.
void addInterest(double interest); //this function will add given interest to all bank accounts.
void printOpenBankAccounts(); //this function will print all bank accounts and their balances.
void closeBank();; //this function will close all bank accounts and exit the program.

//private functions:
double myRound(double val);
#endif //ASSIGNMENT2_MYBANK_H

