
#include <iostream>
using namespace std;

int validatePositiveInteger(const string& prompt) {

	int number;

	cout << prompt;
	cin >> number;

	if (cin.fail() || number <= 0)
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << "Invalid input! Please enter a valid number.\n";

		return validatePositiveInteger(prompt);
	}

	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return number;
}

int calculateRectangleArea(int length, int width) {

	if (length > INT_MAX / width)
	{
		throw overflow_error("Area calculation would overflow!");
	}

	return length * width;
}

int main()
{
	// Calculates the Area of a Rectangle Given its Length and Width.
	cout << "Welcome to the Rectangle Area Calculator!\n\n";
	try {

		int Length = validatePositiveInteger("Please enter Length: ");
		int Width = validatePositiveInteger("Please enter Width: ");

		int area = calculateRectangleArea(Length, Width);
		cout << "\nThe area of the rectangle is: " << area << endl;
	}

	catch (const overflow_error& e) {

		cerr << "Error: " << e.what() << endl;
		return 1;
	}

	return 0;
}