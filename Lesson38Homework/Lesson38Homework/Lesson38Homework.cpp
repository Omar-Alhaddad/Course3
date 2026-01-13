
#include <iostream>
#include <string>
#include <limits>

using namespace std;

enum class Gender { Male, Female };

enum class MaritalStatus { Single, Married };

struct Address
{
	string city;
	string country;
};

struct UserInfo
{
	Address address;
	string name;
	double monthlySalary = 0.0;
	short age = 0;
	Gender gender = Gender::Male;
	MaritalStatus maritalStatus = MaritalStatus::Single;
};

void clearInputBuffer() {

	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

double validatePositiveDouble(const string& prompt) {

	double number;

	while (true)
	{
		cout << prompt;

		if (!(cin >> number))
		{
			clearInputBuffer();

			cout << "Invalid input! Please enter a valid number.\n\n";
		}
		else if (number <= 0)
		{
			clearInputBuffer();

			cout << "Invalid input! Number must be positive.\n\n";
		}
		else
		{
			clearInputBuffer();
			return number;
		}
	}
}

int validatePositiveInteger(const string& prompt, int minval, int maxval) {

	int number;

	while (true)
	{
		cout << prompt;

		if (!(cin >> number))
		{
			clearInputBuffer();

			cout << "Invalid input! Please enter a valid number.\n\n";
		}
		else if (number < minval || number>maxval)
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

// Template for enum validation
template <typename T>
T validateEnum(const string& prompt, int minval, int maxval) {
	int input = validatePositiveInteger(prompt, minval, maxval);
	return static_cast<T>(input);
}

// Convert enum to string with better encapsulation
string genderToString(Gender gender) {

	switch (gender) {

	case Gender::Male: return "Male";
	case Gender::Female: return "Female";
	default: return "Unknown";
	}
}

string maritalStatusToString(MaritalStatus status) {

	switch (status) {

	case MaritalStatus::Single: return "Single";
	case MaritalStatus::Married: return "Married";
	default: return "Unknown";
	}
}

void printSeparator(char fillChar = '-', int length = 50) {

	cout << string(length, fillChar) << '\n';
}

double calculateAnnualIncome(double monthlySalary) {

	const int MONTHS_IN_YEAR = 12;
	return monthlySalary * MONTHS_IN_YEAR;
}

void readPersonInfo(UserInfo& user) {

	cout << "Enter Your Name: ";
	getline(cin, user.name);

	// Validate name is not empty
	while (user.name.empty()) {

		cout << "Name cannot be empty. Please enter your name: ";
		getline(cin, user.name);
	}

	user.age = validatePositiveInteger("Enter Your Age: ", 1, 150);

	cout << "Enter Your City: ";
	getline(cin, user.address.city);

	cout << "Enter Your Country: ";
	getline(cin, user.address.country);

	user.monthlySalary = validatePositiveDouble("Enter Your Monthly Salary: ");

	user.gender = validateEnum<Gender>("Enter your gender (0 = Male, 1 = Female): ", 0, 1);

	user.maritalStatus = validateEnum<MaritalStatus>("Enter your marital status (0 = Single, 1 = Married): ", 0, 1);
}

void printPersonInfo(const UserInfo& user) {

	printSeparator();

	cout << "Name: " << user.name << '\n';
	cout << "Age: " << user.age << " Years\n";
	cout << "City : " << user.address.city << '\n';
	cout << "Country : " << user.address.country << '\n';
	cout << "Monthly Salary : " << user.monthlySalary << '\n';
	cout << "Yearly Salary : " << calculateAnnualIncome(user.monthlySalary) << '\n';
	cout << "Gender : " << genderToString(user.gender) << '\n';
	cout << "Marital Status: " << maritalStatusToString(user.maritalStatus) << '\n';

	printSeparator();
}


int main()
{
	// My Personal Information Card
	UserInfo myInfo;

	readPersonInfo(myInfo);
	printPersonInfo(myInfo);

	return 0;
}