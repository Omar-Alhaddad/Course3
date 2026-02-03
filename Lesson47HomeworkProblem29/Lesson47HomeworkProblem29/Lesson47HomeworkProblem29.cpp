
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

// Method 1: Loop through all numbers and check for even using modulus operator
long long sumEvenNumbersLoop(int N) {

	long long sum = 0;

	for (int i = 1; i <= N; ++i)
	{
		// Check if i is even using modulus operator
		if (i % 2 == 0)
		{
			sum += i;
		}
	}

	return sum;
}

// Method 2: Loop through even numbers only 
long long sumEvenNumbersLoopEnhanced(int N) {

	long long sum = 0;

	// Start at 2 and increment by 2 to only visit even numbers
	for (int i = 2; i <= N; i += 2)
	{
		sum += i;
	}

	return sum;
}

// Method 3: Mathematical formula to calculate sum of even numbers (most efficient)
long long sumEvenNumbersFormula(int N) {

	// Formula: sum of first k even numbers = k(k + 1) = k² + k
	// where k = floor(N/2) = number of even numbers from 1 to N
	long long count = N / 2;  // Number of even numbers from 1 to N

	return (count * count) + count;
}

// Method 4: Loop through all numbers and check for even using bitwise operator
long long sumEvenNumbersBitwiseOperator(int N) {

	long long sum = 0;

	for (int i = 1; i <= N; ++i)
	{
		// Bitwise AND with 1: if least significant bit is 0, number is even
		// Example: 5 (binary: 101) & 1 (binary: 001) = 1 (odd)
		//          4 (binary: 100) & 1 (binary: 001) = 0 (even)
		if ((i & 1) == 0)
		{
			sum += i;
		}
	}

	return sum;
}

int main()
{
	// program sum even numbers from 1 to N. Using four methods to check for even numbers 
	int number = validatePositiveNumber("Enter a positive number N : ");

	printSeparator('=', 60);
	cout << "Calculating sum of even numbers from 1 to " << number << '\n';
	printSeparator('=', 60);

	cout << "Sum of even numbers using modulus operator: " << sumEvenNumbersLoop(number) << '\n';
	cout << "Sum of even numbers by looping through even numbers only: " << sumEvenNumbersLoopEnhanced(number) << '\n';
	cout << "Sum of even numbers using mathematical formula: " << sumEvenNumbersFormula(number) << '\n';
	cout << "Sum of even numbers using bitwise operator: " << sumEvenNumbersBitwiseOperator(number) << '\n';

	printSeparator('-', 60);

	cout << "PERFORMANCE COMPARISON:\n";
	timeFunction("Method 1 (Modulus operator)", sumEvenNumbersLoop, number);
	timeFunction("Method 2 (Loop even only)", sumEvenNumbersLoopEnhanced, number);
	timeFunction("Method 3 (Mathematical formula)", sumEvenNumbersFormula, number);
	timeFunction("Method 4 (Bitwise AND)", sumEvenNumbersBitwiseOperator, number);

	printSeparator('=', 60);

	return 0;
}