
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int TotalSeconds, NumberOfDays, NumberOfHours, NumberOfMinutes, NumberOfSeconds, Remainder;

	const int SecondsPerDay = 24 * pow(60, 2);
	const int SecondsPerHour = pow(60, 2);
	const int SecondsPerMinute = 60;

	cout << "Please enter the total seconds?\n";
	cin >> TotalSeconds;

	NumberOfDays = TotalSeconds / SecondsPerDay;
	Remainder = TotalSeconds % SecondsPerDay;
	NumberOfHours = Remainder / SecondsPerHour;
	Remainder %= SecondsPerHour;
	NumberOfMinutes = Remainder / SecondsPerMinute;
	Remainder %= SecondsPerMinute;
	NumberOfSeconds = Remainder;

	cout << "\n" << round(NumberOfDays) << ":" << round(NumberOfHours) << ":" << round(NumberOfMinutes) << ":" << round(NumberOfSeconds) << endl;

    return 0;
}