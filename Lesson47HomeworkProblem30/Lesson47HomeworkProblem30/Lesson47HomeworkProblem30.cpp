
#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
#include <stdexcept>

using namespace std;

// Clears the input buffer to handle invalid input
void clearInputBuffer() {

	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

/**
 * Prints a separator line
 * @param fillChar Character to fill the line with (default: '-')
 * @param length Length of the separator line (default: 50)
 */
void printSeparator(char fillChar = '-', int length = 50) {

	cout << string(length, fillChar) << '\n';
}

/**
 * Validates and returns a positive integer from user input
 * @param prompt Message to display to the user
 * @return A positive integer entered by the user
 */
int validatePositiveNumber(const string& prompt) {

	int number;

	while (true)
	{
		cout << prompt;

		if (!(cin >> number))
		{
			clearInputBuffer();

			cout << "Invalid input! Please enter a valid number.\n\n";
		}
		else if (number < 0)
		{
			clearInputBuffer();

			cout << "Invalid input! Number must be non-negative.\n\n";
		}
		else
		{
			clearInputBuffer();
			return number;
		}
	}
}

long double factorial(int N) {

	if (N > 170) {
		throw overflow_error("Factorial too large to compute");
	}

	long double result = 1;

	for (int i = N; i > 1; --i)
	{
		result *= i;
	}

	return result;
}

string factorialFormula(int N) {

	if (N == 1 || N == 0) return "1";

	if (N > 15)
	{
		return to_string(N) + " * " + to_string(N - 1) + " * " + to_string(N - 2) + " * ... * 3 * 2 * 1";
	}

	string str;
	str.reserve(N * 4);

	for (int i = N; i > 1; --i)
	{
		str += to_string(i) + " * ";
	}

	str += "1";

	return str;
}

int main()
{
	// Program to calculate factorial of a non-negative number N
	try {
		int number = validatePositiveNumber("Enter a non-negative number N : ");

		printSeparator();

		cout << number << "! = " << factorialFormula(number) << " = " << fixed << setprecision(0) << factorial(number) << '\n';

		printSeparator();
	}
	catch (const exception& e) {
		cerr << "\nError: " << e.what() << '\n';
		return 1;
	}

	return 0;
}