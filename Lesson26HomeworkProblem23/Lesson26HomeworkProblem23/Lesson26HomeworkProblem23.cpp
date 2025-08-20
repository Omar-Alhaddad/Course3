
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	// Calculate the Area of a Circle Given the Lengths of the Sides of a Arbitrary Triangle
	cout << "Welcome to the Circle Area Calculator from Triangle Sides!\n\n";

	double a = 0, b = 0, c = 0;
	const double PI = 3.14159;

	cout << "Please enter the first side length of the triangle?\n";
	cin >> a;
	cout << "Please enter the second side length of the triangle?\n";
	cin >> b;
	cout << "Please enter the third side length of the triangle?\n";
	cin >> c;

	double P = (a + b + c) / 2;  // Semi-perimeter
	double T = (a * b * c) / (4 * sqrt(P * (P - a) * (P - b) * (P - c)));
	double Area = PI * pow(T, 2);
	//double Area = PI * T * T;

	cout << "\nThe area of the circle is: " << round(Area) << endl;

    return 0;
}