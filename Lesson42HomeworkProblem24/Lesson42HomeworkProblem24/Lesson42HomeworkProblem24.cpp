
#include <iostream>
#include <string>
#include <limits>

using namespace std;

constexpr int MIN_INPUT_VALUE = 1;
constexpr int MAX_INPUT_VALUE = 150;
constexpr int MIN_VALID_AGE = 18;
constexpr int MAX_VALID_AGE = 45;

void clearInputBuffer() {

	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void printSeparator(char fillChar = '-', int length = 50) {

	cout << string(length, fillChar) << '\n';
}

int validateNumberInRange(const string& prompt, int minValue, int maxValue) {

	int number;

	while (true)
	{
		cout << prompt;

		if (!(cin >> number))
		{
			clearInputBuffer();

			cout << "Invalid input! Please enter a valid number.\n\n";
		}
		else if (number < minValue || number > maxValue)
		{
			clearInputBuffer();

			cout << "Invalid input! Number must be between " << minValue << " and " << maxValue << "\n\n";
		}
		else
		{
			clearInputBuffer();
			return number;
		}
	}
}

bool isValidAge(int age) {

	return age >= MIN_VALID_AGE && age <= MAX_VALID_AGE;
}

void printAgeValidation(int age) {

	if (isValidAge(age))
	{
		cout << "Your age is Valid Age" << endl;
	}
	else
	{
		cout << "Sorry, Your age is Invalid Age" << endl;
	}
}

int main()
{
	// Validate user age input and check if it's within a valid range

	int age = validateNumberInRange("Enter your age: ", MIN_INPUT_VALUE, MAX_INPUT_VALUE);

	printSeparator();

	printAgeValidation(age);

	return 0;
}