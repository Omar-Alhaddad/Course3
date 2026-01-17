
#include <iostream>
#include <string>
#include <cctype>
#include <limits>

using namespace std;

constexpr int MIN_AGE = 1;
constexpr int MAX_AGE = 150;
constexpr int MIN_HIRING_AGE = 21;

struct Employee
{
	int age = 0;
	bool hasDriverLicense = false;
};

void clearInputBuffer() {

	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void printSeparator(char fillChar = '-', int length = 50) {

	cout << string(length, fillChar) << '\n';
}

int validateAge(const string& prompt, int minval, int maxval) {

	int number;

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

			cout << "Invalid input! Age must be between " << minval << " and " << maxval << "\n\n";
		}
		else
		{
			clearInputBuffer();
			return number;
		}
	}
}

bool validateDriverLicense(const string& prompt) {

	char c;

	while (true)
	{
		cout << prompt;

		if (!(cin >> c))
		{
			clearInputBuffer();

			cout << "Invalid input! Please enter y or n\n\n";
		}
		else if (tolower(c) == 'y' || tolower(c) == 'n')
		{
			clearInputBuffer();

			return tolower(c) == 'y';
		}
		else
		{
			clearInputBuffer();

			cout << "Invalid input! Please enter y or n\n\n";
		}
	}
}

void readEmployeeInfo(Employee& employee) {

	employee.age = validateAge("Enter your age: ", MIN_AGE, MAX_AGE);

	employee.hasDriverLicense = validateDriverLicense("Do you have a driver license? (y/n): ");
}

void hireEmployee(const Employee& employee) {

	if (employee.age > MIN_HIRING_AGE && employee.hasDriverLicense)
	{
		cout << "Congratulations! You are HIRED.\n";
	}
	else
	{
		cout << "Sorry, you are REJECTED.\n";
		if (employee.age <= MIN_HIRING_AGE)
		{
			cout << "Reason: Age must be greater than " << MIN_HIRING_AGE << ".\n";
		}
		if (!employee.hasDriverLicense)
		{
			cout << "Reason: Driver license required.\n";
		}
	}
}

int main()
{
	// Program to hire employee based on age and driver license requirements
	Employee employee;

	readEmployeeInfo(employee);

	printSeparator();

	hireEmployee(employee);

	return 0;
}