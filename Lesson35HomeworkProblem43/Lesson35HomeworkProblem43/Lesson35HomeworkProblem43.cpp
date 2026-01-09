
#include <iostream>
#include <string>
#include <limits>
#include <exception>

using namespace std;

constexpr unsigned int SECONDS_IN_MINUTE = 60;
constexpr unsigned int SECONDS_IN_HOUR = SECONDS_IN_MINUTE * 60;
constexpr unsigned int SECONDS_IN_DAY = SECONDS_IN_HOUR * 24;

struct Time
{
	unsigned long long totalSeconds;
	unsigned int days;
	unsigned int hours;
	unsigned int minutes;
	unsigned int seconds;
};

unsigned long long validatePositiveInteger(const string& prompt) {

	string input;

	while (true)
	{
		cout << prompt;
		cin >> input;

		if (input.empty())
		{
			cout << "Invalid input! Please enter a valid number.\n\n";
			continue;
		}

		else if (input[0] == '-')
		{
			cout << "Invalid input! Negative numbers are not allowed.\n\n";
			continue;
		}

		try {

			size_t pos;
			unsigned long long number = stoull(input, &pos);

			if (input.length() != pos)
			{
				cout << "Invalid input! Please enter a valid number.\n\n";
				continue;
			}

			return static_cast<unsigned long long>(number);
		}

		catch (const exception) {

			cerr << "Invalid input! Number is too large.\n\n" << endl;
		}

	}
}

void convertSecondsToTime(Time& time) {

	unsigned long long remainder = time.totalSeconds;

	time.days = remainder / SECONDS_IN_DAY;
	remainder %= SECONDS_IN_DAY;

	time.hours = remainder / SECONDS_IN_HOUR;
	remainder %= SECONDS_IN_HOUR;

	time.minutes = remainder / SECONDS_IN_MINUTE;
	remainder %= SECONDS_IN_MINUTE;

	time.seconds = remainder;
}

void displayTime(const Time& time) {

	cout << "\n" << time.days << ":" << time.hours << ":" << time.minutes << ":" << time.seconds << endl;
}

int main()
{
	// Calculate Days, Hours, Minutes, and Seconds from Total Number of Seconds
	cout << "Welcome to the Time Duration Calculator!\n\n";

	Time time;
	time.totalSeconds = validatePositiveInteger("Enter the total seconds: ");

	convertSecondsToTime(time);
	displayTime(time);

	return 0;
}