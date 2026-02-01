
#include <iostream>
#include <string>
#include <limits>
#include <ranges>

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
		else if (number <= 0)
		{
			clearInputBuffer();

			cout << "Invalid input! Number must be positive (greater than 0).\n\n";
		}
		else
		{
			clearInputBuffer();
			return number;
		}
	}
}

/**
 * Prints numbers from N down to 1
 * @param N The starting number (positive integer)
 */
void printNumbers(int N) {

	for (int i = N; i >= 1; --i)
	{
		cout << i << '\n';
	}
}

/**
 * Prints numbers from N down to 1 using C++20 ranges
 * @param N The starting number (positive integer)
 */
void printNumbersNew(int N) {

	for (int i : views::iota(1, N + 1) | views::reverse)
	{
		cout << i << '\n';
	}
}

int main()
{
	// program prints numbers from N to 1, where N is a positive integer provided by the user
	int number = validatePositiveNumber("Enter a positive number to count from to 1: ");

	printSeparator();

	cout << "Traditional Loop:\n";
	printNumbers(number);

	printSeparator();

	cout << "C++20 Ranges:\n";
	printNumbersNew(number);

	return 0;
}