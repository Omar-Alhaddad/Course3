
#include <iostream>
#include <string>
#include <limits>

using namespace std;

constexpr int MIN_GRADE = 0;
constexpr int MAX_GRADE = 100;
constexpr int GRADE_A_THRESHOLD = 90;
constexpr int GRADE_B_THRESHOLD = 80;
constexpr int GRADE_C_THRESHOLD = 70;
constexpr int GRADE_D_THRESHOLD = 60;
constexpr int GRADE_E_THRESHOLD = 50;

void printSeparator(char fillChar = '-', int length = 50) {

	cout << string(length, fillChar) << '\n';
}

void clearInputBuffer() {

	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int validateIntegerInRange(const string& prompt, int minValue, int maxValue) {

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

char gradeToLetter(int grade) {

	if (grade >= GRADE_A_THRESHOLD) {
		return 'A';
	}
	else if (grade >= GRADE_B_THRESHOLD) {
		return 'B';
	}
	else if (grade >= GRADE_C_THRESHOLD) {
		return 'C';
	}
	else if (grade >= GRADE_D_THRESHOLD) {
		return 'D';
	}
	else if (grade >= GRADE_E_THRESHOLD) {
		return 'E';
	}
	else {
		return 'F';
	}
}

int main()
{
	// Program to convert numeric grades to letter grades
	int grade = validateIntegerInRange("Enter your grade (0-100): ", MIN_GRADE, MAX_GRADE);

	printSeparator();

	cout << "Your letter grade is: " << gradeToLetter(grade) << '\n';

	return 0;
}