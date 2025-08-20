
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	// Calculate the Area of a Circle Given the Circumference
	cout << "Welcome to the Circle Area Calculator from Circumference!\n\n";

	double Circumference = 0.0;
	const double PI = 3.14159;

	cout << "Please enter the circumference of the circle?\n";
	cin >> Circumference;

	//double Area = Circumference * Circumference / (4 * PI);
	double Area = pow(Circumference, 2) / (4.0 * PI);

	cout << "\nThe area of the circle is: " << floor(Area) << endl;

    return 0;
}