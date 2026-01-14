
#include <iostream>
#include <string>

using namespace std;

void clearInputBuffer() {

	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

float validatePositiveFloat(const string& prompt, int minval, int maxval) {

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
			return number;
		}
	}
}

template<size_t N>
void readGrades(float(&grades)[N]) {

	for (size_t i = 0; i < N; i++)
	{
		string prompt = "Enter grade" + to_string(i + 1) + " : ";
		grades[i] = validatePositiveFloat(prompt, 1, 100);
	}
}

template<size_t N>
float calculateAverage(const float(&grades)[N]) {

	float sum = 0;

	for (const float& grade : grades)
	{
		sum += grade;
	}

	return sum / N;
}

int main()
{
	// Program that reads 3 student grades and calculates their average
	float grades[3];

	readGrades(grades);

	cout << string(20, '*') << endl;
	cout << "The average of grades is: " << calculateAverage(grades) << endl;

	return 0;
}