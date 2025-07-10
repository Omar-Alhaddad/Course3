
#include <iostream>
using namespace std;

int main()
{
    // Calculate the Number of Days, Hours, Minutes and Seconds from a Given Number of Seconds
    cout << "Welcome to the Time Converter Calculator!\n\n";

    int TotalSeconds, NumberOfDays, NumberOfHours, NumberOfMinutes, NumberOfSeconds, Remainder;
    int SecondsPerDay = 24 * 60 * 60;
    short SecondsPerHour = 60 * 60;
    short SecondsPerMinute = 60;

    cout << "Please enter the total seconds?\n";
    cin >> TotalSeconds;

    NumberOfDays = TotalSeconds / SecondsPerDay;
    Remainder = TotalSeconds % SecondsPerDay;
    NumberOfHours = Remainder / SecondsPerHour;
    Remainder %= SecondsPerHour;
    NumberOfMinutes = Remainder / SecondsPerMinute;
    Remainder %= SecondsPerMinute;
    NumberOfSeconds = Remainder;

    cout << "\n" << NumberOfDays << ":" << NumberOfHours << ":" << NumberOfMinutes << ":" << NumberOfSeconds << endl;

    return 0;
}