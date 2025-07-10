
#include <iostream>
using namespace std;

int main()
{
    // Calculates the Area of a Circle Inscribed in an Isosceles Triangle
    cout << "Welcome to the Circle Area Inscribed in Isosceles Triangle Calculator!\n\n";

    int EqualSides, Base;
    const float PI = 3.1416;

    cout << "Please enter the length of the equal sides of the triangle?\n";
    cin >> EqualSides;
    cout << "Please enter the base of the triangle?\n";
    cin >> Base;

    float CircleArea = (PI * Base * Base / 4) * ((2.0 * EqualSides - Base) / (2 * EqualSides + Base));

    cout << "\nThe area of the circle is: " << CircleArea << endl;

    return 0;
}