//Michael Lucas
//COP2000.53
//Project 4 - Population Histogram

#include <iostream>
#include <string>
#include <locale>
#include <algorithm>

#define POPULATION_MIN_VALUE 1000000            //population minimum allowed value
#define POPULATION_MAX_VALUE 1400000000         //population maximum allowed value
#define POPULATION_HISTOGRAM_FACTOR 1000000     //factor used when creating the histogram

using namespace std;

/**
 * The predict for the is_numeric function.
 *
 * Uses the std::isdigit() function to verivy that the character is a digit
 * or check to see if it is a minus sign '-'.
 *
 * @see Michael Gautier - https://gautiertalkstechnology.wordpress.com/2015/04/20/cplusplus-isnumeric-function/
 * @param value - The character to check that it is a digit
 * @return True if `value` is a digit; otherwise false
 */
bool is_digit(const char value)
{
	return isdigit(value) || value == '-';
}

/**
 * Indicates whether the string `value` contains all digits [0-9].
 *
 * @see Michael Gautier - https://gautiertalkstechnology.wordpress.com/2015/04/20/cplusplus-isnumeric-function/
 * @param value - A string to check that it contains all digits
 * @return True if all `value` characters are digits; otherwise false
 */
bool is_numeric(const string& value)
{
	return all_of(value.begin(), value.end(), is_digit);
}

/**
 * Prompts the user to input a County's population.
 *
 * This function will validate the input and repeat until valid input is correctly
 * entered.
 *
 * @param index - The County's array offset
 * @return The County's population as an integer
 */
int prompt_population(const int& index)
{
	string population{};
	bool valid{ false };
	while (!valid)
	{
		printf("Enter the population for country %d:\t", index + 1);
		getline(cin, population);

		if (!is_numeric(population)) {
			printf("\033[1;31mValue must be numeric, found %s!\033[0m\n", population.c_str());
			valid = false;
		}
		else if (stoi(population) < POPULATION_MIN_VALUE || stoi(population) > POPULATION_MAX_VALUE) {
			printf("\033[1;31mValue must be between %d and %d - found %d!\033[0m\n", POPULATION_MIN_VALUE, POPULATION_MAX_VALUE, stoi(population));
			valid = false;
		}
		else {
			valid = true;
		}
	}

	return stoi(population);
}

/**
 * Outputs a County's population histogram.
 *
 * @param index - The County's index
 * @param population - The County's population value
 */
void population_column(const int& index, const int& population)
{
	string column{};
	column.assign(population / POPULATION_HISTOGRAM_FACTOR, '*');
	printf("\033[1;32mCountry %d: %s\033[0m\n", index + 1, column.c_str());
}

/**
 * The applications main function.
 *
 * @return zero (0) when successful
 */
int main()
{
	setlocale(LC_NUMERIC, "en_US");
	int populations[5]{ 0,0,0,0,0 };
	cout << "Population Histogram" << endl << endl;
	for (int i = 0; i < 5; i++) {
		populations[i] = prompt_population(i);
	}
	printf("\n\033[1;33mPOPULATION BAR CHART\033[0m\n(Each * = %d)\n", POPULATION_HISTOGRAM_FACTOR);
	for (int i = 0; i < 5; i++) {
		population_column(i, populations[i]);
	}

	system("PAUSE"); //this is an OS specific command

	//A non-OS specific pause command for non-terminal users.

	//cout << "Enter to exit the program...";
	//cin.ignore().get();

	return 0;

}