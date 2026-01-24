
#include <iostream>
#include <string>
#include <limits> 

using namespace std;

constexpr int MIN_DAY = 1;
constexpr int MAX_DAY = 7;

enum class DaysOfWeek : int { Sunday = 1, Monday = 2, Tuesday = 3, Wednesday = 4, Thursday = 5, Friday = 6, Saturday = 7 };

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

			cout << "Invalid day! Number must be between " << minValue << " and " << maxValue << "\n\n";
		}
		else
		{
			clearInputBuffer();
			return number;
		}
	}
}

string daysOfWeekToString(int daynumber) {

	DaysOfWeek dayEnum = static_cast<DaysOfWeek>(daynumber);

	if (dayEnum == DaysOfWeek::Sunday)
	{
		return "Sunday";
	}
	else if (dayEnum == DaysOfWeek::Monday)
	{
		return "Monday";
	}
	else if (dayEnum == DaysOfWeek::Tuesday)
	{
		return "Tuesday";
	}
	else if (dayEnum == DaysOfWeek::Wednesday)
	{
		return "Wednesday";
	}
	else if (dayEnum == DaysOfWeek::Thursday)
	{
		return "Thursday";
	}
	else if (dayEnum == DaysOfWeek::Friday)
	{
		return "Friday";
	}
	else if (dayEnum == DaysOfWeek::Saturday)
	{
		return "Saturday";
	}
	else
	{
		return "Wrong Day";
	}
}

string daysOfWeekToStringByArray(int dayNumber) {

	static const string days[] = { "Wrong Day", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

	return (dayNumber >= MIN_DAY && dayNumber <= MAX_DAY) ? days[dayNumber] : days[0];
}

int main()
{
	// Program to display the day of the week based on user input (1-7)
	int dayNumber = validateIntegerInRange("Enter day number (1-7): ", MIN_DAY, MAX_DAY);

	printSeparator();

	cout << "It's " << daysOfWeekToString(dayNumber) << '\n';

	printSeparator();

	cout << "It's " << daysOfWeekToStringByArray(dayNumber) << '\n';

	return 0;
}