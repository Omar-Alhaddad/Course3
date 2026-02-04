
#include <iostream>
#include <string>
#include <limits>
#include <chrono>
#include <iomanip>
#include <cmath>
#include <stdexcept>

using namespace std;

constexpr int MIN_EXPONENT = 0;  // Add this
constexpr int MIN_INPUT = 1;
constexpr int MAX_INPUT = INT_MAX;
constexpr int SEPARATOR_LENGTH = 50;
constexpr char SEPARATOR_CHAR = '-';
constexpr int MAX_SAFE_EXPONENT_FOR_BITSHIFT = 63;

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
void printSeparator(char fillChar = SEPARATOR_CHAR, int length = SEPARATOR_LENGTH) {

	cout << string(length, fillChar) << '\n';
}

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

template<typename Func, typename... Args>
void timeFunction(const string& methodName, Func&& function, Args&&... args) {

	auto start = chrono::high_resolution_clock::now();
	long double result = function(forward<Args>(args)...);
	auto end = chrono::high_resolution_clock::now();

	auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);

	cout << left << setw(31) << methodName << ": " << right << setw(12) << result
		<< "  (Time: " << setw(6) << duration.count() << " ns)\n";
}

/**
 * Calculates base^exponent using exponentiation by squaring (bit manipulation)
 * @param base The base number
 * @param exponent The exponent (non-negative)
 * @return base^exponent as long double
 * @complexity O(log n) where n is the exponent
 */
long double fastPower(int base, unsigned int exponent) {

	if (exponent == 0 || base == 1) return 1.0L;
	if (base == 0) return 0.0L;

	long double result = 1.0L;
	long double currentBase = static_cast<long double>(base);

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

/**
 * Calculates base^exponent using exponentiation by squaring without bit operations
 * @param base The base number
 * @param exponent The exponent (non-negative)
 * @return base^exponent as long double
 * @complexity O(log n) where n is the exponent
 */
long double powerOptimized(int base, unsigned int exponent) {

	if (base == 1 || exponent == 0) return 1.0L;
	if (base == 0) return 0.0L;

	long double result = 1.0L;
	long double currentBase = static_cast<long double>(base);

	// Similar to fastPower but without bit operations
	while (exponent > 1) {

		if (exponent % 2 == 1) {
			result *= currentBase;
		}

		currentBase *= currentBase;
		exponent /= 2;
	}

	return result * currentBase;
}

/**
 * Calculates base^exponent using simple iterative multiplication
 * @param base The base number
 * @param exponent The exponent (non-negative)
 * @return base^exponent as long double
 * @complexity O(n) where n is the exponent
 */
long double iterativePower(int base, unsigned int exponent) {

	if (base == 1 || exponent == 0) return 1.0L;
	if (base == 0) return 0.0L;

	long double result = 1.0L;

	for (unsigned int i = 0; i < exponent; i++)
	{
		result *= base;
	}

	return result;
}

/**
 * Calculates base^exponent using optimized iterative multiplication
 * Computes base^(n/2) then squares it, with one extra multiply if n is odd
 * @param base The base number
 * @param exponent The exponent (non-negative)
 * @return base^exponent as long double
 * @complexity O(n/2) where n is the exponent
 * @note May be slower than regular iterative for small n due to overhead
 */
long double iterativePowerEnhanced(int base, unsigned int exponent) {

	if (base == 1 || exponent == 0) return 1.0L;
	if (base == 0) return 0.0L;

	long double result = 1.0L;
	int halfExponent = exponent / 2;

	for (int i = 0; i < halfExponent; i++)
	{
		result *= base;
	}

	return (exponent % 2 == 0) ? result * result : result * result * base;
}

/**
 * Calculates 2^exponent using bit shift operation
 * @param exponent The exponent (must be <= 63)
 * @return 2^exponent as long double
 * @throws overflow_error if exponent > 63
 * @complexity O(1)
 */
long double powerOfTwo(unsigned int exponent) {

	if (exponent > MAX_SAFE_EXPONENT_FOR_BITSHIFT) {

		throw overflow_error("Exponent too large for bit shift");
	}

	return static_cast<long double>(1ULL << exponent);
}

/**
 * Calculates base^exponent at compile time using constexpr
 * @param base The base number
 * @param exponent The exponent (non-negative)
 * @return base^exponent as long double
 * @note Uses exponentiation by squaring for efficiency
 * @complexity O(log n) where n is the exponent
 */
constexpr long double constexprPower(int base, unsigned int exponent) {

	if (exponent == 0) return 1.0L;
	if (exponent == 1) return static_cast<long double>(base);

	long double half = constexprPower(base, exponent / 2);
	return (exponent % 2 == 0) ? half * half : half * half * base;
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

	cout << "\nConstexpr Power (Compile-Time): " << base << "^" << exponent << " = " << constexprPower(base, exponent) << endl;
	printSeparator();

	cout << "\nStandard Library (pow): " << base << "^" << exponent << " = " << pow(base, exponent) << endl;
	printSeparator();

	if (base == 2 && exponent <= MAX_SAFE_EXPONENT_FOR_BITSHIFT)
	{
		cout << "\nBit Shift (Power of Two): " << base << "^" << exponent << " = " << powerOfTwo(exponent) << endl;
		printSeparator();
	}
}
void displayTimeFunction(int base, unsigned int exponent) {

	cout << "\n=== Performance Comparison ===\n";
	printSeparator('=');

	// Performance Comparison of Different Power Calculation Methods
	timeFunction("Fast Power (Bit Manipulation)", fastPower, base, exponent);

	timeFunction("Power Optimized", powerOptimized, base, exponent);

	timeFunction("Iterative Power", iterativePower, base, exponent);

	timeFunction("Iterative Power (Enhanced)", iterativePowerEnhanced, base, exponent);

	timeFunction("Constexpr Power (Compile-Time)", constexprPower, base, exponent);

	timeFunction("Standard Library pow()", [](int b, unsigned int e) { return pow(b, e); }, base, exponent);

	// timeFunction("Iterative Power", pow, base, exponent);
	if (base == 2 && exponent <= MAX_SAFE_EXPONENT_FOR_BITSHIFT)
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
		cout << "Welcome to the Power Calculator!\n\n";

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