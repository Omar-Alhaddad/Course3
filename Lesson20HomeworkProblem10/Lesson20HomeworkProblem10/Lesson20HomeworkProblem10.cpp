
#include <iostream>
using namespace std;

int main()
{
    // Calculate The Average of Three Marks
    cout << "Welcome to The Average of Three Marks Calculator!\n\n";

    int Mark1, Mark2, Mark3;

    cout << "Please enter the first mark?\n";
    cin >> Mark1;
    cout << "Please enter the second mark?\n";
    cin >> Mark2;
    cout << "Please enter the third mark?\n";
    cin >> Mark3;

    float AverageOfMArks = (Mark1 + Mark2 + Mark3) / 3.0;

    cout << "\nAverage: " << AverageOfMArks << endl;

    return 0;
}