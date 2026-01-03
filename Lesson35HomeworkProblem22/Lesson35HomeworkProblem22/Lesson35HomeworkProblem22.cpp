
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

double calculateInscribedCircleArea(double equalSide, double base) {

	// Formula: A = π * (b² / 4) * ((2a - b) / (2a + b))
	// where a = equal side length, b = base length
	return (PI * base * base / 4) * ((2 * equalSide - base) / (2 * equalSide + base));
}

bool isValidIsoscelesTriangle(const double equalSide, const double base) {

	// For isosceles: base < (2*equalSide) (the critical constraint)
	return base < (2 * equalSide);
}

int main()
{
	// Calculate the Area of a Circle Given the Base and Equal Side Lengths of an Isosceles Triangle
	cout << "Welcome to the Circle Area Calculator from Base and Equal Side Lengths of an Isosceles Triangle!\n\n";

	double	equalSide = validatePositiveDouble("Enter the equal side length of the triangle: ");
	double base = validatePositiveDouble("Enter the base length of the triangle: ");

	if (isValidIsoscelesTriangle(equalSide, base))
	{
		double area = calculateInscribedCircleArea(equalSide, base);

		cout << fixed << setprecision(3);
		cout << "\nThe area of the circle is: " << area;
		cout << "\nThe area of the circle is (floored): " << floor(area) << endl;
	}
	else
	{
		cout << "\nInvalid triangle! Base must be less than twice the equal side.\n";
	}

	return 0;
}