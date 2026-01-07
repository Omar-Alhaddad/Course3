
#include <iostream>
#include <string>
#include <limits>

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

// Fast power calculation using bit manipulation (exponentiation by squaring)
// Time complexity: O(log n) instead of O(n)
long long fastPower(int base, int exponent) {

	if (exponent == 0 || base == 1) return 1;
	if (exponent == 1) return base;
	if (base == 0) return 0;

	long long result = 1;
	long long currentBase = base;

	// Process each bit of the exponent
	while (exponent > 0) {
		// If current bit is 1, multiply result by current base
		if (exponent & 1) {  // Check if least significant bit is 1
			result *= currentBase;
		}

		// Square the base for next bit position
		currentBase *= currentBase;

		// Right shift to process next bit
		exponent >>= 1;  // Divide exponent by 2
	}

	return result;
}

long long power(int base, int exponent) {

	if (base == 1 || exponent == 0) return 1;
	if (base == 0) return 0;
	if (exponent == 1) return base;

	long long result = 1;
	for (int i = 0; i < exponent; i++)
	{
		result *= base;
	}

	return result;
}

long long powerOfTwo(int exponent) {

	if (exponent >= 63) {

		throw overflow_error("Exponent too large for bit shift");
	}

	return 1ll << exponent;
}

void printSeparator(char fillchar = '-', int length = 50) {

	cout << '\n' << string(length, fillchar) << '\n';
}

void displayPower(int number, int exponent) {

	if (number == 2)
	{
		cout << "\nThe result of " << number << "^" << exponent << " is : " << powerOfTwo(exponent) << endl;
	}

	printSeparator();
	cout << "\nThe result of " << number << "^" << exponent << " is : " << fastPower(number, exponent) << endl;
	printSeparator();
	cout << "\nThe result of " << number << "^" << exponent << " is : " << power(number, exponent) << endl;
}

int main()
{
	// Calculate the Power of a Number From User Input
	cout << "Welcome to the Power Calculator!\n\n";

	int number = validatePositiveInteger("Enter the number: ");
	int exponent = validatePositiveInteger("Enter the power to raise the number to: ");

	displayPower(number, exponent);

	return 0;
}