
#include <iostream>
using namespace std;

void printH(char fillChar = '*') {

	// H Shaped Stars
	const string  space = string(3, ' ');

	cout << fillChar << space << fillChar << "\n"
		<< fillChar << space << fillChar << "\n"
		<< string(5, fillChar) << '\n'
		<< fillChar << space << fillChar << "\n"
		<< fillChar << space << fillChar << "\n";
}

void printHNestedLoops(char fillChar = '*') {

	// H Shaped Stars using Nested Loops
	string output;
	output.reserve(30); // Reserve space to avoid multiple allocations

	for (int row = 1; row <= 5; ++row)
	{
		for (int col = 1; col <= 5; ++col)
		{
			if (col == 1 || col == 5 || row == 3)
			{
				output += fillChar;
			}
			else
			{
				output += ' ';
			}
		}
		output += '\n';
	}
	cout << output;
}

void printSeparatorLine(int length = 20, char sepChar = '_') {

	// Separator Line
	cout << string(length, sepChar) << "\n\n";
}

int main()
{
	printH();
	printSeparatorLine(10);
	printHNestedLoops();

	return 0;
}