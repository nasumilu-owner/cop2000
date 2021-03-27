//Michael Lucas
//COP2000.53
//First Project - Displays name, address, phone, and major on the terminal

#include <iostream>
using namespace std;

int main()
{

    //---------------- Person Contact Output --------------//

    cout << "Michael Lucas" << endl
        << "1234 Some Street, Some Town, FL 12345" << endl
        << "555-456-7894" << endl
        << "AS 3624-PROG AND ANALYSIS\n"; //used \n here rather than std::endl

    //----------------------------------------------------//

    system("PAUSE"); //this is an OS specific command

    //A non-OS specific pause command for non-terminal users.

    //cout << "Enter to exit the program...";
    //cin.ignore().get();

    return 0;

}
