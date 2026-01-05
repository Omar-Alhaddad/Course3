
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <cmath>
using namespace std;

int validatePositiveInteger(const string& prompt) {

	int number;

	while (true)
	{
		cout << prompt;

		if (!(cin >> number))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "Invalid input! Please enter a valid number.\n\n";
		}
		else if (number <= 0)
		{
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "Invalid input! Number must be positive.\n\n";
		}
		else
		{
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			return number;
		}
	}
}

int squarePower(int number) {

	return number * number;
}

int cubePower(int number) {

	return number * number * number;
}

int fourthPower(int number) {

	return number * number * number * number;
}

void printSeparator(char fillchar = '-', int length = 50) {

	cout << '\n' << string(length, fillchar) << '\n';
}

void displayPower(int number) {

	cout << "\nSquare power of the number is: " << squarePower(number);
	cout << "\nCube power of the number is: " << cubePower(number);
	cout << "\nFourth power of the number is: " << fourthPower(number);
	printSeparator();
}

int main()
{
	// calculate the Square, Cube, and Fourth Power of a Number
	cout << "Welcome to the Square, Cube, and Fourth Power Calculator!\n\n";

	int number = validatePositiveInteger("Enter the number: ");

	displayPower(number);

	return 0;
}