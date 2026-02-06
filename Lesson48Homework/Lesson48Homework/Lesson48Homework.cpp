
#include <iostream>
#include <string>
#include <cctype>
#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

constexpr short MIN_INPUT = 1;
constexpr short MAX_INPUT = 150;
constexpr short MIN_USER = 1;
constexpr short MAX_USER = 100;

struct UserInfo
{
	string firstName;
	string lastName;
	string phone;
	short age = 0;
};

void clearScreen() {

#ifdef _WIN32
	// Windows API - No system() call
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coordScreen = { 0, 0 };
	DWORD cCharsWritten;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD dwConSize;

	if (!GetConsoleScreenBufferInfo(hConsole, &csbi))
	{
		return;
	}

	dwConSize = csbi.dwSize.X * csbi.dwSize.Y;

	FillConsoleOutputCharacter(hConsole, (TCHAR)' ', dwConSize, coordScreen, &cCharsWritten);

	GetConsoleScreenBufferInfo(hConsole, &csbi);

	FillConsoleOutputAttribute(hConsole, csbi.wAttributes, dwConSize, coordScreen, &cCharsWritten);

	SetConsoleCursorPosition(hConsole, coordScreen);

#else
	// ANSI escape codes for other platforms
	cout << "\033[2J\033[1;1H" << flush;
#endif
}

void clearInputBuffer() {

	cin.clear();
	cin.ignore((numeric_limits<streamsize>::max)(), '\n');
}

void printSeparator(char fillChar = '-', int length = 50) {

	cout << string(length, fillChar) << '\n';
}

short validatePositiveInteger(const string& prompt, short minValue, short maxValue) {

	short number;

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

bool isValidPhone(const string& phone) {

	if (phone.empty() || phone.length() < 7 || phone.length() > 15) {

		return false;
	}

	for (const char c : phone)
	{
		if (!isdigit(c))
		{
			return false;
		}
	}

	return true;
}

void readPersonInfo(UserInfo& user) {

	printSeparator();

	cout << "Enter first name: ";
	cin >> user.firstName;

	cout << "Enter last name: ";
	cin >> user.lastName;

	cout << "Enter phone: ";
	cin >> user.phone;

	while (!isValidPhone(user.phone)) {

		cout << "Invalid phone number! Enter valid phone: ";
		cin >> user.phone;
	}

	user.age = validatePositiveInteger("Enter your age: ", MIN_INPUT, MAX_INPUT);

	printSeparator();
}

void printPersonInfo(const UserInfo& user) {

	printSeparator('*');

	cout << "First Name: " << user.firstName << '\n';
	cout << "Last Name: " << user.lastName << '\n';
	cout << "Age  : " << user.age << " Years\n";
	cout << "Phone: " << user.phone << '\n';

	printSeparator('*');
}

void readPersonsInfo(UserInfo users[], int& numberOfUsers) {

	numberOfUsers = validatePositiveInteger("How many users do you want to enter(1 - 100) : ", MIN_USER, MAX_USER);

	for (int i = 0; i < numberOfUsers; i++)
	{
		printSeparator();

		cout << "Enter Person " << i + 1 << " Info:" << '\n';

		readPersonInfo(users[i]);
	}
}

void printPersonsInfo(const UserInfo users[], int numberOfUsers) {

	for (int i = 0; i < numberOfUsers; i++)
	{
		cout << "Person " << i + 1 << " Info:" << '\n';
		printPersonInfo(users[i]);
	}
}

int main()
{
	// Collect personal details from users and display them
	UserInfo users[MAX_USER];

	int numberOfUsers = 0;

	readPersonsInfo(users, numberOfUsers);

	clearScreen();

	printSeparator('*');

	printPersonsInfo(users, numberOfUsers);

	return 0;
}