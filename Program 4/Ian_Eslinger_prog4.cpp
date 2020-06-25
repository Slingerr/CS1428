/*=====================================================================
Program: Piggy Bank that allows for deposits, withdrawals, and checking
the amount of coins that make up the current balance.
Author: Ian Eslinger
Class: CS1428 Honor
Instructor: Ziliang Zong
Date: 10/16/2016
Description: Piggy Bank that can make deposits, make withdrawals, and
check the statistics of what coins make up the current balance. Also,
it automatically converts coins to the next highest denomination.
Input: Amount of money to be deposited or withdrawn.
Output: Current balance in bank and total in change that make up the
current balance.
Compilation instructions:
Usage:

Modifications:
=====================================================================*/
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    const float QUARTER = 0.25, DIME = 0.10, NICKEL = 0.05, PENNY = 0.01;
    float balance = 0.00;
    float value, change_total;
    int choice, quarter , dime, nickel, penny;

    do
    {
        //Format balance to be shown in regular notation
        cout.setf(ios::showpoint | ios::fixed );

        //Format balance to only show 2 digits after decimal point
        cout << setprecision(2);

        //Make top of box
        cout.fill('*');
        cout << setw(35) << '*' << endl;


        //Show title of menu
        cout.setf(ios::left);
        cout << '*';
        cout.fill(' ');
        cout << setw(8) << ' ' << " Piggy Bank Menu " << setw(8) << ' ';
        cout.setf(ios::right);
        cout << '*' << endl;
        cout.setf(ios::left);
        cout << '*';
        cout.fill(' ');
        cout << setw(33) << ' ';
        cout.setf(ios::right);
        cout << '*' << endl;

        //Display current balance in top of menu
        cout.setf(ios::left);
        cout << '*';
        cout.fill(' ');
        cout << setw(2) << ' ' << "  Current Balance $ " << setw(6) << balance;
        cout << "  ";
        cout.setf(ios::right);
        cout << setw(3) << ' ' << '*' << endl;
        cout.fill('*');
        cout << setw(35) << '*' << endl;

        //Display Deposit Option
        cout.setf(ios::left);
        cout << '*';
        cout.fill(' ');
        cout << " 1)  Make Deposit";
        cout.setf(ios::right);
        cout << setw(16) << ' ' << '*' << endl;

        //Display Withdrawal Option
        cout.setf(ios::left);
        cout << '*';
        cout.fill(' ');
        cout << " 2)  Make Withdrawal";
        cout.setf(ios::right);
        cout << setw(13) << ' ' << '*' << endl;

        //Display view coin option
        cout.setf(ios::left);
        cout << '*';
        cout.fill(' ');
        cout << " 3)  View Coins";
        cout.setf(ios::right);
        cout << setw(18) << ' ' << '*' << endl;

        //Display exit option
        cout.setf(ios::left);
        cout << '*';
        cout.fill(' ');
        cout << " 4)  Exit Program";
        cout.setf(ios::right);
        cout << setw(16) << ' ' << '*' << endl;

        cout.fill('*');
        cout << setw(35) << '*' << endl;


        //Obtain user's choice
        cout << "Enter choice" << endl;
        cin >> choice;

      //Menu
      switch(choice)
        {
            //Option to deposit cash
            case 1:cout << "Input the value you want to deposit." << endl;
                   cin >> value;

                    //Error handling for negative values
                    if(value < 0)
                    {
                        cout << "Error : Negative values are not accepted.";
                        cout << endl;
                    }
                    //Error handling for exceeding the limit
                    else if (value + balance > 900.00)
                    {
                        cout << "The piggybank will not hold that much." << endl;
                        cout << "You may deposit up to $" << 900.00 - balance;
                        cout << endl;
                    }
                    //Depositing
                    else
                    {
                    balance += value;
                    }
                break;
            // Option to withdraw cash
            case 2:cout << "Input the value you want to withdraw." << endl;
                   cin >> value;

                    //Error handling for negative values
                    if(value < 0)
                    {
                    cout << "Error : Negative values are not accepted." << endl;
                    }
                    //Error handling for trying to withdraw more than possible
                    else if (value > balance)
                    {
                    cout << "The piggybank does not contain that much." << endl;
                    cout << "You may withdraw up to $" << balance << endl;
                    }
                    //Withdrawing
                    else
                    {
                    balance -= value;
                    }
                break;
            //Evaluate the stats of current balance
            case 3://Make a counter to use for finding coins
                   change_total = balance;

                   //Format the title of menu
                   cout.fill('*');
                   cout << setw(35) << '*' << endl;
                   cout.setf(ios::left);
                   cout << '*';
                   cout.fill(' ');
                   cout << setw(11) << ' ' << " Statistics " << setw(10);
                   cout << ' ';
                   cout.setf(ios::right);
                   cout << '*' << endl;
                   cout.fill('*');
                   cout << setw(35) << '*' << endl;

                   //Display number of quarters and their amount
                   cout.setf(ios::left);
                   cout << '*';
                   cout.fill(' ');
                   cout << setw(2) << ' ' << " Quarters" << setw(5) << ' ';
                   quarter = change_total/QUARTER;
                   change_total -= quarter*QUARTER;
                   cout << setw(4) << quarter << setw(3) << ' ' << "$ ";
                   cout << setw(6) << quarter*QUARTER;
                   cout.setf(ios::right);
                   cout << setw(2) << ' ' << '*' << endl;

                   //Display number of dimes and their amount
                   cout.setf(ios::left);
                   cout << '*';
                   cout.fill(' ');
                   cout << setw(2) << ' ' << " Dimes" << setw(8) << ' ';
                   dime = change_total/DIME;
                   change_total -= dime*DIME;
                   cout << setw(4) << dime << setw(3) << ' ' << "$ ";
                   cout << setw(6) << dime*DIME;
                   cout.setf(ios::right);
                   cout << setw(2) << ' ' << '*' << endl;

                   //Display number of nickels and their amount
                   cout.setf(ios::left);
                   cout << '*';
                   cout.fill(' ');
                   cout << setw(2) << ' ' << " Nickels" << setw(6) << ' ';
                   nickel = change_total/NICKEL;
                   change_total -= nickel*NICKEL;
                   cout << setw(4) << nickel << setw(3) << ' ' << "$ ";
                   cout << setw(6) << nickel*NICKEL;
                   cout.setf(ios::right);
                   cout << setw(2) << ' ' << '*' << endl;

                   //Display number of pennies and their amount
                   cout.setf(ios::left);
                   cout << '*';
                   cout.fill(' ');
                   cout << setw(2) << ' ' << " Pennies" << setw(9) << ' ';
                   penny = change_total/PENNY;
                   change_total -= penny * PENNY;
                   cout << penny << setw(3) << ' ' << "$ " << setw(6);
                   cout << penny*PENNY;
                   cout << setw(2) << ' ' << '*' << endl;

                   //Close the menu box
                   cout << '*';
                   cout.fill(' ');
                   cout << setw(33) << ' ' << '*' << endl;
                   cout.fill('*');
                   cout << setw(35) << '*' << endl;
                   cout << endl;
                break;
            //Exit the program
            case 4: cout << "GOODBYE!" << endl;
                break;
            //Error handling for invalid choice
            default : cout << "Error : Choice is invalid" << endl;
        }

    //Error handling for if balance becomes negative
        if(balance <0)
        {
            cout << "Error : Balance can not be negative" << endl;
            return -1;
        }
    }while(choice !=4);

    //Exit Gracefully
    return 0;
}
