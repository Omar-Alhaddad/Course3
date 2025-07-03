
#include <iostream>
using namespace std;

int main()
{
    // Calculates the Area of a Circle Inscribed in a Square
    cout << "Welcome to the Circle Area Inscribed in a Square Calculator!\n\n";

    int SideLength;
    const float PI = 3.1416;

    cout << "Please enter the side length of the square?\n";
    cin >> SideLength;

    float Area = (PI * SideLength * SideLength) / 4;

    cout << "\nThe area of the circle is: " << Area << endl;

    return 0;
}