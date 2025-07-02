
#include <iostream>
using namespace std;

int main()
{
	// Basic Arithmetic Operations
	int A, B;

	cout << "Please enter the first Number A?\n";
	cin >> A;
	cout << "Please enter the second Number B?\n";
	cin >> B;

	cout << endl;

	cout << A << " + " << B << " = " << A + B << endl;
	cout << A << " - " << B << " = " << A - B << endl;
	cout << A << " * " << B << " = " << A * B << endl;
	cout << A << " / " << B << " = " << 1.0 * A / B << endl;
	cout << A << " % " << B << " = " << A % B << endl;

    return 0;
}