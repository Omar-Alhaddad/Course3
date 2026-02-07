
#include <iostream>
#include <string>
#include <limits>

using namespace std;

constexpr char MIN_CAPITAL_INPUT = 'A';
constexpr char MAX_CAPITAL_INPUT = 'Z';
constexpr char MIN_SMALL_INPUT = 'a';
constexpr char MAX_SMALL_INPUT = 'z';

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
 * @brief Validates character input within a specified range.
 *
 * @param prompt The message to display to the user.
 * @param minValue The minimum acceptable character value.
 * @param maxValue The maximum acceptable character value.
 * @return char The validated character input.
 */
char validateCharacter(const string& prompt, char minValue, char maxValue) {

	char character;

	while (true)
	{
		cout << prompt;

		if (!(cin >> character))
		{
			clearInputBuffer();

			cout << "Invalid input! Please enter a valid Character.\n\n";
		}
		else if (character < minValue || character > maxValue)
		{
			clearInputBuffer();

			cout << "Invalid input! Character must be between (" << minValue << " - " << maxValue << ").\n\n";
		}
		else
		{
			clearInputBuffer();
			return character;
		}
	}
}

/**
 * @brief Prints a triangle pattern of letters up to the specified end letter.
 *
 * @param endLetter The last letter to include in the triangle.
 */
void printLetterTriangle(char endLetter) {

	char startLetter;

	if (endLetter >= MIN_CAPITAL_INPUT && endLetter <= MAX_CAPITAL_INPUT)
	{
		startLetter = 'A';
	}
	else if (endLetter >= MIN_SMALL_INPUT && endLetter <= MAX_SMALL_INPUT)
	{
		startLetter = 'a';
	}
	else
	{	// Default for invalid input
		startLetter = 'A';
		endLetter = 'F';
	}

	for (char i = startLetter; i <= endLetter; ++i)
	{
		for (char j = startLetter; j <= i; ++j)
		{
			cout << j << ' ';
		}

		cout << '\n';
	}

}

int main()
{
	char character = validateCharacter("Enter a Capital Letter: ", MIN_CAPITAL_INPUT, MAX_CAPITAL_INPUT);

	printSeparator();

	printLetterTriangle(character);

	printSeparator();

	character = validateCharacter("Enter a Small Letter: ", MIN_SMALL_INPUT, MAX_SMALL_INPUT);

	printSeparator();

	printLetterTriangle(character);

	return 0;
}