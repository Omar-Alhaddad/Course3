
#include <iostream>
#include <string>
#include <limits>

using namespace std;

void clearInputBuffer() {

	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void printSeparator(char fillChar = '-', int length = 50) {

	cout << string(length, fillChar) << '\n';
}

int validatePositiveNumber(const string& prompt) {

	int number;

	while (true)
	{
		cout << prompt;

		if (!(cin >> number))
		{
			clearInputBuffer();

			cout << "Invalid input! Please enter a valid number.\n\n";
		}
		else if (number <= 0)
		{
			clearInputBuffer();

			cout << "Invalid input! Number must be positive (greater than 0).\n\n";
		}
		else
		{
			clearInputBuffer();
			return number;
		}
	}
}

void printNumbers(int N) {

	for (int i = 1; i <= N; ++i)
	{
		cout << i << '\n';
	}

	cout << flush;
}

int main()
{
	// program prints numbers from 1 to N, where N is a positive integer provided by the user
	int number = validatePositiveNumber("Enter a positive number to count to: ");

	printSeparator();

	printNumbers(number);

	return 0;
}