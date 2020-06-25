/*=====================================================================

Program: Read a file to identify coordinates then output its location
 on the coordinate plane to the file.
Author: Ian Eslinger
Class: CS1428 Honor

Instructor: Ziliang Zong
Date: 09/14/2016
Description: This program reads the target file for the value of a point
and then writes to the target file whether the point is in Quadrant I,II,
III, IV ,the x-axis, the y-axis, or the origin.
Input: File containing a point defined by a x-coordinate and a y-coordinate.
Output: Append the location of the point on the coordinate plane.
Compilation instructions:
Usage:

Modifications:

======================================================================*/

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    double x_cord;
    double y_cord;


    //Inform user the program is attempting to open the file
    cout << "Opening Target File" << endl;
    cout << endl;

    //Opening the file to read the contents
    ifstream fin;
    fin.open("points.txt");

    //Error handling for reading the file
    if ( !fin)
    {
        cout << "Error opening file";
        return -1;
    }

    //Storing contents of file to variables
    fin >> x_cord;
    fin >> y_cord;
    fin.close();

    //Inform user of the value of the variables
    cout << "The point is (" << x_cord << "," << y_cord << ")" << endl;
    cout << endl;

    //Opening the file to write to it
    ofstream fout;
    fout.open("points.txt",ios::app);

    //Error handling for attempting to update the file
    if (!fout)
    {
        cout << "Error Writing to target file";
        return -1;
    }

    //Assignment for the origin
    if(x_cord == 0 &&  y_cord == 0)
     {
         fout << endl << "The point ("<< x_cord << "," << y_cord
         << ") lies on the origin\n";
     }

    //Assignment for the Y Axis
    if(x_cord > 0 || x_cord < 0  &&  y_cord == 0)
     {
         fout << endl << "The point ("<< x_cord << "," << y_cord
         << ") lies on the X-Axis\n";
     }

    //Assignment for the Y Axis
    if(y_cord > 0 || y_cord < 0  &&  x_cord == 0)
     {
         fout << endl << "The point ("<< x_cord << "," << y_cord
         << ") lies on the Y-Axis\n";
     }

     //Assignment for Quadrant I
     if(x_cord > 0 && y_cord > 0)
     {
         fout << endl << "The point ("<< x_cord << "," << y_cord
         << ") lies in Quadrant I\n";
     }

     //Assignment for Quadrant II
     if(x_cord < 0 && y_cord > 0)
     {
         fout << endl << "The point ("<< x_cord << "," << y_cord
         << ") lies in Quadrant II\n";
     }

     //Assignment for Quadrant III
     if(x_cord < 0 && y_cord < 0)
     {
         fout << endl << "The point ("<< x_cord << "," << y_cord
         << ") lies in Quadrant III\n";
     }

     //Assignment for Quadrant IV
     if(x_cord > 0 && y_cord < 0)
     {
         fout << endl << "The point ("<< x_cord << "," << y_cord
         << ") lies in Quadrant IV\n";
     }
    //Exit the file
    fout.close();

    //Inform user the operation finished successfully
    cout << "The target file has been updated successfully!" << endl;
    cout << endl;

    //Exit Gracefully
    return 0;
}
