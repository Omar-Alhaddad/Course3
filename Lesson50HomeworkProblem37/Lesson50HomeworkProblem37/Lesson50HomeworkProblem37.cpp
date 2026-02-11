
#include <iostream>
#include <string>
#include <limits>
#include <iomanip>

using namespace std;

constexpr int SEPARATOR_LENGTH = 50;
constexpr char SEPARATOR_CHAR = '-';
constexpr int STOP_NUMBER = -99;

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
 * Prompts the user for an integer value
 * @param prompt Prompt to display to the user
 * @return The user's input as an integer
 */
int readInteger(const string& prompt) {

	int number;

	while (true)
	{
		cout << prompt;

		if (!(cin >> number))
		{
			clearInputBuffer();

			cout << "Invalid input! Please enter a valid number.\n\n";
		}
		else
		{
			clearInputBuffer();
			return number;
		}
	}
}

/**
 * @brief Calculates the sum of numbers entered by the user until a stop number is entered.
 *
 * @param prompt The prompt to display to the user.
 * @param stopNumber The number that, when entered, will stop the loop and return the sum.
 * @return The sum of all numbers entered by the user.
 */
long long sumNumbers(const string& prompt, int stopNumber = STOP_NUMBER) {

	long long sum = 0;
	int number;

	while (true)
	{
		number = readInteger(prompt);

		if (number == stopNumber)
		{
			break;
		}

		sum += number;
	}

	return sum;
}

int main()
{
	// Program to calculate the sum of numbers entered by the user until -99 is entered
	cout << "Enter numbers to sum (enter " << STOP_NUMBER << " to finish):\n";

	printSeparator();

	long long sum = sumNumbers("Enter number: ");

	printSeparator();

	cout << "Sum of numbers: " << sum << '\n';

	return 0;
}