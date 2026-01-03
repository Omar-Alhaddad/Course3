
#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>
#include <numbers>

using namespace std;

constexpr double PI = numbers::pi;

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

constexpr double calculateCircleArea(double squareSideLength) {

	// Area = π * r² where r = sideLength/2
	// Therefore: Area = π * (sideLength/2)² = π * sideLength² / 4
	return (PI * squareSideLength * squareSideLength) / 4;
}

int main()
{
	// Calculates the Area of a Circle Inscribed in a Square
	cout << "Welcome to the Circle Area Inscribed in a Square Calculator!\n\n";

	double squareSideLength = validatePositiveDouble("Enter the side length of the square: ");
	double area = calculateCircleArea(squareSideLength);

	cout << fixed << setprecision(2);
	cout << "\nThe area of the circle is: " << area;
	cout << "\nThe area of the circle is (ceiling): " << ceil(area) << endl;

	return 0;
}