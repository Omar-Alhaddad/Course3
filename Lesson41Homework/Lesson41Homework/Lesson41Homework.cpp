
#include <iostream>
#include <string>

using namespace std;

constexpr int NUM_USERS = 2;
constexpr short MIN_AGE = 1;
constexpr short MAX_AGE = 150;

struct UserInfo
{
	string firstName;
	string lastName;
	string phone;
	short age = 0;
};

void clearInputBuffer() {

	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void printSeparator(char fillChar = '-', int length = 50) {

	cout << string(length, fillChar) << '\n';
}

short validatePositiveInteger(const string& prompt, short minval, short maxval) {

	short number;

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

			cout << "Invalid input! Age must be between " << minval << " and " << maxval << "\n\n";
		}
		else
		{
			clearInputBuffer();
			return number;
		}
	}
}

bool isValidPhone(const string& phone) {

	if (phone.empty()) return false;

	for (const char c : phone)
	{
		if (c < '0' || c > '9')
		{
			return false;
		}
	}

	return true;
}

void readPersonInfo(UserInfo& user) {

	cout << "Enter your first name: ";
	cin >> user.firstName;

	cout << "Enter your last name: ";
	cin >> user.lastName;

	cout << "Enter your phone: ";
	cin >> user.phone;

	while (!isValidPhone(user.phone)) {

		cout << "Invalid phone number! Enter your phone: ";
		cin >> user.phone;
	}

	user.age = validatePositiveInteger("Enter your age: ", MIN_AGE, MAX_AGE);
}

void printPersonInfo(const UserInfo& user) {

	printSeparator('*');

	cout << "First Name: " << user.firstName << '\n';
	cout << "Last Name: " << user.lastName << '\n';
	cout << "Age  : " << user.age << " Years\n";
	cout << "Phone: " << user.phone << '\n';

	printSeparator('*');
}

void readPersonsInfo(UserInfo users[], int size) {

	for (int i = 0; i < size; i++)
	{
		cout << "User Number " << i + 1 << '\n';

		readPersonInfo(users[i]);

		if (i != size - 1)
		{
			printSeparator('#');
		}
	}
}

void printPersonsInfo(const UserInfo users[], int size) {

	for (int i = 0; i < size; i++)
	{
		printPersonInfo(users[i]);
	}
}

int main()
{
	// Collect personal details from users and display them
	UserInfo Users[NUM_USERS];

	readPersonsInfo(Users, NUM_USERS);

	printSeparator();

	printPersonsInfo(Users, NUM_USERS);

	return 0;
}