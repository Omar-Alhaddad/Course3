
#include <iostream>
#include <string>

using namespace std;

constexpr int NUM_GRADES = 3;
constexpr int MIN_GRADE = 0;
constexpr int MAX_GRADE = 100;

void clearInputBuffer() {

	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

float validateGradeInput(const string& prompt, int minval, int maxval) {

	float number;

	while (true)
	{
		cout << prompt;

		if (!(cin >> number))
		{
			clearInputBuffer();

			cout << "Invalid input! Please enter a valid number.\n\n";
		}
		else if (number < minval || number > maxval)
		{
			clearInputBuffer();

			cout << "Invalid input! Number must be between " << minval << " and " << maxval << "\n\n";
		}
		else
		{
			clearInputBuffer();
			return number;
		}
	}
}

void readGrades(float grades[], int size) {

	for (int i = 0; i < size; i++)
	{
		string prompt = "Enter grade" + to_string(i + 1) + " : ";
		grades[i] = validateGradeInput(prompt, MIN_GRADE, MAX_GRADE);
	}
}

float calculateAverage(float grades[], int size) {

	float sum = 0.0f;

	for (int i = 0; i < size; i++)
	{
		sum += grades[i];
	}

	return sum / size;
}

void printResult(float result) {

	cout << string(20, '*') << endl;
	cout << "The average of grades is: " << result << endl;
}

int main()
{
	// Program that reads 3 student grades and calculates their average
	float grades[NUM_GRADES] = {};

	readGrades(grades, NUM_GRADES);

	float average = calculateAverage(grades, NUM_GRADES);

	printResult(average);

	return 0;
}