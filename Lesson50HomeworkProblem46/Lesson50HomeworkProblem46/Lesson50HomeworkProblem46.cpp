
#include <iostream>
#include <string>

using namespace std;

constexpr int SEPARATOR_LENGTH = 50;
constexpr char SEPARATOR_CHAR = '-';

/**
 * @enum LetterCase
 * @brief Enumerated type to represent the case of letters.
 * @details The LetterCase enum has two possible values: Upper and Lower.
 */
enum class LetterCase { Upper, Lower };

/**
 * Prints a separator line
 * @param fillChar Character to fill the line with (default: '-')
 * @param length Length of the separator line (default: 50)
 */
void printSeparator(const char fillChar = SEPARATOR_CHAR, const int length = SEPARATOR_LENGTH) {

	cout << string(length, fillChar) << '\n';
}

/**
 * @brief Prints all letters from A to Z in the specified case.
 * @param letterCase The case of the letters to print (default: LetterCase::Upper).
 */
void printLetters(const LetterCase letterCase = LetterCase::Upper) {

	const char start = (letterCase == LetterCase::Upper) ? 'A' : 'a';
	const char end = (letterCase == LetterCase::Upper) ? 'Z' : 'z';

	char i = start;

	while (i <= end)
	{
		cout << i << '\n';

		++i;
	}
}

int main()
{
	// Program that prints all letters from A to Z in both uppercase and lowercase
	printLetters(LetterCase::Upper);

	printSeparator();

	printLetters(LetterCase::Lower);

	return 0;
}