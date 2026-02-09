
#include <iostream>
#include <string>
#include <limits>
#include <ranges>

using namespace std;

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
 * @brief Validates and returns a positive number entered by the user.
 *
 * @param prompt The prompt message to display to the user.
 * @return The positive number entered by the user.
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
 * Prints numbers from N down to 1 using a while loop
 * @param N The starting number (positive integer)
 */
void printNumbers(const int N) {

	int i = N;

	while (i >= 1)
	{
		cout << i << '\n';

		--i;
	}
}

/**
 * Prints numbers from N down to 1 using C++20 ranges
 * @param N The starting number (positive integer)
 */
void printNumbersNew(const int N) {

	auto range = views::iota(1, N + 1) | views::reverse;

	auto it = range.begin();
	auto end = range.end();

	while (it != end)
	{
		cout << *it << '\n';

		++it;
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