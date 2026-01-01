
#include <iostream>
#include <string>
#include <limits>
using namespace std;

// ============ INPUT FUNCTIONS ============
int readNumber(const string& prompt) {

	int number;

	cout << prompt;
	cin >> number;

	if (cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << "Invalid input! Please enter a valid number.\n";

		return readNumber(prompt);
	}

	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return number;
}

// ============ DISPLAY FUNCTIONS ============
void displayNumber(const string& prompt, int num) {

	cout << prompt << num << endl;
}

void printSeparator(char fillchar = '-', int length = 50) {

	cout << string(length, fillchar) << endl;
}

// ============ SWAP FUNCTIONS ============
void swapNumbers(int& num1, int& num2) {

	int temp = num1;
	num1 = num2;
	num2 = temp;
}

void swapNumbersXOR(int& num1, int& num2) {
	// XOR Swap: Uses bitwise XOR to swap without temporary variable
	// Works because: A XOR B XOR B = A
	// Limitation: Slower than temp variable on modern CPUs

	if (&num1 == &num2)
	{
		return;
	}

	num1 ^= num2;
	num2 ^= num1;
	num1 ^= num2;
}

void swapNumbersNoTemp(int& num1, int& num2) {
	// Arithmetic Swap: Uses addition/subtraction to swap
	// WARNING: Can cause integer overflow with large numbers!
	// Example: INT_MAX + 1 causes overflow

	if (&num1 == &num2)
	{
		return;
	}

	num1 = num1 + num2;
	num2 = num1 - num2;
	num1 = num1 - num2;
}

void demonstrateSwapMethods(const string& method, void (*swapFunction)(int&, int&)) {

	cout << "Welcome to Swaps Two Numbers Using " << method << "\n\n";

	// Get input from user
	int number1 = readNumber("Please enter the first number: ");
	int number2 = readNumber("Please enter the second number: ");

	// Display original values
	printSeparator();
	displayNumber("First number: ", number1);
	displayNumber("Second number: ", number2);

	// Swap the numbers
	swapFunction(number1, number2);

	// Display swapped values
	printSeparator();
	displayNumber("First number: ", number1);
	displayNumber("Second number: ", number2);
	printSeparator('*');
}

int main()
{
	// Swaps Two Numbers Using a Temporary Variable
	demonstrateSwapMethods("a Temporary Variable!", swapNumbers);

	// Swaps Two Numbers Using XOR Bitwise Operator
	demonstrateSwapMethods("XOR Bitwise Operator", swapNumbersXOR);

	//  Swaps Two Numbers Using Arithmetic Operations 
	demonstrateSwapMethods("Arithmetic Operations", swapNumbersNoTemp);

	return 0;
}