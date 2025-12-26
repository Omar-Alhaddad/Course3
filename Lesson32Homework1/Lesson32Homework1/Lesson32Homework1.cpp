
#include <iostream>
#include <string>
using namespace std;

void displayMyInfoCard() {

	//My Information Card
	string border(42, '*');

	cout << border << '\n';
	cout << "Name: Omar Al-haddad\n";
	cout << "Age : 26 Years\n";
	cout << "City: Mukalla\n";
	cout << "Country: Yemen\n";
	cout << border << '\n';
}

int main()
{
	displayMyInfoCard();

	return 0;
}