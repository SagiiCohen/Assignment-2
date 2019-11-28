#include <stdio.h>
#include "myBank.h"
#define accounts 50

int main()
{
    char user_input = 0; //setting the first byte to 0 to clear the entire char.
    while(user_input != 'E')
   {
       //Resetting all variables.
       double user_money = 0;
       double user_interest = 0;
       int acc_number = 0;

       printf("Transaction type? ");
       scanf(" %c", &user_input);
       if(user_input != 'O' && user_input != 'B' && user_input != 'D'
       && user_input != 'W' && user_input != 'C' && user_input != 'I' && user_input != 'P' && user_input != 'E') //invalid transaction type.
       {
           printf("Your transaction type was invalid, please try again.\n");
       }
       else //transaction type input is valid.
       {
           if(user_input == 'O')
           {
               printf("Initial deposit? ");
               if(scanf("%lf", &user_money)==1) openAccount(user_money);
               else printf("Please enter a valid deposit.\n");
           }
           else if(user_input == 'B')
           {
               printf("Account number? ");
               if(scanf("%d", &acc_number)==1) getBalance(acc_number);
               else printf("Please enter a valid account number.\n");
           }
           else if(user_input == 'D')
           {
               printf("Account number? ");
               if(scanf("%d", &acc_number)==1)
               {
                   printf("Amount? ");
                   if(scanf("%lf", &user_money)==1) deposit(acc_number,user_money);
                   else printf("Please enter a valid information.\n");
               }
               else printf("Please enter a valid information.\n");
           }
           else if(user_input == 'W')
           {
               printf("Account number? ");
               if(scanf("%d", &acc_number)==1)
               {
                   printf("Amount? ");
                   if(scanf("%lf", &user_money)==1) withdraw(acc_number,user_money);
                   else printf("Please enter a valid information.\n");
               }
               else printf("Please enter a valid information.\n");
           }
           else if(user_input == 'C')
           {
               printf("Account number? ");
               if(scanf("%d", &acc_number)==1) closeAccount(acc_number);
               else printf("Please enter a valid account number.\n");
           }
           else if(user_input == 'I')
           {
               printf("Interest rate? ");
               if(scanf("%lf", &user_interest)==1)
               {
                   addInterest(user_interest);
               }
               else printf("Please enter a valid information.\n");
           }
           else if(user_input == 'P') printOpenBankAccounts();
       }
       while ((getchar()) != '\n'); //clearing the input buffer.
   }
  //user input was 'E'. so we will close all the bank accounts and exit the program.
  closeBank();
  printf("Exiting program...");
  return 0; //exit the program.
}
