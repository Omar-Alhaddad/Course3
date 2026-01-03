
#include <iostream>
#include <limits>
#include <numbers>
#include <iomanip>

using namespace std;

const double PI = numbers::pi;

double validatePositiveDouble(const string& prompt) {

	double number;

	while (true)
	{
		cout << prompt;

		if (!(cin >> number))
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

double calculateCircleArea(double diameter) {

	return (PI * diameter * diameter) / 4;
}

int main()
{
	// Calculate the Area of a Circle Given the Diameter
	cout << "Welcome to the Circle Area Calculator from Diameter!\n\n";

	double diameter = validatePositiveDouble("Enter the diameter length of the circle: ");
	double area = calculateCircleArea(diameter);

	cout << fixed << setprecision(2);
	cout << "\nThe area of the circle is: " << area << endl;
	cout << "The area of the circle is (ceiling): " << ceil(area) << endl;

	return 0;
}