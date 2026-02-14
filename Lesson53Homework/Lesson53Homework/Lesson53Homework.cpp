
#include <iostream>
#include <string>
#include <limits>

using namespace std;

constexpr int SIZE = 5;
constexpr int MIN_INPUT = 1;
constexpr int MAX_INPUT = 100;
constexpr int SUM_THRESHOLD = 50;

/**
 * @brief Prints a separator line with the specified character and count.
 *
 * @param fillChar The character to fill the line with. Default is '-'.
 * @param count The number of characters in the line. Default is 50.
 */
void printSeparator(char fillChar = '-', int count = 50) {

	cout << string(count, fillChar) << '\n';
}

/**
 * @brief Clears the input buffer to handle invalid input.
 */
void clearInputBuffer() {

	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

/**
 * @brief Validates and returns an integer within specified range.
 *
 * @param prompt The message to display to the user.
 * @param minValue The minimum acceptable value.
 * @param maxValue The maximum acceptable value.
 * @return The validated integer.
 */
int validateIntegerInRange(const string& prompt, int minValue, int maxValue) {

	int number;

	while (true)
	{
		cout << prompt << flush;

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
			clearInputBuffer();  // Remove any trailing characters (like newline)
			return number;
		}
	}
}

/**
 * @brief Calculates the sum of numbers entered by the user.
 *
 * Only numbers less than or equal to SUM_THRESHOLD are included in the sum.
 *
 * Numbers greater than SUM_THRESHOLD are skipped but still count toward the
 * total number of inputs requested.
 *
 * @param size The number of numbers to be entered.
 * @return The sum of the entered numbers (excluding those > SUM_THRESHOLD).
 */
int sumNumbers(const int size) {

	int sum = 0;
	int number;

	for (int i = 0; i < size; i++)
	{
		number = validateIntegerInRange("Enter number " + to_string(i + 1) + " : ", MIN_INPUT, MAX_INPUT);

		if (number > SUM_THRESHOLD)
		{
			cout << "Number " << number << " exceeds threshold (" << SUM_THRESHOLD << ") and will be skipped.\n\n";

			continue;
		}

		sum += number;
	}

	return sum;
}

int main()
{
	int sum = sumNumbers(SIZE);

	printSeparator();
	cout << "Sum of numbers is " << sum << '\n';
	printSeparator();

	return 0;
}