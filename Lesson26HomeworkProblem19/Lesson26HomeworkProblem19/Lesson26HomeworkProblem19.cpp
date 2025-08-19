
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	// Calculate the Area of a Circle Given the Diameter
	cout << "Welcome to the Circle Area Calculator from Diameter!\n\n";

	double Diameter = 0;
	const double Pi = 3.1416;

	cout << "Please enter the diameter length of the circle?\n";
	cin >> Diameter;

	//double Area = (Pi * Diameter * Diameter) / 4;
	double Area = (Pi * pow(Diameter, 2)) / 4;

	cout << "\nThe area of the circle is: " << ceil(Area) << endl;

    return 0;
}