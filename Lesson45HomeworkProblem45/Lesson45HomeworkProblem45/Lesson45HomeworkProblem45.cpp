
#include <iostream>
#include <string>
#include <string_view>
#include <limits> 

using namespace std;

constexpr int MIN_MONTH = 1;
constexpr int MAX_MONTH = 12;

enum class Months : int { January = 1, February, March, April, May, June, July, August, September, October, November, December };

void printSeparator(char fillChar = '-', int length = 50) {

	cout << string(length, fillChar) << '\n';
}

void clearInputBuffer() {

	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int validateIntegerInRange(const string& prompt, int minValue, int maxValue) {

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

			cout << "Invalid month! Number must be between " << minValue << " and " << maxValue << "\n\n";
		}
		else
		{
			clearInputBuffer();
			return number;
		}
	}
}

// Approach 1: Using switch statement with enum class
string monthsToString(int monthNumber) {

	Months monthEnum = static_cast<Months>(monthNumber);

	switch (monthEnum)
	{
	case Months::January:
		return "January";
	case Months::February:
		return "February";
	case Months::March:
		return "March";
	case Months::April:
		return "April";
	case Months::May:
		return "May";
	case Months::June:
		return "June";
	case Months::July:
		return "July";
	case Months::August:
		return "August";
	case Months::September:
		return "September";
	case Months::October:
		return "October";
	case Months::November:
		return "November";
	case Months::December:
		return "December";
	default:
		return "Wrong Month";
	}
}

// Approach 2: Using array lookup
string_view getMonth(int monthNumber) {

	static constexpr string_view months[] = { "Wrong Month", "January" , "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

	return (monthNumber >= MIN_MONTH && monthNumber <= MAX_MONTH) ? months[monthNumber] : months[0];
}

int main()
{
	// Program to display month name based on month number using enum class and array
	int monthNumber = validateIntegerInRange("Enter month number (1-12): ", MIN_MONTH, MAX_MONTH);

	printSeparator();

	cout << monthsToString(monthNumber) << '\n';

	printSeparator();

	cout << getMonth(monthNumber) << '\n';

	return 0;
}