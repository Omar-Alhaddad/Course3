
#include <iostream>
#include <sstream>
#include <string>
#include <limits>
#include <iomanip>
#include <stdexcept>

using namespace std;

constexpr int MAX_FACTORIAL_INPUT = 170;
constexpr int FORMULA_ABBREVIATION_THRESHOLD = 15;

/**
 * @brief Clears the input buffer to handle invalid input.
 */
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
 * Validates and returns a non-negative integer from user input
 * @param prompt Message to display to the user
 * @return A non-negative integer entered by the user
 */
int validateNonNegativeNumber(const string& prompt) {

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

			cout << "Invalid input! Number must be non-negative (0 or greater).\n\n";
		}
		else
		{
			clearInputBuffer();
			return number;
		}
	}
}

/**
 * Calculates the factorial of a number
 * @param N The number to calculate the factorial for
 * @return The factorial of N
 * @throws overflow_error If N is greater than 170
 */
long double factorial(const int N) {

	if (N > MAX_FACTORIAL_INPUT)
	{
		throw overflow_error("Factorial too large to compute (max: "
			+ to_string(MAX_FACTORIAL_INPUT) + ")");
	}

	if (N == 1 || N == 0)
	{
		return 1;
	}

	long double result = 1;
	int i = N;

	while (i > 1)
	{
		result *= i;

		--i;
	}

	return result;
}

/**
 * Generates the factorial formula as a string
 * @param N The number to generate the formula for
 * @return The factorial formula as a string
 */
string factorialFormula(const int N) {

	if (N == 1 || N == 0)
	{
		return "1";
	}

	if (N > FORMULA_ABBREVIATION_THRESHOLD)
	{
		return to_string(N) + " * " + to_string(N - 1) + " * " + to_string(N - 2) + " * ... * 3 * 2 * 1";
	}

	ostringstream oss;

	int i = N;

	while (i > 1)
	{
		oss << i << " * ";

		--i;
	}

	oss << "1";

	return oss.str();
}

int main()
{
	// Program to calculate factorial of a non-negative number N
	try {

		cout << "\n=== Factorial Calculator ===\n\n";
		int number = validateNonNegativeNumber("Enter a non-negative number N : ");

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