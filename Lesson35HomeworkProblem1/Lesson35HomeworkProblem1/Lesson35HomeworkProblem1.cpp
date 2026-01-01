
#include <iostream>
#include <string>
using namespace std;

void printName(const string& name = "Omar") {

    cout << name << endl;
}

int main()
{
	// Print the default name
	printName();

	// Print the name "Ahmed"
	printName("Ahmed");

    return 0;
}