
#include <iostream>
#include <string>
#include <limits>
using namespace std;

constexpr unsigned int SECONDS_IN_MINUTE = 60;
constexpr unsigned int SECONDS_IN_HOUR = SECONDS_IN_MINUTE * 60;
constexpr unsigned int SECONDS_IN_DAY = SECONDS_IN_HOUR * 24;

struct Time
{
	unsigned int days;
	unsigned int hours;
	unsigned int minutes;
	unsigned int seconds;
};

int validatePositiveInteger(const string& prompt) {

	int number;

	while (true)
	{
		cout << prompt;

		if (!(cin >> number))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "Invalid input! Please enter a valid number.\n\n";
		}
		else if (number < 0)
		{
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "Invalid input! Number must be non-negative.\n\n";
		}
		else
		{
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			return number;
		}
	}
}

unsigned long long calculateTotalSeconds(const Time& time) {

	unsigned long long totalSeconds = 0;

	totalSeconds += static_cast<unsigned long long>(time.days) * SECONDS_IN_DAY;
	totalSeconds += static_cast<unsigned long long>(time.hours) * SECONDS_IN_HOUR;
	totalSeconds += static_cast<unsigned long long>(time.minutes) * SECONDS_IN_MINUTE;
	totalSeconds += time.seconds;

	return totalSeconds;
}

Time inputTime() {

	Time time;

	time.days = validatePositiveInteger("Enter the number of days: ");
	time.hours = validatePositiveInteger("Enter the number of hours: ");
	time.minutes = validatePositiveInteger("Enter the number of minutes: ");
	time.seconds = validatePositiveInteger("Enter the number of seconds: ");

	return time;
}

int main()
{
	// Calculate the Total Number of Seconds from Days, Hours, Minutes, and Seconds
	cout << "Welcome to the Seconds Calculator!\n\n";

	Time time = inputTime();

	unsigned long long totalSeconds = calculateTotalSeconds(time);

	cout << "\nThe total number of seconds is: " << totalSeconds << " seconds" << endl;

	return 0;
}