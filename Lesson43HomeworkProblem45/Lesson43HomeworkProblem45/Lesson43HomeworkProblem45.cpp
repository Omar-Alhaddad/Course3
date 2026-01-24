
#include <iostream>
#include <string>
#include <limits> 

using namespace std;

constexpr int MIN_MONTH = 1;
constexpr int MAX_MONTH = 12;

enum class Months : int { January = 1, February, March, April, May, June, July, August, September, October, November, December };

void printSeparator(char fillChar = '-', int length = 50) {

	cout << string(length, fillChar) << endl;
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

string monthsToString(int monthNumber) {

	Months monthEnum = static_cast<Months>(monthNumber);

	if (monthEnum == Months::January)
	{
		return "January";
	}
	else if (monthEnum == Months::February)
	{
		return "February";
	}
	else if (monthEnum == Months::March)
	{
		return "March";
	}
	else if (monthEnum == Months::April)
	{
		return "April";
	}
	else if (monthEnum == Months::May)
	{
		return "May";
	}
	else if (monthEnum == Months::June)
	{
		return "June";
	}
	else if (monthEnum == Months::July)
	{
		return "July";
	}
	else if (monthEnum == Months::August)
	{
		return "August";
	}
	else if (monthEnum == Months::September)
	{
		return "September";
	}
	else if (monthEnum == Months::October)
	{
		return "October";
	}
	else if (monthEnum == Months::November)
	{
		return "November";
	}
	else if (monthEnum == Months::December)
	{
		return "December";
	}
	else
	{
		return "Wrong Month";
	}
}

string monthsToStringByArray(int monthNumber) {

	static constexpr const char* months[] = { "Wrong Month", "January" , "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

	return (monthNumber >= MIN_MONTH && monthNumber <= MAX_MONTH) ? months[monthNumber] : months[0];
}

int main()
{
	// Program to display month name based on month number using enum class and array
	int monthNumber = validateIntegerInRange("Enter month number (1-12): ", MIN_MONTH, MAX_MONTH);

	printSeparator();

	cout << monthsToString(monthNumber) << '\n';

	printSeparator();

	cout << monthsToStringByArray(monthNumber) << '\n';

	return 0;
}