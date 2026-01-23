
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

enum class MathematicalOperations { Multiplication = 42, Addition = 43, Subtraction = 45, Division = 47 };

struct CalculationTask
{
	double number1;
	double number2;
	MathematicalOperations operation;
};

void printSeparator(char fillChar = '-', int length = 50) {

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

char validateOperationType(const string& prompt) {

	char c;

	while (true) {

		cout << prompt;
		cin >> c;

		switch (static_cast<MathematicalOperations>(c))
		{
		case MathematicalOperations::Addition:
		case MathematicalOperations::Subtraction:
		case MathematicalOperations::Multiplication:
		case MathematicalOperations::Division:
			clearInputBuffer();
			return c;
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

	task.operation = static_cast<MathematicalOperations>(validateOperationType("Enter a mathematical operation (+, -, *, /): "));
}

double executeCalculation(const CalculationTask& task) {

	if (task.operation == MathematicalOperations::Addition)
	{
		return task.number1 + task.number2;
	}
	else if (task.operation == MathematicalOperations::Subtraction)
	{
		return task.number1 - task.number2;
	}
	else if (task.operation == MathematicalOperations::Multiplication)
	{
		return task.number1 * task.number2;
	}
	else
	{
		if (task.number2 == 0.0)
		{
			throw runtime_error("Division by zero is not allowed!");
		}
		return task.number1 / task.number2;
	}
}

int main()
{
	// Program to perform a mathematical calculation based on user input 
	try {
		CalculationTask task;

		readCalculationTask(task);

		printSeparator();

		cout << "Result is : " << fixed << setprecision(3) << executeCalculation(task) << '\n';
	}
	catch (const exception& e) {

		cerr << "Error: " << e.what() << '\n';
		return 1;
	}

	return 0;
}