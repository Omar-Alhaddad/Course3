
#include <iostream>
#include <string_view>
#include <limits> 

using namespace std;

constexpr int MIN_DAY = 1;
constexpr int MAX_DAY = 7;

enum class DaysOfWeek : int { Sunday = 1, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday };

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

	switch (dayEnum)
	{
	case DaysOfWeek::Sunday:
		return "Sunday";
	case DaysOfWeek::Monday:
		return "Monday";
	case DaysOfWeek::Tuesday:
		return "Tuesday";
	case DaysOfWeek::Wednesday:
		return "Wednesday";
	case DaysOfWeek::Thursday:
		return "Thursday";
	case DaysOfWeek::Friday:
		return "Friday";
	case DaysOfWeek::Saturday:
		return "Saturday";
	default:
		return "Wrong Day";
	}
}

string_view getDayName(int dayNumber) {

	constexpr string_view days[] = { "Wrong Day", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

	return (dayNumber >= MIN_DAY && dayNumber <= MAX_DAY) ? days[dayNumber] : days[0];
}

int main()
{
	// Program to display the day of the week based on user input (1-7)
	int dayNumber = validateIntegerInRange("Enter day number (1-7): ", MIN_DAY, MAX_DAY);

	printSeparator();

	cout << "It's " << daysOfWeekToString(dayNumber) << '\n';

	printSeparator();

	cout << "It's " << getDayName(dayNumber) << '\n';

	return 0;
}