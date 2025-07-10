
#include <iostream>
using namespace std;

int main()
{
    // calculate the Square, Cube, and Fourth Power of a Number
    cout << "Welcome to the Square, Cube, and Fourth Power Calculator!\n\n";

    int Number;

    cout << "Please enter the number?\n";
    cin >> Number;

    int SquarePower = Number * Number;
    int CubePower = Number * Number * Number;
    int FourthPower = Number * Number * Number * Number;

    cout << "\nSquare power of the number is: " << SquarePower;
    cout << "\nCube power of the number is: " << CubePower;
    cout << "\nFourth power of the number is: " << FourthPower;

    return 0;
}