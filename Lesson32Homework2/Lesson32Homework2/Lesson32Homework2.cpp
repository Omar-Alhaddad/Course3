
#include <iostream>
#include <string>
using namespace std;

void printSquareOfStars() {

	// Square Of Stars
	cout << "********\n";
	cout << "********\n";
	cout << "********\n";
	cout << "********\n";
}

void printSquareOfStarsNestedLoops(int rows = 4, int cols = 8, char fillChar = '*') {

	// Square Of Stars Using Nested Loops
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			cout << fillChar;
		}
		cout << '\n';
	}
}

void printSeparatorLine(int length = 20, char sepChar = '_') {

	// Separator Line
	cout << string(length, sepChar) << "\n\n";
}

int main()
{
	printSquareOfStarsNestedLoops(4, 8, '#');
	printSeparatorLine();
	printSquareOfStars();

	return 0;
}