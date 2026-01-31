
#include <iostream>
#include <string>
#include <limits> 

using namespace std;

constexpr int MIN_DAY = 1;
constexpr int MAX_DAY = 7;

enum class WeekDay : int { Sunday = 1, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday };

void printSeparator(char fillChar = '-', int length = 50) {

	cout << string(length, fillChar) << '\n';
}

void clearInputBuffer() {

	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

[[nodiscard]] WeekDay readWeekDay(const string& prompt, int minValue, int maxValue) {

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
			return static_cast<WeekDay>(number);
		}
	}
}

void showWeekDayMenu() {

	printSeparator('*');
	cout << "\t\tWeek Days Menu\n";
	printSeparator('*');
	cout << "1. Sunday\n";
	cout << "2. Monday\n";
	cout << "3. Tuesday\n";
	cout << "4. Wednesday\n";
	cout << "5. Thursday\n";
	cout << "6. Friday\n";
	cout << "7. Saturday\n";
	printSeparator('*');
}

string getWeekDay(WeekDay day) {

	switch (day)
	{
	case WeekDay::Sunday:
		return "Sunday";
	case WeekDay::Monday:
		return "Monday";
	case WeekDay::Tuesday:
		return "Tuesday";
	case WeekDay::Wednesday:
		return "Wednesday";
	case WeekDay::Thursday:
		return "Thursday";
	case WeekDay::Friday:
		return "Friday";
	case WeekDay::Saturday:
		return "Saturday";
	default:
		return "Not a Week Day!";
	}
}

int main()
{
	// Program to display the day of the week based on user input (1-7)
	showWeekDayMenu();

	string dayName = getWeekDay(readWeekDay("Enter day number (1-7): ", MIN_DAY, MAX_DAY));

	printSeparator();

	cout << "It's " << dayName << '\n';

	printSeparator();

	return 0;
}