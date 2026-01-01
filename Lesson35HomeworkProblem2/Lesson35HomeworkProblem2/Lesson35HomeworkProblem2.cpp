
#include <iostream>
#include <string>
using namespace std;

string getUserName(const string& prompt = "Please enter your name: ") {

	string name;

	do
	{
		cout << prompt;
		getline(cin, name);

		if (name.empty())
		{
			cout << "Name cannot be empty. Please try again.\n";
		}

	} while (name.empty());

	return name;
}

void printName(const string& name = "Omar") {

	cout << name << endl;
}

int main()
{
	// First interaction with default prompt
	printName(getUserName());

	cout << string(26, '_') << endl;

	// Second interaction with custom prompt
	printName(getUserName("Enter your full name: "));

	return 0;
}