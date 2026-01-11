
#include <iostream>
#include <string>
#include <limits>
using namespace std;

// ============ INPUT FUNCTIONS ============
int readNumber(const string& prompt) {

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
		else
		{
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			return number;
		}
	}
}

// ============ DISPLAY FUNCTIONS ============
void displayNumber(const string& prompt, int num) {

	cout << prompt << num << '\n';
}

void printSeparator(char fillChar = '-', int length = 50) {

	cout << string(length, fillChar) << '\n';
}

// ============ SWAP FUNCTION ============
void swapNumbers(int& num1, int& num2) {

	int temp = num1;
	num1 = num2;
	num2 = temp;
}

int main()
{
	// Swaps Two Numbers Using a Temporary Variable
	cout << "Welcome to Swaps Two Numbers Using a Temporary Variable!" << "\n\n";

	// Get input from user
	int number1 = readNumber("Please enter the first number: ");
	int number2 = readNumber("Please enter the second number: ");

	// Display original values
	printSeparator();
	cout << "Before Swap:\n";
	displayNumber("First number: ", number1);
	displayNumber("Second number: ", number2);

	// Swap the numbers
	swapNumbers(number1, number2);

	// Display swapped values
	printSeparator();
	cout << "After Swap:\n";
	displayNumber("First number: ", number1);
	displayNumber("Second number: ", number2);

	return 0;
}