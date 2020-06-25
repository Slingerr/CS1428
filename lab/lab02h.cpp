//Ian Eslinger

// Preprocessor Directive
#include <iostream>
#include <iomanip>

// Namespace Directive
using namespace std;

// Main Function Declaration
int main ()
{
   float balance = 60.71;
   int quarter, dime, nickel, penny;
   const float QUARTER = 0.25, DIME = 0.10, NICKEL = 0.05, PENNY = 0.01;
   int total;

   cout.setf(ios::showpoint | ios::fixed );
   cout << setprecision(2) << fixed;

   quarter = balance/QUARTER;
   cout <<  "AMount of quarters : " << quarter << endl;

   balance -= quarter*QUARTER;
   cout << balance << endl;


   dime = balance/DIME;
   cout << "Amount of dimes : " << dime << endl;

   cout << dime * DIME << endl;

   balance -= dime*DIME;
   cout << balance << endl;

   nickel = balance/NICKEL;
   cout << "Amount of nickels  : " << nickel << endl;

   balance -= nickel*NICKEL;
   cout << balance << endl;

   penny = balance/PENNY;
   cout << "Amount of pennies : " << penny << endl;

   balance -= penny * PENNY;
   cout << balance << endl;







 return 0;
}
