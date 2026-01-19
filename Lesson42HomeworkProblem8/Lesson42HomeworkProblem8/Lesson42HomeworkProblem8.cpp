
#include <iostream>
#include <string>
#include <limits>

using namespace std;

constexpr int MIN_MARK = 0;
constexpr int MAX_MARK = 100;
constexpr int PASSING_MARK = 50;

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

bool isPass(int mark) {

	return mark >= PASSING_MARK;
}

string getMarkResult(int mark) {

	return isPass(mark) ? "Passed" : "Fail";
}

int main()
{
	// Get mark from user and display pass or fail result
	int mark = validateIntegerInRange("Enter your mark: ", MIN_MARK, MAX_MARK);

	cout << getMarkResult(mark) << endl;

	return 0;
}