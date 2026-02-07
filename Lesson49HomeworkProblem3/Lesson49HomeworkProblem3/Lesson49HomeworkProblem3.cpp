
#include <iostream>
#include <string>

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

			cout << "Invalid input! Number must be between " << minValue << " and " << maxValue << "\n\n";
		}
		else
		{
			clearInputBuffer();
			return number;
		}
	}
}

/**
 * @brief Prints an inverted number triangle of the specified length.
 *
 * @param length The length of the inverted number triangle. Default is 10.
 */
void printInvertedNumberTriangle(int length = 10) {

	if (length <= 0) length = 10;

	for (int i = length; i >= 1; --i)
	{
		for (int j = 1; j <= i; ++j)
		{
			cout << j << ' ';
		}

		cout << '\n';
	}
}

int main()
{
	// Print inverted number triangle
	printInvertedNumberTriangle();

	printSeparator();

	int length = validatePositiveInteger("Enter the length of the inverted number triangle: ", MIN_INPUT, MAX_INPUT);

	printSeparator();

	printInvertedNumberTriangle(length);

	return 0;
}