

#include <iostream>
#include <string>
#include "Account.h"
#include "Checkings.h"
#include "Savings.h"
using namespace std;



int mainMenu()   ///function for main menu interface
{

    int choice = 0;

    cout << "\n-----------------------------" << endl;
    cout << "|What would you like to do? |" << endl;
    cout << "-----------------------------" << endl;
    cout << "| 1. Deposit                |" << endl;
    cout << "| 2. Withdraw               |" << endl;
    cout << "| 3. Check Balance          |" << endl;
    cout << "| 4. Transfer Money         |" << endl;
    cout << "| 5. [Exit]                 |" << endl;
    cout << "-----------------------------" << endl;

    cin >> choice;
    return choice;
}

int main()
{
   ///class-objects instantiation
    Account accObj;
    Checkings checkObj;
    Savings savObj;

    cout << "-----------------------------" << endl;
    cout << "|    Welcome " << endl;
    cout << "-----------------------------" << endl;


    bool isNotFinished = true; ///used to break do-while loop
    int accountChoice = -1;

    ///loop through menu until user hits exit
    do
    {
        switch (mainMenu())
        {
        /// call deposit function
        case 1:
            cout << "-------------------------------------------------" << endl;
            cout << "| Which account would you like to deposit into? |" << endl;
            cout << "-------------------------------------------------" << endl;
            cout << "| 1. Checking                                   |" << endl;
            cout << "| 2. Savings                                    |" << endl;
            cout << "-------------------------------------------------" << endl;

            cin >> accountChoice;
            switch (accountChoice)
            {
            case 1:
                checkObj.setDeposit();
                break;
            case 2:
                savObj.setDeposit();
                break;
            default:
                cout << "Invalid choice! Please select again." << endl;
                break;
            }


            break;

        /// call widthdraw
        case 2:
            cout << "-------------------------------------------------" << endl;
            cout << "|       Which account to widthdrwaw from?       |" << endl;
            cout << "-------------------------------------------------" << endl;
            cout << "| 1. Checking                                   |" << endl;
            cout << "| 2. Savings                                    |" << endl;
            cout << "-------------------------------------------------" << endl;

            cin >> accountChoice;
            switch (accountChoice)   ///nested switch case to chose account type
            {
            case 1:
                checkObj.setWithdraw();
                break;
            case 2:
                savObj.setWithdraw();
                break;
            default:
                cout << "Invalid choice! Please select again." << endl;
                break;
            }

            break;
        case 3:

            /// call to check balance
            cout << "-------------------------------------------------" << endl;
            cout << "|       Check Account Balance for?              |" << endl;
            cout << "-------------------------------------------------" << endl;
            cout << "| 1. Checking                                   |" << endl;
            cout << "| 2. Saving                                     |" << endl;
            cout << "-------------------------------------------------" << endl;

            cin >> accountChoice;
            switch (accountChoice)
            {
            case 1:
                cout << "Your current Checking balance is $" << checkObj.getBalance(); /// gets balance for checkings account
                break;

            case 2:
                cout << "Your current Savings balance is $" << savObj.getSavingsBalance(); /// gets balance for savings account
                break;

            default:
                cout << "Invalid choice! Please select again." << endl;
                break;

            }

            break;


        /// call for transfer
        case 4:

            cout << "-------------------------------------------------" << endl;
            cout << "| Select account you wish to transer from.       |" << endl;
            cout << "-------------------------------------------------" << endl;
            cout << "| 1. Checkings to Savings                                   |" << endl;
            cout << "| 2. Savings to Checkings                                    |" << endl;
            cout << "-------------------------------------------------" << endl << endl;

            cin >> accountChoice;
            switch (accountChoice)
            {
            case 1:
            {
                double depositTOsav = checkObj.getTransfer(); /// Withdraw ammount from Checking
                savObj.setSavingsBalance(depositTOsav); /// Deposit ammount to Savings
                break;
            }
            case 2:
            {
                double depositTOcheck = savObj.getTransfer(); /// Withdraw ammount from Savings
                checkObj.setBalance(depositTOcheck); /// Deposit ammount to Checkings
                break;
            }
            default:
                cout << " Invalid choice! Please select again." << endl;

            }

            break;

        /// Call for EXIT on menu.
        case 5:
            cout << "Thank you Good Day" << endl;
            isNotFinished = false;
            break;

        default:
            cout << "Invalid choice! Please select again." << endl;
            break;
        }

    }
    while (isNotFinished);


    system("pause");
    return 0;

}
