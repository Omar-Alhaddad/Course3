
#include <iostream>
#include <string>

using namespace std;

enum class LetterCase { Upper, Lower };

void printSeparator(char fillChar = '-', int length = 50) {

	cout << string(length, fillChar) << '\n';
}

void printCapitalLetters() {

	for (char i = 'A'; i <= 'Z'; i++)
	{
		cout << i << '\n';
	}
}

void printSmallLetters() {

	for (char i = 'a'; i <= 'z'; i++)
	{
		cout << i << '\n';
	}
}

void printLettersEnum(LetterCase letterCase = LetterCase::Upper) {

	char start = (letterCase == LetterCase::Upper) ? 'A' : 'a';
	char end = (letterCase == LetterCase::Upper) ? 'Z' : 'z';

	for (char i = start; i <= end; i++)
	{
		cout << i << '\n';
	}
}

void printLettersBool(bool isUpperCase = true) {

	char start = (isUpperCase) ? 'A' : 'a';
	char end = (isUpperCase) ? 'Z' : 'z';

	for (char i = start; i <= end; i++)
	{
		cout << i << '\n';
	}
}

int main()
{
	// Program that prints all letters from A to Z in both uppercase and lowercase
	printCapitalLetters();

	printSeparator();

	printSmallLetters();

	printSeparator('*');

	printLettersBool();

	printSeparator();

	printLettersBool(false);

	printSeparator('*');

	printLettersEnum();

	printSeparator();

	printLettersEnum(LetterCase::Lower);

	return 0;
}