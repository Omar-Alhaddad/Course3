
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

constexpr int MIN_STRLENGTH = 4;
constexpr int MAX_STRLENGTH = 6;
constexpr int ACCOUNT_BALANCE = 7500;
const string CORRECT_PIN = "1234";

void printSeparator(char fillChar = '-', int length = 50) {

	cout << string(length, fillChar) << '\n';
}

bool isPINFormatValid(const string& pin, size_t minLength, size_t maxLength) {

	if (pin.length() < minLength || pin.length() > maxLength)
	{
		cout << "Invalid PIN! PIN must be between " << minLength << " and " << maxLength << " digits.\n\n";
		return false;
	}
	if (!all_of(pin.begin(), pin.end(), ::isdigit))
	{
		cout << "Invalid PIN! PIN must contain digits only.\n\n";
		return false;
	}

	return true;
}

string validatePIN(const string& prompt, size_t minLength, size_t maxLength) {

	string pin;

	while (true)
	{
		cout << prompt;

		cin >> pin;

		if (isPINFormatValid(pin, minLength, maxLength))
		{
			return pin;
		}
	}
}

bool verifyPIN(const string& enteredPIN) {

	return enteredPIN == CORRECT_PIN;
}

void displayUserBalance(const string& enteredPIN) {

	if (verifyPIN(enteredPIN))
	{
		cout << "Your balance is: " << ACCOUNT_BALANCE << endl;
	}
	else
	{
		cout << "Wrong PIN" << endl;
	}
}

int main()
{
	// Program to validate user PIN and display account balance
	cout << "=== ATM System ===" << endl;

	printSeparator();

	string pin = validatePIN("Enter your PIN: ", MIN_STRLENGTH, MAX_STRLENGTH);

	printSeparator();

	displayUserBalance(pin);

	return 0;
}