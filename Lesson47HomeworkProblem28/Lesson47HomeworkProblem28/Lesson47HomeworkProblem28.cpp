
#include <iostream>
#include <string>
#include <limits>
#include <chrono>
#include <iomanip>

using namespace std;

// Clears the input buffer to handle invalid input
void clearInputBuffer() {

	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

/**
 * Prints a separator line
 * @param fillChar Character to fill the line with (default: '-')
 * @param length Length of the separator line (default: 50)
 */
void printSeparator(char fillChar = '-', int length = 50) {

	cout << string(length, fillChar) << '\n';
}

/**
 * Validates and returns a positive integer from user input
 * @param prompt Message to display to the user
 * @return A positive integer entered by the user
 */
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

template<typename Func>
void timeFunction(const string& methodName, Func function, int N) {

	auto start = chrono::high_resolution_clock::now();
	long long result = function(N);
	auto end = chrono::high_resolution_clock::now();

	auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

	cout << left << setw(31) << methodName << ": " << right << setw(12) << result
		<< "  (Time: " << setw(6) << duration.count() << " microseconds)\n";
}

// Method 1: Loop through all numbers and check for odd using modulus operator
long long sumOddNumbersLoop(int N) {

	long long sum = 0;

	for (int i = 1; i <= N; ++i)
	{
		// Check if i is odd using modulus operator
		if (i % 2 == 1)
		{
			sum += i;
		}
	}

	return sum;
}

// Method 2: Loop through odd numbers only 
long long sumOddNumbersLoopEnhanced(int N) {

	long long sum = 0;

	// Start at 1 and increment by 2 to only visit odd numbers
	for (int i = 1; i <= N; i += 2)
	{
		sum += i;
	}

	return sum;
}

// Method 3: Mathematical formula to calculate sum of odd numbers (most efficient)
long long sumOddNumbersFormula(int N) {

	// Formula: sum of first k odd numbers = k²
	// where k = number of odd numbers from 1 to N
	long long count = (N + 1) / 2;  // Number of odd numbers from 1 to N

	return count * count;
}

// Method 4: Loop through all numbers and check for odd using bitwise operator
long long sumOddNumbersBitwiseOperator(int N) {

	long long sum = 0;

	for (int i = 1; i <= N; ++i)
	{
		// Bitwise AND with 1: if least significant bit is 1, number is odd
		// Example: 5 (binary: 101) & 1 (binary: 001) = 1 (odd)
		//          4 (binary: 100) & 1 (binary: 001) = 0 (even)
		if ((i & 1) == 1)
		{
			sum += i;
		}
	}

	return sum;
}

int main()
{
	// program sum odd numbers from 1 to N. Using four methods to check for odd numbers 
	int number = validatePositiveNumber("Enter a positive number N : ");

	printSeparator('=', 60);
	cout << "Calculating sum of odd numbers from 1 to " << number << '\n';
	printSeparator('=', 60);

	cout << "Sum of odd numbers using modulus operator: " << sumOddNumbersLoop(number) << '\n';
	cout << "Sum of odd numbers by looping through odd numbers only: " << sumOddNumbersLoopEnhanced(number) << '\n';
	cout << "Sum of odd numbers using mathematical formula: " << sumOddNumbersFormula(number) << '\n';
	cout << "Sum of odd numbers using bitwise operator: " << sumOddNumbersBitwiseOperator(number) << '\n';

	printSeparator('-', 60);

	cout << "PERFORMANCE COMPARISON:\n";
	timeFunction("Method 1 (Modulus operator)", sumOddNumbersLoop, number);
	timeFunction("Method 2 (Loop odd only)", sumOddNumbersLoopEnhanced, number);
	timeFunction("Method 3 (Mathematical formula)", sumOddNumbersFormula, number);
	timeFunction("Method 4 (Bitwise AND)", sumOddNumbersBitwiseOperator, number);

	printSeparator('=', 60);

	return 0;
}