
#include <iostream>
#include <limits>
#include <cmath>
using namespace std;

float validatePositiveFloat(const string& prompt) {

	float number;

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

// Calculates rectangle area using the Pythagorean theorem
// Area = a * sqrt(d² - a²), where a is side length and d is diagonal
float calculateRectangleArea(float sideLength, float diagonal) {

	float otherSideLength = sqrt(pow(diagonal, 2) - pow(sideLength, 2));
	return sideLength * otherSideLength;
}

bool isValidRectangle(float sideLength, float diagonal) {

	return diagonal > sideLength;
}

int main()
{
	// Calculate the Area of a Rectangle Given the Length of One Side and the Diagonal
	cout << "Welcome to the Rectangle Area Calculator from One Side and the Diagonal!\n\n";

	float sideLength = validatePositiveFloat("Enter the side length (a): ");
	float diagonal = validatePositiveFloat("Enter the diagonal length (d): ");

	if (!isValidRectangle(sideLength, diagonal))
	{
		cerr << "\nError: The diagonal must be longer than the side length!\n";
		cerr << "For a valid rectangle: d > a\n";
		cerr << "Your input: d = " << diagonal << ", a = " << sideLength << '\n';
		return 1;
	}

	float area = calculateRectangleArea(sideLength, diagonal);
	cout << "\nThe area of the rectangle is: " << area << endl;

	return 0;
}