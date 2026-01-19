
#include <iostream>
#include <string>
#include <limits>

using namespace std;

constexpr int MIN_MARK = 0;
constexpr int MAX_MARK = 100;
constexpr int PASSING_AVERAGE = 50;
constexpr int NUM_MARKS = 3;

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

void readMarks(int marks[], int size) {

	for (int i = 0; i < size; i++)
	{
		string prompt = "Enter mark " + to_string(i + 1) + ": ";
		marks[i] = validateNumberInRange(prompt, MIN_MARK, MAX_MARK);
	}
}

float calculateAverage(const int marks[], int size) {

	if (size == 0) return 0.0f;

	int sum = 0;

	for (int i = 0; i < size; i++)
	{
		sum += marks[i];
	}

	return static_cast<float>(sum) / size;
}

bool isPass(float average) {

	return average >= PASSING_AVERAGE;
}

string getFinalResult(float average) {

	return isPass(average) ? "PASS" : "FAIL";
}

int main()
{
	// Program to read 3 student marks, calculate their average, and determine if the student passed or failed
	int marks[NUM_MARKS] = {};

	readMarks(marks, NUM_MARKS);

	printSeparator();

	float average = calculateAverage(marks, NUM_MARKS);
	cout << "Average: " << average << '\n';

	cout << "Final Result: " << getFinalResult(average) << '\n';

	return 0;
}