
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cmath>
#include <limits>

using namespace std;

constexpr char FILL_CHAR = '-';
constexpr int SEPARATOR_LENGTH = 50;
constexpr int PRECISION = 7;
constexpr double EPSILON = 1e-9;

enum class MathematicalOperations { Multiplication, Addition, Subtraction, Division };

struct CalculationTask
{
	double number1;
	double number2;
	MathematicalOperations operation;
};

void printSeparator(char fillChar = FILL_CHAR, int length = SEPARATOR_LENGTH) {

	cout << string(length, fillChar) << '\n';
}

void clearInputBuffer() {

	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

double validateNumber(const string& prompt) {

	double number;

	while (true)
	{
		cout << prompt;

		if (!(cin >> number))
		{
			clearInputBuffer();

			cout << "Invalid input! Please enter a valid number.\n\n";
		}
		else
		{
			clearInputBuffer();
			return number;
		}
	}
}

char operationToChar(const MathematicalOperations op) {

	switch (op)
	{
	case MathematicalOperations::Addition:
		return '+';
	case MathematicalOperations::Subtraction:
		return '-';
	case MathematicalOperations::Multiplication:
		return '*';
	case MathematicalOperations::Division:
		return '/';
	default:
		return '?';
	}
}

MathematicalOperations validateOperationType(const string& prompt) {

	char c;

	while (true) {

		cout << prompt;
		cin >> c;

		switch (c)
		{
		case '+':
			clearInputBuffer();
			return MathematicalOperations::Addition;
		case '-':
			clearInputBuffer();
			return MathematicalOperations::Subtraction;
		case '*':
			clearInputBuffer();
			return MathematicalOperations::Multiplication;
		case '/':
			clearInputBuffer();
			return MathematicalOperations::Division;
		default:
			clearInputBuffer();
			cout << "Invalid operation! Please enter +, -, *, or /\n\n";
			break;
		}
	}
}

void readCalculationTask(CalculationTask& task) {

	task.number1 = validateNumber("Enter number 1: ");

	task.number2 = validateNumber("Enter number 2: ");

	task.operation = validateOperationType("Enter a mathematical operation (+, -, *, /): ");
}

double executeCalculation(const CalculationTask& task) {

	switch (task.operation) {

	case MathematicalOperations::Addition:
		return task.number1 + task.number2;

	case MathematicalOperations::Subtraction:
		return task.number1 - task.number2;

	case MathematicalOperations::Multiplication:
		return task.number1 * task.number2;

	case MathematicalOperations::Division:
		if (abs(task.number2) < EPSILON)
		{
			throw runtime_error("Division by zero is not allowed!");
		}
		return task.number1 / task.number2;

	default:
		throw logic_error("Invalid operation");
	};
}

bool hasDecimalPart(double number) {

	return abs(number - round(number)) > EPSILON;
}

void printNumber(double number) {

	if (hasDecimalPart(number))
	{
		ostringstream oss;
		oss << fixed << setprecision(PRECISION) << number;
		string str = oss.str();

		// Remove trailing zeros
		str.erase(str.find_last_not_of('0') + 1, string::npos);

		// Remove trailing decimal point if all decimals were zeros
		if (str.back() == '.') {
			str.pop_back();
		}

		cout << str;
	}
	else
	{
		cout << static_cast<int>(number);
	}
}

void printCalculationTask(const CalculationTask& task) {

	double result = executeCalculation(task);

	printNumber(task.number1);
	cout << " " << operationToChar(task.operation) << " ";
	printNumber(task.number2);
	cout << " = ";
	printNumber(result);
	cout << '\n';
}

int main()
{
	// Program to perform a mathematical calculation based on user input 
	try {
		CalculationTask task;

		readCalculationTask(task);

		printSeparator();

		printCalculationTask(task);
	}
	catch (const exception& e) {

		cerr << "Error: " << e.what() << '\n';
		return 1;
	}

	return 0;
}