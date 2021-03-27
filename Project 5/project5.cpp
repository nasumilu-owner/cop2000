//Michael Lucas
//COP2000.53
//Project 5 - XYZ Corporation Weekly payroll report

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

/**
 * Opens the data file.
 * 
 * The data file is assumed to be in the same directory as
 * the program and is opened via relative path.
 * 
 * @param The ifstream to open
 */
void openFile(ifstream& filein) 
{
    filein.open("./weeklyMar9.txt");
}

/**
 * Tests that the file is open
 * 
 * If the file is not open the program will exit with
 * status 0
 * 
 * @param The ifstream to test whether it is valid and open
 */
void testFile(ifstream& filein)
{
    if(!filein || !filein.is_open()) {
        cerr << "\033[1;31mError: unable to open the data file!\033[0m\n" << endl;
        exit(0);
    }
}

/**
 * Closes the open file if needed.
 * 
 * @param The ifstream to close
 */
void closeFile(ifstream& filein)
{
    if(filein && filein.is_open()) {
        filein.close();
    }
}

/**
 * Displays the grand payroll total.
 * 
 * @param The total payroll cost
 */
void displayTotal(const float &total)
{
    cout << endl << "Total:" << setw(3) << "$" << right << setw(8) << total << endl;
}

/**
 * Calculates the weekly pay of an employee.
 * 
 * @param The employees payrate
 * @param The hours worked
 * @return The total employee's weekly pay
 */
float calcWeeklyPay(const float &payrate, const float &hours) 
{
    if(hours <= 40) {
        return payrate * hours;
    }
    return (payrate * 40) + ((hours - 40) * payrate * 1.5);
}

/**
 * Displays the payroll record for an employee.
 * 
 * @param The employee
 * @param The total weekly pay for `employee`
 */
void displayEmployee(const string employee, const float pay)
{
    cout << employee << setw(5) << "$" << right << setw(8) << pay << endl;
}

/**
 * The I do everything method. Reads data from the file, tokenizes the data, 
 * and well does everything else. 8-(
 * 
 * @param The ifstream to read the data from.
 */
void readFile(ifstream &filein) 
{
    string line{};
    float total{};

    while(getline(filein, line)) {
        stringstream str_stream{line};
        string employee{};
        float payrate{}, hours{}, pay{};
        
        str_stream >> employee >> payrate >> hours;
        pay = calcWeeklyPay(payrate, hours);
        total += pay;
        displayEmployee(employee, pay);
    }
    displayTotal(total);
}

/**
 * The main function. 
 * 
 * 1. Output the application title
 * 2. Set the fixed precision to 2
 * 3. Declare the ifstream
 * 4. Open the file
 * 5. Test that the file opened properly
 *    a. If not, exit(0)
 * 6. Read the data file
 * 7. Close the ifstream 
 */
int main()
{

    cout << "XYZ Corporation" <<endl
        << "Weekly payroll report" << endl
        << endl;
    cout << fixed << setprecision(2);

    ifstream filein;

    openFile(filein);
    testFile(filein);
    readFile(filein);
    closeFile(filein);

    system("PAUSE"); //this is an OS specific command

    //A non-OS specific pause command for non-terminal users.

    //cout << "Enter to exit the program...";
    //cin.ignore().get();

    return 0;

}