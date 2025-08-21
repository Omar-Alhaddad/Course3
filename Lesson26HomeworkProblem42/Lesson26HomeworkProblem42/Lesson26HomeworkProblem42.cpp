
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	// Calculate the Total Number of Seconds from Days, Hours, Minutes, and Seconds Using the pow Function
	cout << "Welcome to the Seconds Calculator!\n\n";

	int NumberOfDays = 0, NumberOfHours = 0, NumberOfMinutes = 0, NumberOfSeconds = 0;

	cout << "Please enter the number of days?\n";
	cin >> NumberOfDays;
	cout << "Please enter the number of hours?\n";
	cin >> NumberOfHours;
	cout << "Please enter the number of minutes?\n";
	cin >> NumberOfMinutes;
	cout << "Please enter the number of seconds?\n";
	cin >> NumberOfSeconds;

	int TotalSeconds = (NumberOfDays * 24 * pow(60, 2)) + (NumberOfHours * pow(60, 2)) + (NumberOfMinutes * 60) + NumberOfSeconds;

	cout << "\nThe total number of seconds is: " << round(TotalSeconds) << " Seconds" << endl;

    return 0;
}