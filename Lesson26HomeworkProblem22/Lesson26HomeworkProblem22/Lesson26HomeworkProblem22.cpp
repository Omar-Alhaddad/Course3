
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	// Calculate the Area of a Circle Given the Base and Equal Side Lengths of an Isosceles Triangle
	cout << "Welcome to the Circle Area Calculator from Base and Equal Side Lengths of an Isosceles Triangle!\n\n";

	double Base = 0.0, EqualSide = 0.0;
	const double PI = 3.14159;

	cout << "Please enter the equal side length of the triangle?\n";
	cin >> EqualSide;
	cout << "Please enter the base length of the triangle?\n";
	cin >> Base;

	//double Area = (PI * Base * Base / 4) * ((2 * EqualSide - Base) / (2 * EqualSide + Base));
	double Area = (PI * pow(Base, 2) / 4) * ((2 * EqualSide - Base) / (2 * EqualSide + Base));

	cout << "\nThe area of the circle is: " << floor(Area) << endl;

    return 0;
}