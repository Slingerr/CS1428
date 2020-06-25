/*=====================================================================

Program: Tool to calculate volume of water in a water tower.
Author: Ian Eslinger
Class: CS1428 Honor

Instructor: Ziliang Zong
Date: 09/27/2016
Description: Calculate the volume of water in a water tower depending on which
of the different sections is holding water and accounting for the change of
space between the cylindrical and conical portions.
Input: Height of water in water tower
Output: The volume of water stored in the water tower
Compilation instructions:
Usage:

Modifications:

Date Comment:

======================================================================*/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    const float PI = 3.1415926, r1 = 15, r2 = 25;
    float height, vol;

    //Obtain height of water from user
    cout << "Input the current height of the water in the tower" << endl;
    cin >> height;
    cout << endl;

    //Error Handling for invalid input value
    if(height < 0 || height > 50)
    {
        cout << "Incorrect height - ONLY range of 0-50.  Height: ";
        cin >> height;
        cout << endl;

        //Exit program if user inputs invalid value twice
        if(height < 0 || height > 50)
        {
            cout << "Please read the manual and try again later" << endl;
            cout << "Program exiting." << endl;
            return -1;
        }
    }
    //Calculate cylinder 1
    else if(height <= 20 && height > 0)
    {
        vol = PI * pow(r1 , 2) * height;

        cout << "With a height of " << height << " feet, the water volume is "
        << vol << " cubic feet." << endl;
    }
    //Calculate cone 1
    else if (height > 20 && height <=30)
    {
        height -= 5.0;
        vol = (PI/3.0) * (pow(height, 3) - pow(r1, 2));
        vol += 14137.2;
        height += 5.0;

        cout << "With a height of " << height << " feet, the water volume is "
        << vol << " cubic feet." << endl;
    }
    //Calculate cylinder 2
    else if(height > 30 && height <=40)
    {
        height -= 30.0;
        vol = PI * pow(r2, 2) * height;
        vol += 26965.4;
        height += 30.0;

        cout << "With a height of " << height << " feet, the water volume is "
        << vol << " cubic feet." << endl;

    }
    //Calculate cone 2
    else if (height > 40 && height <=50)
    {
        height -= 25;
        vol = (PI/3.0) * (pow(height, 3) - pow(r1, 3));
        vol+= 46600.4;
        height += 25;

        cout << "With a height of " << height << " feet, the water volume is "
        << vol << " cubic feet." << endl;

    }
//Exit Gracefully
return 0;
}
