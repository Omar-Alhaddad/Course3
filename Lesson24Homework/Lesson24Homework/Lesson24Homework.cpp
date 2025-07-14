
#include <iostream>
using namespace std;

int main()
{
	// Demonstrates the Use of Relational Operators
	int A, B;

	cout << "Please enter the first number A?\n";
	cin >> A;

	cout << "Please enter the second number B?\n";
	cin >> B;

	cout << A << " == " << B << " is " << (A == B) << endl;
	cout << A << " != " << B << " is " << (A != B) << endl;
	cout << A << " > " << B << " is " << (A > B) << endl;
	cout << A << " < " << B << " is " << (A < B) << endl;
	cout << A << " >= " << B << " is " << (A >= B) << endl;
	cout << A << " <= " << B << " is " << (A <= B) << endl;

    return 0;
}