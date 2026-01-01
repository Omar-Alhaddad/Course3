
#include <iostream>
#include <string>
using namespace std;

void mySumProcedure() {

	int Number1, Number2;

	cout << "Please enter Number1?" << endl;
	cin >> Number1;

	cout << "\nPlease enter Number2?" << endl;
	cin >> Number2;

	cout << string(26, '*') << endl;

	cout << Number1 + Number2 << endl;
}

int mySumFunction() {

	int Number1, Number2;

	cout << "Please enter Number1?" << endl;
	cin >> Number1;

	cout << "\nPlease enter Number2?" << endl;
	cin >> Number2;

	cout << string(26, '*') << endl;

	return Number1 + Number2;
}

int main()
{
	// Call the procedure
	mySumProcedure();

	cout << string(26, '_') << endl;

	// Call the function
	cout << mySumFunction() << endl;

	return 0;
}