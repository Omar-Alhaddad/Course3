
#include <iostream>
using namespace std;

int main()
{
    // Calculate the Total Number of Seconds from Days, Hours, Minutes, and Seconds
    cout << "Welcome to the Seconds Calculator!\n\n";

    int NumberOfDays, NumberOfHours, NumberOfMinutes, NumberOfSeconds;

    cout << "Please enter the number of days?\n";
    cin >> NumberOfDays;
    cout << "Please enter the number of hours?\n";
    cin >> NumberOfHours;
    cout << "Please enter the number of minutes?\n";
    cin >> NumberOfMinutes;
    cout << "Please enter the number of seconds?\n";
    cin >> NumberOfSeconds;

    int TotalSeconds = (NumberOfDays * 24 * 60 * 60) + (NumberOfHours * 60 * 60) + (NumberOfMinutes * 60) + NumberOfSeconds;

    cout << "\nThe total number of seconds is: " << TotalSeconds << " Seconds" << endl;

    return 0;
}