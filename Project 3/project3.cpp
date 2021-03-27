//Michael Lucas
//COP2000.53
//Project 3 - Lists the freezing and boiling points of several substances

#include <iostream>
#include <string>
#include <iomanip>

// Freezing and boiling points for ethyl alcohol in fahrenheit
#define ETHYL_ALCOHOL_FREEZING_POINT -173
#define ETHYL_ALCOHOL_BOILING_POINT 172

// Freezing and boiling points for mercury in fahrenheit
#define MERCURY_FREEZING_POINT -38
#define MERCURY_BOILING_POINT 676

// Freezing and boiling points for oxygen in fahrenheit
#define OXYGEN_FREEZING_POINT -362
#define OXYGEN_BOILING_POINT -306

// Freezing and boiling points for water in fahrenheit
#define WATER_FREEZING_POINT 32
#define WATER_BOILING_POINT 212

using namespace std;

int main()
{
    // initalize temperature variable to 0
    double temperature{};
    // a empty | concat string of valid freezing & boiling substances
    // derived from the inputed temperature.
    string freezing{}, boiling{};

    // Using iomanip to format our floating point numbers
    // so a little set is needed
    cout << fixed << showpoint << setprecision(2);

    cout << "Freezing and Boiling Points"
        << endl
        << endl
        << "Enter a temperature in Fahrenheit: ";

    //Get the temperature from std::cin
    cin >> temperature;

    // Freezing
    //
    // Since more than one substance can freeze at a
    // given temperature simple if statement to concatinate
    // acceptable values.

    // Here is an if statement.
    if(temperature <= ETHYL_ALCOHOL_FREEZING_POINT) {
        freezing += "Ethyl Alcohol; ";
    }

    // Ternary statments contatinating the next substance or empty string
    freezing += (temperature <= OXYGEN_FREEZING_POINT) ? "Oxygen; " : "";
    freezing += (temperature <= MERCURY_FREEZING_POINT) ? "Mercury; " : "";
    freezing += (temperature <= WATER_FREEZING_POINT) ? "Water; " : "";

    // Check for empty string if found echo "None Found!"
    cout << "\nFreezing:\t"
        << ((freezing.empty()) ? "None Found!" : freezing)
        << endl;

    //Boiling
    if(temperature >= ETHYL_ALCOHOL_BOILING_POINT) {
        boiling += "Ethyl Alcohol; ";
    }

    // Ternary statments contatinating the next substance or empty string
    boiling += (temperature >= OXYGEN_BOILING_POINT) ? "Oxygen; " : "";
    boiling += (temperature >= MERCURY_BOILING_POINT) ? "Mercury; " : "";
    boiling += (temperature >= WATER_BOILING_POINT) ? "Water; " : "";

    cout << "\nBoiling:\t"
        << ((boiling.empty()) ? "None Found!" : boiling)
        << endl;


    system("PAUSE"); //this is an OS specific command

    //A non-OS specific pause command for non-terminal users.

    //cout << "Enter to exit the program...";
    //cin.ignore().get();


    return 0;

}
