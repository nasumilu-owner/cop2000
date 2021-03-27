//Michael Lucas
//COP2000.53
//Project 8 - Read, sort, and display list columns of even and odd numbers

#include <iostream>
#include <fstream>
#include <vector>
#include <functional>
#include <string>
#include <iomanip>
#include <algorithm>

#define BUFFER_SIZE 200 // Random number buffer size

using namespace std;

template <int N>
class RandomNumberFileReader
{

public:

	static const int ASC = 1;
	static const int DESC = 0;

	/**
	 * Constructs a RandomNumberFileReader instance.
	 */
	RandomNumberFileReader(const string& filename, int order = ASC) {
		this->load(filename); // Load the data
		this->sort(order); // Sort the data
	}

	// Gets a vector with a copy of the odd numbers
	vector<int> odd_numbers()
	{
		return this->map([](int& number) -> bool {
			return number % 2 == 1;
			});
	}

	// Gets a vector with a copy of the even numbers
	vector<int> even_numbers()
	{
		return this->map([](int& number) -> bool {
			return number % 2 == 0;
			});
	}

	// Get a vector<int> mapped by the lambda function `func`
	vector<int> map(function<bool(int&)> func)
	{
		vector<int> mapped_values{};
		for (int i = 0; i < N; i++) {

			if (this->numbers[i] != 0 && func(this->numbers[i])) {
				mapped_values.push_back(this->numbers[i]);
			}
		}
		mapped_values.shrink_to_fit();
		return mapped_values;
	}

	// << operator overloading to display formated output to an osteam.
	friend ostream& operator << (ostream& os, RandomNumberFileReader& reader) {
		vector<int> odd_numbers = reader.odd_numbers();
		vector<int> even_numbers = reader.even_numbers();

		int odd_size = odd_numbers.size();
		int even_size = even_numbers.size();
		os << left << endl << "  Random Number File Reader and Sorter" << endl << endl;
		os << "+---------------------------------------+" << endl;
		os << setw(25) << "| Total Even Numbers:" << setw(15) << even_size << "|" << endl;
		os << setw(25) << "| Total Odd Numbers:" << setw(15) << odd_size << "|" << endl;
		os << "+-------------------+-------------------+" << endl;
		os << setw(20) << "| Even Numbers" << setw(20) << "| Odd Numbers" << setw(3) << "|" << endl;
		os << "+-------------------+-------------------+" << endl;


		int length = max(odd_size, even_size);
		for (int i = 0; i < length; i++) {
			os << "|" << setw(10);
			if (even_size > i) {
				os << right << even_numbers.at(i);
			}
			else {
				os << " - ";
			}
			os << setw(10) << "|" << setw(10);
			if (odd_size > i) {
				os << odd_numbers.at(i);
			}
			else
			{
				os << " - ";
			}

			os << setw(10) << "|";
			os << endl;
		}
		os << "+-------------------+-------------------+" << endl;
		return os;
	}

private:
	// Loads the data from the file `filename`
	void load(const string& filename)
	{
		ifstream filein{};
		filein.open(filename);
		if (!filein.is_open()) {
			cerr << "\033[1;31mUnable to open file " << filename << "!\033[0m" << endl;
			exit(404);
		}
		int value{};
		int i = 0;
		while (filein >> value && i < N) {
			this->numbers[i] = value;
			i += 1;
		}
		filein.close();
	}

	// Sorts the data using selection sort algorithm
	void sort(int order = ASC) {
		for (int i = 0; i < N - 1; i++) {
			int index = i;
			for (int j = i + 1; j < N; j++) {
				if (order == ASC & (this->numbers[j] < this->numbers[index])) {
					index = j;
				}
				else if (order == DESC & (this->numbers[j] > this->numbers[index])) {
					index = j;
				}
			}
			if (index != i) {
				swap(this->numbers[i], this->numbers[index]);
			}
		}
	}

	// array of sorted random numbers
	int numbers[N]{};

};

int main(int argc, char** argv)
{
	string filename{ "./Random.txt" };
	int sort_order = RandomNumberFileReader<BUFFER_SIZE>::ASC;
	if (argc > 1) {
		filename = argv[1];
	}

	if (argc > 2) {
		sort_order = stoi(argv[2]);
	}

	RandomNumberFileReader<BUFFER_SIZE> reader = RandomNumberFileReader<BUFFER_SIZE>(filename, sort_order);
	cout << reader;

	system("PAUSE"); //this is an OS specific command

	//A non-OS specific pause command for non-terminal users.

	//cout << "Enter to exit the program...";
	//cin.ignore().get();

	return 0;
}