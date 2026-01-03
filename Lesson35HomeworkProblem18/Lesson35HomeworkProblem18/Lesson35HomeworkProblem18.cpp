
#include <iostream>
#include <limits>
#include <cmath>
#include <iomanip>

using namespace std;

const double PI = 3.1415926535897;

double validatePositiveDouble(const string& prompt) {

	double number;

	while (true)
	{
		cout << prompt;
		cin >> number;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "Invalid input! Please enter a valid number.\n\n";
		}
		else if (number <= 0)
		{
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "Invalid input! Number must be positive.\n\n";
		}
		else
		{
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			return number;
		}
	}
}

double calculateCircleArea(double radius) {

	return PI * radius * radius;
}

int main()
{
	// Calculate the Area of a Circle Given the Radius
	cout << "Welcome to the Circle Area Calculator!\n\n";

	double radius = validatePositiveDouble("Enter the radius of the circle: ");
	double area = calculateCircleArea(radius);

	cout << fixed << setprecision(2);
	cout << "\nThe area of the circle is: " << area << endl;
	cout << "The area of the circle is (ceiling): " << ceil(area) << endl;

	return 0;
}