
#include <iostream>
#include <string>
#include <limits>
#include <chrono>
#include <iomanip>
#include <cmath>
#include <stdexcept>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using namespace boost::multiprecision;

constexpr int MIN_EXPONENT = 0;
constexpr int MIN_INPUT = 1;
constexpr int MAX_INPUT = INT_MAX;
constexpr int SEPARATOR_LENGTH = 50;
constexpr char SEPARATOR_CHAR = '-';

/**
 * @brief Clears the input buffer to handle invalid input.
 */
void clearInputBuffer() {

	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

/**
 * Prints a separator line
 * @param fillChar Character to fill the line with (default: '-')
 * @param length Length of the separator line (default: 50)
 */
void printSeparator(char fillChar = SEPARATOR_CHAR, int length = SEPARATOR_LENGTH) {

	cout << string(length, fillChar) << '\n';
}

/**
 * Prompts the user for a positive integer within a specified range
 * @param prompt Prompt to display to the user
 * @param minValue Minimum value allowed
 * @param maxValue Maximum value allowed
 * @return The user's input as an integer
 */
int validatePositiveInteger(const string& prompt, int minValue, int maxValue) {

	int number;

	while (true)
	{
		cout << prompt;

		if (!(cin >> number))
		{
			clearInputBuffer();

			cout << "Invalid input! Please enter a valid number.\n\n";
		}
		else if (number < minValue || number > maxValue)
		{
			clearInputBuffer();

			cout << "Invalid input! Number must be between " << minValue << " and " << maxValue << "\n\n";
		}
		else
		{
			clearInputBuffer();
			return number;
		}
	}
}

/**
 * Prints the result of a function and its execution time
 * @param methodName The name of the function
 * @param function The function to be executed
 * @param args The arguments to be passed to the function
 * @tparam Func The type of the function
 * @tparam Args The types of the arguments
 */
template<typename Func, typename... Args>
void timeFunction(const string& methodName, Func&& function, Args&&... args) {

	auto start = chrono::high_resolution_clock::now();
	auto result = function(forward<Args>(args)...);
	auto end = chrono::high_resolution_clock::now();

	auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);

	cout << left << setw(31) << methodName << ": " << right << setw(12) << result
		<< "  (Time: " << setw(6) << duration.count() << " ns)\n";
}

/**
 * Calculates base^exponent using exponentiation by squaring (bit manipulation)
 * @param base The base number
 * @param exponent The exponent (non-negative)
 * @return base^exponent as cpp_int (exact result)
 * @complexity O(log n) where n is the exponent
 */
cpp_int fastPower(int base, unsigned int exponent) {

	if (base == 1 || exponent == 0) return 1;
	if (base == 0) return 0;

	cpp_int result = 1;
	cpp_int currentBase = static_cast<cpp_int>(base);

	// Process each bit of the exponent
	while (exponent > 0)
	{
		// If current bit is 1, multiply result by current base
		if (exponent & 1) // Check if least significant bit is 1
		{
			result *= currentBase;
		}

		// Square the base for next bit position
		currentBase *= currentBase;

		// Right shift to process next bit
		exponent >>= 1;  // Divide exponent by 2
	}

	return result;
}

/**
 * Calculates base^exponent using exponentiation by squaring without bit operations
 * @param base The base number
 * @param exponent The exponent (non-negative)
 * @return base^exponent as cpp_int (exact result)
 * @complexity O(log n) where n is the exponent
 */
cpp_int powerOptimized(int base, unsigned int exponent) {

	if (base == 1 || exponent == 0) return 1;
	if (base == 0) return 0;

	cpp_int result = 1;
	cpp_int currentBase = static_cast<cpp_int>(base);

	// Similar to fastPower but without bit operations
	while (exponent > 0)
	{
		if (exponent % 2 == 1)
		{
			result *= currentBase;
		}

		currentBase *= currentBase;
		exponent /= 2;
	}

	return result;
}

/**
 * Calculates base^exponent using simple iterative multiplication
 * @param base The base number
 * @param exponent The exponent (non-negative)
 * @return base^exponent as cpp_int (exact result)
 * @complexity O(n) where n is the exponent
 */
cpp_int iterativePower(int base, unsigned int exponent) {

	if (base == 1 || exponent == 0) return 1;
	if (base == 0) return 0;

	cpp_int result = 1;

	unsigned int i = 0;

	while (i < exponent)
	{
		result *= base;

		++i;
	}

	return result;
}

/**
 * Calculates base^exponent using optimized iterative multiplication
 * Computes base^(n/2) then squares it, with one extra multiply if n is odd
 * @param base The base number
 * @param exponent The exponent (non-negative)
 * @return base^exponent as cpp_int (exact result)
 * @complexity O(n/2) where n is the exponent
 * @note This method now gives exact results with cpp_int!
 */
cpp_int iterativePowerEnhanced(int base, unsigned int exponent) {

	if (base == 1 || exponent == 0) return 1;
	if (base == 0) return 0;

	cpp_int result = 1;

	int halfExponent = exponent / 2;

	int i = 0;

	while (i < halfExponent)
	{
		result *= base;

		++i;
	}

	if (exponent % 2 == 0)
	{
		return result * result;
	}
	else
	{
		return result * result * base;
	}
}

/**
 * Calculates 2^exponent using bit shift operation
 * @param exponent The exponent
 * @return 2^exponent as cpp_int (exact result)
 * @complexity O(1)
 */
cpp_int powerOfTwo(unsigned int exponent) {

	cpp_int bit = 1;

	return (bit << exponent);
}

/**
 * Calculates base^exponent using recursive approach
 * @param base The base number
 * @param exponent The exponent (non-negative)
 * @return base^exponent as cpp_int (exact result)
 * @note Uses exponentiation by squaring recursively
 * @complexity O(log n) where n is the exponent
 */
cpp_int recursivePower(int base, unsigned int exponent) {

	if (exponent == 0) return 1;
	if (exponent == 1) return static_cast<cpp_int>(base);

	cpp_int half = recursivePower(base, exponent / 2);

	if (exponent % 2 == 0)
	{
		return half * half;
	}
	else
	{
		return half * half * base;
	}
}

/**
 * Displays power calculation results using all available methods
 * @param base The base number
 * @param exponent The exponent
 */
void displayPowerResults(int base, unsigned int exponent) {

	printSeparator();

	cout << fixed << setprecision(0);

	cout << "\nFast Power (Bit Manipulation): " << base << "^" << exponent << " = " << fastPower(base, exponent) << endl;
	printSeparator();

	cout << "\nPower Optimized: " << base << "^" << exponent << " = " << powerOptimized(base, exponent) << endl;
	printSeparator();

	cout << "\nIterative Power: " << base << "^" << exponent << " = " << iterativePower(base, exponent) << endl;
	printSeparator();

	cout << "\nIterative Power (Enhanced): " << base << "^" << exponent << " = " << iterativePowerEnhanced(base, exponent) << endl;
	printSeparator();

	cout << "\nRecursive Power: " << base << "^" << exponent << " = " << recursivePower(base, exponent) << endl;
	printSeparator();

	cout << "\nStandard Library (pow) [Approximate]: " << base << "^" << exponent << " = " << pow(base, exponent) << endl;
	printSeparator();

	if (base == 2)
	{
		cout << "\nBit Shift (Power of Two): " << base << "^" << exponent << " = " << powerOfTwo(exponent) << endl;
		printSeparator();
	}
}

/**
 * Displays the performance comparison of different power calculation methods.
 *
 * @param base The base number used for power calculation.
 * @param exponent The exponent used for power calculation.
 */
void displayTimeFunction(int base, unsigned int exponent) {

	cout << "\n=== Performance Comparison ===\n";
	printSeparator('=');

	// Performance Comparison of Different Power Calculation Methods
	timeFunction("Fast Power (Bit Manipulation)", fastPower, base, exponent);

	timeFunction("Power Optimized", powerOptimized, base, exponent);

	timeFunction("Iterative Power", iterativePower, base, exponent);

	timeFunction("Iterative Power (Enhanced)", iterativePowerEnhanced, base, exponent);

	timeFunction("Recursive Power", recursivePower, base, exponent);

	timeFunction("Standard Library pow() [Approximate]", [](int b, unsigned int e) { return pow(b, e); }, base, exponent);

	// timeFunction("Iterative Power", pow, base, exponent);
	if (base == 2)
	{
		timeFunction("Bit Shift (Power of Two)", powerOfTwo, exponent);
	}

	printSeparator();
}

int main()
{
	// Calculate the Power of a Number From User Input
	try
	{
		printSeparator('=');
		cout << "  Welcome to the Exact Power Calculator!\n";
		cout << "  All results are EXACT with no rounding!\n";
		printSeparator('=');

		int base = validatePositiveInteger("Enter the number: ", MIN_INPUT, MAX_INPUT);
		int exponent = validatePositiveInteger("Enter the power to raise the number to: ", MIN_EXPONENT, MAX_INPUT);

		displayPowerResults(base, exponent);

		displayTimeFunction(base, exponent);
	}
	catch (const exception& e)
	{
		cerr << "\nError: " << e.what() << '\n';
		return 1;
	}

	return 0;
}