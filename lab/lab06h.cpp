//Ian Eslinger

// Preprocessor Directive
#include <iostream>
#include <fstream>

// Namespace Directive
using namespace std;

// Main Function Declaration
int main ()
{
    const int OP_ADD = 0, OP_SUB = 1, OP_MUL = 2, OP_DIV = 3, OP_MOD = 4;
    const int OP_REA = 5, OP_WRT = 6, OP_STR = 7;

    int data0, data1, data2;

    //Array stating memory allocated
    int ram[256];
    //Memory array for instructions/operations
    int inst[4];

    //opening file
    ifstream fin;
    fin.open("age.txt");

    //Error handling for opening file
    if(!fin)
        {
            cout << "File could not be opened" << endl;
            return -1;
        }

while(!fin.eof())
{

    //Loop for storing arrat
    for(int i=0; i < 4; i++)
    {
        fin >> inst[i];
    }


    //Error Handling for dividing by 0
    if (ram[inst[0]] == 3 && ram[inst[3]] == 0)
        {
            cout<< "Can't divide by zero" << endl;
            return -1;
        }

   switch(inst[0])
   {
        //Addition
        case OP_ADD: data0 = ram[inst[2]] + ram[inst[3]];
        cout << "The sum is : " << data0 << endl;
        break;
while(!fin.eof())
{
        //Subtraction
        case OP_SUB: data0 = ram[inst[2]] - ram[inst[3]];
        cout << "The difference is : " << data0 << endl;
        break;

        //Multiplication
        case OP_MUL: data0 = ram[inst[2]] * ram[inst[3]];
        cout << "The product is : " << data0 << endl;
        break;

        //Division
        case OP_DIV: data0 = ram[inst[2]]/ ram[inst[3]];
        cout << "The quotient is : " << data0 << endl;
        break;

        //Modulus
        case OP_MOD: data0 = ram[inst[2]] % ram[inst[3]];
        cout << "The remainder is : " << data0 << endl;
        break;

        //Read
        case OP_REA: cout<< "Enter a value"<< endl;
            cin >> ram[inst[1]];
            break;
        //Write
        case OP_WRT: cout<< "Writing a value" << endl;
         cout << ram[inst[1]];
            break;
        //Store
        case OP_STR: cout << "Storing a value" << endl;
            ram[inst[1]] == inst[2];
            break;
        //Error Handling for unrecognized operations
        default:ram[inst[1]] = -1;
        cout << "Unable to perform operation" << endl;
        cout << ram[inst[1]] << endl;
   }
}

fin.close();

//Exit Gracefully
return 0;
}
