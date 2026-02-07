
#include <iostream>
#include <string>

using namespace std;

/**
 * @enum LetterCase
 * @brief An enumeration type to represent the case of letters.
 *        CAPITAL represents uppercase letters and SMALL represents lowercase letters.
 */
enum class LetterCase { CAPITAL, SMALL };

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
 * @brief Prints all possible pairs of letters in the specified case.
 *
 * @param letterCase The case of the letters. Default is CAPITAL.
 */
void printLetterPairs(LetterCase letterCase = LetterCase::CAPITAL) {

	int start = (letterCase == LetterCase::CAPITAL) ? 'A' : 'a';
	int end = (letterCase == LetterCase::CAPITAL) ? 'Z' : 'z';

	for (int i = start; i <= end; ++i) {
		cout << "Letter : " << char(i) << '\n';

		for (int j = start; j <= end; ++j) {
			cout << char(i) << char(j) << '\n';
		}

		printSeparator();
	}
}

/**
 * @brief Prints all possible pairs of letters in the specified case.
 *        This version uses char instead of int for the loop variables.
 *
 * @param letterCase The case of the letters. Default is CAPITAL.
 */
void printLetterPairsEnhanced(LetterCase letterCase = LetterCase::CAPITAL) {

	char start = (letterCase == LetterCase::CAPITAL) ? 'A' : 'a';
	char end = (letterCase == LetterCase::CAPITAL) ? 'Z' : 'z';

	for (char i = start; i <= end; ++i) {
		cout << "Letter : " << i << '\n';

		for (char j = start; j <= end; ++j) {
			cout << i << j << '\n';
		}

		printSeparator();
	}
}

int main() {

	// Print capital letter pairs using both approaches
	cout << "Capital Letter Pairs (int approach):\n";
	printSeparator('=');
	printLetterPairs(LetterCase::CAPITAL);

	cout << "\nCapital Letter Pairs (char approach):\n";
	printSeparator('=');
	printLetterPairsEnhanced(LetterCase::CAPITAL);

	// Print small letter pairs using both approaches
	cout << "\nSmall Letter Pairs (int approach):\n";
	printSeparator('=');
	printLetterPairs(LetterCase::SMALL);

	cout << "\nSmall Letter Pairs (char approach):\n";
	printSeparator('=');
	printLetterPairsEnhanced(LetterCase::SMALL);

	return 0;
}