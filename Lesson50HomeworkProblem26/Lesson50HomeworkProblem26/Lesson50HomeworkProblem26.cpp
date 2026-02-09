
#include <iostream>
#include <string>
#include <limits>

using namespace std;

/**
 * @brief Clears the input buffer to handle invalid input.
 */
void clearInputBuffer() {

	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

/**
 * @brief Prints a separator line with the specified character and length.
 *
 * @param fillChar The character to fill the line with. Default is '-'.
 * @param length The length of the line. Default is 50.
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
 * @brief Prints numbers from 1 to the specified number using a while loop.
 *
 * @param N The number to count to.
 */
void printNumbers(const int N) {

	int i = 1;

	while (i <= N)
	{
		cout << i << '\n';

		++i;
	}
}

int main()
{
	// program prints numbers from 1 to N, where N is a positive integer provided by the user 
	int number = validatePositiveNumber("Enter a positive number to count to: ");

	printSeparator();

	printNumbers(number);

	return 0;
}