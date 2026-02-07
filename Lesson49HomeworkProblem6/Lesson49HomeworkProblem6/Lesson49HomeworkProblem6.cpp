
#include <iostream>
#include <string>
#include <limits>

using namespace std;

constexpr int MIN_INPUT = 1;
constexpr int MAX_INPUT = 150;

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
 * @brief Clears the input buffer to handle invalid input.
 */
void clearInputBuffer() {

	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

/**
 * @brief Validates and returns a positive integer within specified range.
 *
 * @param prompt The message to display to the user.
 * @param minValue The minimum acceptable value.
 * @param maxValue The maximum acceptable value.
 * @return The validated integer.
 */
int validatePositiveInteger(const string& prompt, int minValue, int maxValue) {

	int number;

	while (true)
	{
		cout << prompt;

		if (!(cin >> number))
		{
			clearInputBuffer();

			cout << "Invalid input! Please enter a valid number.\n\n";
		}
		else if (number < minValue || number > maxValue)
		{
			clearInputBuffer();

			cout << "Invalid input! Number must be between " << minValue << " and " << maxValue << " (inclusive).\n\n";
		}
		else
		{
			clearInputBuffer();
			return number;
		}
	}
}

/**
 * @brief Prints a descending number triangle pattern
 * @param maxNumber The maximum number to display (default: 10)
 */
void printDescendingNumberTriangle(int maxNumber = 10) {

	if (maxNumber < MIN_INPUT || maxNumber > MAX_INPUT)
	{
		cout << "Warning: Invalid maxNumber (" << maxNumber << "). Using default value of 10.\n";
		maxNumber = 10;
	}

	// Print Descending Number Triangle
	for (int i = 1; i <= maxNumber; ++i)
	{
		for (int j = i; j <= maxNumber; ++j)
		{
			cout << j << ' ';
		}

		cout << '\n';
	}
}

int main()
{
	// Program that prints a descending number triangle
	int maxNumber = validatePositiveInteger("Enter the maximum number to display: ", MIN_INPUT, MAX_INPUT);

	printSeparator();

	cout << "Descending Number Triangle (From User Input):\n\n";
	printDescendingNumberTriangle(maxNumber);

	printSeparator();

	cout << "Descending Number Triangle (Default):\n\n";
	printDescendingNumberTriangle();

	return 0;
}