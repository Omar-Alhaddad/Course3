
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	// calculate the Square, Cube, and Fourth Power of a Using the pow() function
	cout << "Welcome to the Square, Cube, and Fourth Power Calculator!\n\n";

	int Number = 0;

	cout << "Please enter the number?\n";
	cin >> Number;

	float SquarePower = pow(Number, 2);
	float CubePower = pow(Number, 3);
	float FourthPower = pow(Number, 4);

	cout << "\nSquare power of the number is: " << round(SquarePower);
	cout << "\nCube power of the number is: " << round(CubePower);
	cout << "\nFourth power of the number is: " << round(FourthPower);

    return 0;
}