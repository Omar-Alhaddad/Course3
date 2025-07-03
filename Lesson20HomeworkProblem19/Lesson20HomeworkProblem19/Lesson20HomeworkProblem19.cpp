
#include <iostream>
using namespace std;

int main()
{
    // Calculates the Area of a Circle Given its Diameter
    cout << "Welcome to the Circle Area Calculator!\n\n";

    int Diameter;
    const float PI = 3.1416;

    cout << "Please enter the diameter?\n";
    cin >> Diameter;

    float Area = (PI * Diameter * Diameter) / 4;

    cout << "\nThe Area of the Circle is: " << Area << endl;

    return 0;
}