//Michael Lucas
//COP2000.53
//Project 2 - preform some simple calcuations with user input.

#include <iostream>
#include <iomanip>
//#include <cmath>

// The value of PI
#define PI 3.141592

using namespace std;

int main()
{

    //list initialize variables to a value of zero
    double value1{}, value2{}, area{};
    
    //const double PI = 3.141592;

    // ---------------- Circle Area ----------------------//

    // Using iomanip in the circle area
    //Now set the output stream percision
    cout << fixed << showpoint << setprecision(2);

    cout << "Find the Area!" << endl << endl;
    cout << "Circle:" << endl << endl;

    cout << "Enter the radius value in inches: ";
    cin >> value1; //value1 is the inputed radius

    area = PI * value1 * value1; // area of circle

    // Could use pow function from cmath
    // area = PI * pow(value1, 2);

    cout << endl
        << "The area of a circle with a radius of "
        << value1
        << " inches is: "
        << area
        << endl
        << endl;

    //----------------------------------------------------//

    // --------------- Rectangle Area --------------------//

    cout << "Rectangle:" << endl << endl;
    cout << "Enter the length in inches: ";
    cin >> value1; // value1 is the inputted length
    cout << endl << "Enter the width in inches: ";
    cin >> value2; // value2 is the inputted width

    area = value1 * value2; // area of rectangle

    //Using the old printf function :-)
    printf("\nThe area of a rectangle with a length of "
            "%0.2f inches and a width of %0.2f is: %0.2f\n\n",
            value1, value2, area);

    //----------------------------------------------------//

    // --------------- Triangle Area --------------------//

    cout << "Triangle:" << endl << endl;
    cout << "Enter the base in inches: ";
    cin >> value1; // value1 is the inputted base
    cout << endl << "Enter the height in inches: ";
    cin >> value2; // value2 is the inputted height

    area = (value1 * value2) / 2; // area of triangle

    // Again use the good old printf function :-)
    printf("\nThe are of a triangle with a base of %0.2f and "
            "a height of %0.2f inches is: %0.2f\n\n",
            value1, value1, area);
    //----------------------------------------------------//


    system("PAUSE"); //this is an OS specific command

    //A non-OS specific pause command for non-terminal users.

    //cout << "Enter to exit the program...";
    //cin.ignore().get();

    return 0;

}
