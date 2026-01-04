
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <cmath>
#include <numbers>

using namespace std;

constexpr double PI = numbers::pi;

struct TriangleSides
{
	double a, b, c;
};

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

bool isValidTriangle(const TriangleSides& sides) {

	return (sides.a + sides.b > sides.c) &&
		(sides.a + sides.c > sides.b) &&
		(sides.b + sides.c > sides.a) &&
		(sides.a > 0) && (sides.b > 0) && (sides.c > 0);
}

double calculateSemiperimeter(const TriangleSides& sides) {

	return (sides.a + sides.b + sides.c) * 0.5;
}

double calculateCircumradius(const TriangleSides& sides) {

	double p = calculateSemiperimeter(sides);
	double heronTerm = (p * (p - sides.a) * (p - sides.b) * (p - sides.c));

	// Formula: R = abc / (4 * Area), where Area = sqrt(heronTerm)
	return (sides.a * sides.b * sides.c) / (4.0 * sqrt(heronTerm));
}

double calculateCircleArea(const TriangleSides& sides) {

	double R = calculateCircumradius(sides);
	return PI * R * R;
}

int main()
{
	// Calculate the Area of a Circle Given the Lengths of the Sides of a Arbitrary Triangle
	cout << "Welcome to the Circle Area Calculator from Triangle Sides!\n\n";

	double a = validatePositiveDouble("Enter the first side length of the triangle: ");
	double b = validatePositiveDouble("Enter the second side length of the triangle: ");
	double c = validatePositiveDouble("Enter the third side length of the triangle: ");

	TriangleSides sides{ a,b,c };

	if (!isValidTriangle(sides))
	{
		cerr << "\nError: The given sides do not form a valid triangle!\n";
		cerr << "Reminder: For a valid triangle, the sum of any two sides must be greater than the third side.\n" << endl;
		return 1;
	}

	double area = calculateCircleArea(sides);

	cout << fixed << setprecision(3);
	cout << "\nThe area of the circle is: " << area;
	cout << "\nThe area of the circle is (Rounded): " << round(area) << endl;

	return 0;
}