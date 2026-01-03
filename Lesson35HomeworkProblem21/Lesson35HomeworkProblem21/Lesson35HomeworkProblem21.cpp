
#include <iostream>
#include <iomanip>
#include <limits>
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

constexpr double calculateCircleArea(double circumference) {

	return (circumference * circumference) / (4 * PI);
}

int main()
{
	// Calculate the Area of a Circle Given the Circumference
	cout << "Welcome to the Circle Area Calculator from Circumference!\n\n";

	double circumference = validatePositiveDouble("Enter the circumference of the circle: ");
	double area = calculateCircleArea(circumference);

	cout << fixed << setprecision(3);
	cout << "\nThe area of the circle is: " << area;
	cout << "\nThe area of the circle is (floored): " << floor(area) << endl;

	return 0;
}