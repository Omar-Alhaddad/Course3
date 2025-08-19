
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	// Calculate the Area of a Circle Given the Radius
	cout << "Welcome to the Circle Area Calculator!\n\n";

	const double PI = 3.1416;
	double Radius = 0.0;

	cout << "Please enter the radius of the circle?\n";
	cin >> Radius;

	//double Area = PI * Radius * Radius;
	double Area = PI * pow(Radius, 2);

	cout << "\nThe area of the circle is: " << ceil(Area) << endl;

    return 0;
}