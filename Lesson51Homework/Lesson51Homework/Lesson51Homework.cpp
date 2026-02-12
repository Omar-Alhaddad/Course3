
#include <iostream>
#include <string>
#include <limits>

using namespace std;

constexpr int SEPARATOR_LENGTH = 50;
constexpr char SEPARATOR_CHAR = '-';

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
void printSeparator(char fillChar = SEPARATOR_CHAR, int length = SEPARATOR_LENGTH) {

	cout << string(length, fillChar) << '\n';
}

/**
 * @brief Reads an integer within a specified range using do-while loop
 * @param minValue Minimum acceptable value (inclusive)
 * @param maxValue Maximum acceptable value (inclusive)
 * @return Valid integer within the specified range
 */
int readIntegerNumberInRangeDoWhile(int minValue, int maxValue) {

	int number;

	do
	{
		cout << "Enter a number between " << minValue << " and " << maxValue << ": ";

		if (!(cin >> number))
		{
			clearInputBuffer();

			cout << "Invalid input! Please enter a valid number.\n\n";

			continue;
		}

		if (number < minValue || number > maxValue)
		{
			cout << "Wrong number! Number must be between " << minValue << " and " << maxValue << " (inclusive).\n\n";
		}

	} while (number < minValue || number > maxValue);

	return number;
}

/**
 * @brief Reads an integer within a specified range using while loop
 * @param minValue Minimum acceptable value (inclusive)
 * @param maxValue Maximum acceptable value (inclusive)
 * @return Valid integer within the specified range
 */
int readIntegerNumberInRangeWhile(int minValue, int maxValue) {

	int number;

	while (true)
	{
		cout << "Enter a number between " << minValue << " and " << maxValue << ": ";

		if (!(cin >> number))
		{
			clearInputBuffer();

			cout << "Invalid input! Please enter a valid number.\n\n";
		}
		else if (number < minValue || number > maxValue)
		{
			cout << "Wrong number! Number must be between " << minValue << " and " << maxValue << " (inclusive).\n\n";

		}
		else
		{
			return number;
		}
	}
}

int main()
{
	// Program to read an integer number between 18 and 45 using do-while loop and while loop approach
	int number = readIntegerNumberInRangeDoWhile(18, 45);
	cout << "\nThe number you entered is: " << number << '\n';

	printSeparator();

	int num = readIntegerNumberInRangeWhile(18, 45);
	cout << "\nThe number you entered is: " << num << '\n';

	return 0;
}