
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	// Calculate the Power of a Number From User Input
	cout << "Welcome to the Power Calculator!\n\n";

	int Number = 0, Power = 0;

	cout << "Please enter the number?\n";
	cin >> Number;
	cout << "Please enter the power to raise the number to?\n";
	cin >> Power;

	double Result = pow(Number, Power);

	cout << "\nThe result of " << Number << "^" << Power << " is : " << round(Result) << endl;

    return 0;
}