
#include <iostream>
#include <string>
#include <limits>

using namespace std;

constexpr int SIZE = 10;
constexpr int MIN_INPUT = 1;
constexpr int MAX_INPUT = 100;
constexpr int MIN_CHOICE = 1;
constexpr int MAX_CHOICE = 4;

/**
 * @brief Prints a separator line with the specified character and count.
 *
 * @param fillChar The character to fill the line with. Default is '-'.
 * @param count The number of characters in the line. Default is 50.
 */
void printSeparator(char fillChar = '-', int count = 50) {

	cout << string(count, fillChar) << '\n';
}

/**
 * @brief Clears the input buffer to handle invalid input.
 */
void clearInputBuffer() {

	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

/**
 * @brief Validates and returns an integer within specified range.
 *
 * @param prompt The message to display to the user.
 * @param minValue The minimum acceptable value.
 * @param maxValue The maximum acceptable value.
 * @return The validated integer.
 */
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

/**
 * @brief Searches for the first occurrence of a target value in an array.
 *
 * @param arr The array to search.
 * @param target The value to search for.
 * @param size The size of the array.
 */
void searchNumber(const int arr[], int target, int size) {

	cout << "\n";

	for (int i = 0; i < size; i++)
	{
		if (arr[i] == target)
		{
			cout << target << " found at index [" << i << "]\n";

			return;
		}
	}

	cout << target << " not found in array\n";
}

/**
 * @brief Searches for all occurrences of a target value in an array.
 *
 * @param arr The array to search.
 * @param target The value to search for.
 * @param size The size of the array.
 */
void searchAllOccurrences(const int arr[], int target, int size) {

	bool found = false;

	cout << "\n";

	for (int i = 0; i < size; i++)
	{
		if (arr[i] == target)
		{
			cout << target << " found at index [" << i << "]\n";

			found = true;
		}
	}

	if (!found)
	{
		cout << target << " not found in array\n";
	}
}

/**
 * @brief Displays the contents of an array.
 *
 * @param arr The array to display.
 * @param size The size of the array.
 */
void displayArray(const int arr[], int size) {

	cout << "Array: [ ";

	for (int i = 0; i < size; i++)
	{
		cout << arr[i];

		if (i < size - 1)
		{
			cout << ", ";
		}
	}

	cout << " ]\n";
}

/**
 * @brief Displays the main menu with options.
 *
 */
void displayMenu() {

	printSeparator('=');
	cout << "       ARRAY SEARCH PROGRAM\n";
	printSeparator('=');
	cout << "1. Search for first occurrence\n";
	cout << "2. Search for all occurrences\n";
	cout << "3. Display the array\n";
	cout << "4. Exit\n";
}

int main()
{
	int arr[SIZE] = { 10, 20, 44, 55, 33, 22, 99, 88, 99, 100 };

	int choice;
	int target;

	do {
		displayMenu();

		choice = validateIntegerInRange("Enter your choice: ", MIN_CHOICE, MAX_CHOICE);

		switch (choice) {
		case 1:
			target = validateIntegerInRange("Enter the number for search: ", MIN_INPUT, MAX_INPUT);
			searchNumber(arr, target, SIZE);
			printSeparator();
			cout << '\n';
			break;

		case 2:
			target = validateIntegerInRange("Enter the number for search: ", MIN_INPUT, MAX_INPUT);
			searchAllOccurrences(arr, target, SIZE);
			printSeparator();
			cout << '\n';
			break;
		case 3:
			displayArray(arr, SIZE);
			printSeparator();
			cout << '\n';
			break;

		case 4:
			printSeparator('=');
			cout << "Thank you for using the Array Search Program!\n";
			printSeparator('=');
			break;
		}

	} while (choice != 4);

	return 0;
}