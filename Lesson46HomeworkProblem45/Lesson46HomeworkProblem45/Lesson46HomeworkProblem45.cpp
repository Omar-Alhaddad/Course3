
#include <iostream>
#include <string>
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

Months readMonth(const string& prompt, int minValue, int maxValue) {

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
			return static_cast<Months>(number);
		}
	}
}

// Using switch statement with enum class
string getMonth(Months month) {

	switch (month)
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

void showMonthsMenu() {

	printSeparator('*');
	cout << "\t\tMONTHS OF YEAR\n";
	printSeparator('*');
	cout << "  (1)  January                   (7) July\n";
	cout << "  (2)  February                  (8) August\n";
	cout << "  (3)  March                     (9) September\n";
	cout << "  (4)  April                     (10) October\n";
	cout << "  (5)  May                       (11) November\n";
	cout << "  (6)  June                      (12) December\n";
	printSeparator('*');
}

int main()
{
	// Program to display month name based on month number using enum class and switch statement
	showMonthsMenu();

	string monthName = getMonth(readMonth("Enter month number (1-12): ", MIN_MONTH, MAX_MONTH));

	printSeparator();

	cout << monthName << '\n';

	printSeparator();

	return 0;
}