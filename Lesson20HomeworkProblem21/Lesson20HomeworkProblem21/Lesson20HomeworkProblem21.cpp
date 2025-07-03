
#include <iostream>
using namespace std;

int main()
{
    // Calculates the Area of a Circle Given its Circumference
    cout << "Welcome to the Circle Area Calculator from its Circumference!\n\n";

    int Circumference;
    const float PI = 3.1416;

    cout << "Please enter the circle's circumference?\n";
    cin >> Circumference;

    float Area = (Circumference * Circumference) / (4 * PI);

    cout << "\nThe Area of the Circle is: " << Area << endl;

    return 0;
}