
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	// Calculate the Area of a Circle Given the Length of One Side of a Square
	cout << "Welcome to the Circle Area Inscribed in a Square Calculator!\n\n";

	double SquareLength;
	const double PI = 3.1416;

	cout << "Please enter the length of the square side?\n";
	cin >> SquareLength;

	//double Area = (PI * SquareLength * SquareLength) / 4;
	double Area = (PI * pow(SquareLength, 2)) / 4;

	cout << "\nThe area of the circle is: " << ceil(Area) << endl;

    return 0;
}