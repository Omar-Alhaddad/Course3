
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

constexpr int MIN_STRLENGTH = 4;
constexpr int MAX_STRLENGTH = 6;
constexpr int MAX_ATTEMPTS = 3;
constexpr int ACCOUNT_BALANCE = 7500;
const string CORRECT_PIN = "1234";

/**
 * Prints a separator line of a specified length and character.
 *
 * @param fillChar The character used to fill the separator line. Default is '-'.
 * @param length The length of the separator line. Default is 50.
 */
void printSeparator(char fillChar = '-', int length = 50) {

	cout << string(length, fillChar) << '\n';
}

/**
 * Checks if a PIN is valid.
 *
 * @param pin The PIN to validate.
 * @param minLength The minimum length of the PIN.
 * @param maxLength The maximum length of the PIN.
 * @return True if the PIN is valid, False otherwise.
 */
bool isPINFormatValid(const string& pin, size_t minLength, size_t maxLength) {

	if (pin.length() < minLength || pin.length() > maxLength)
	{
		cout << "Wrong PIN! PIN must be between " << minLength << " and " << maxLength << " digits.\n\n";
		return false;
	}
	if (!all_of(pin.begin(), pin.end(), ::isdigit))
	{
		cout << "Wrong PIN! PIN must contain digits only.\n\n";
		return false;
	}

	return true;
}

/**
 * Verifies if a PIN matches the correct PIN.
 *
 * @param enteredPIN The PIN to verify.
 * @return True if the PIN matches the correct PIN, False otherwise.
 */
bool verifyPIN(const string& enteredPIN) {

	return enteredPIN == CORRECT_PIN;
}

/**
 * Validates a PIN from user input.
 *
 * @param prompt The prompt to display to the user.
 * @param minLength The minimum length of the PIN.
 * @param maxLength The maximum length of the PIN.
 * @return The validated PIN.
 */
string validatePIN(const string& prompt, size_t minLength, size_t maxLength) {

	string pin;
	int failedCounter = 0;

	while (failedCounter < MAX_ATTEMPTS)
	{
		cout << prompt;

		cin >> pin;

		if (isPINFormatValid(pin, minLength, maxLength))
		{
			if (verifyPIN(pin))
			{
				return pin;
			}
			else
			{
				cout << "Wrong PIN\n\n";
				++failedCounter;
			}
		}
		else
		{
			++failedCounter;
		}
	}

	cout << "Card is locked!" << endl;

	return "";
}

/**
 * Displays the user's account balance if the entered PIN is correct.
 * Note: In current implementation, PIN is pre-validated, so this always displays.
 *
 * @param enteredPIN The PIN entered by the user.
 */
void displayUserBalance(const string& enteredPIN) {

	if (verifyPIN(enteredPIN))
	{
		cout << "Your balance is: " << ACCOUNT_BALANCE << endl;
	}
}

int main()
{
	// Program to validate user PIN and display account balance
	cout << "=== ATM System ===" << endl;

	printSeparator();

	string pin = validatePIN("Enter your PIN: ", MIN_STRLENGTH, MAX_STRLENGTH);

	if (pin.empty())
	{
		return 1;
	}

	printSeparator();

	displayUserBalance(pin);

	return 0;
}