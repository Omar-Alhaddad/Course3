
#include <iostream>
#include <string>
using namespace std;

int main()
{
	// String Operations
	string String1, String2, String3;

	cout << "Please enter String1 ?" << endl;
	getline(cin, String1);

	cout << "\nPlease enter String2 ?" << endl;
	cin >> String2;

	cout << "\nPlease enter String3 ?" << endl;
	cin >> String3;

	cout << string(46, '*') << endl;
	cout << "The Length of String1 is " << String1.length() << endl;

	cout << "Character at index 0,2,4,7 are: " << String1[0] << " " << String1[2] << " " << String1[4] << " " << String1[7] << endl;

	cout << "Concatenating String2 and String3 = " << String2 + String3 << endl;

	// Convert String2 and String3 to integers and multiply them
	try {
		int Result = stoi(String2) * stoi(String3);
		cout << String2 << " * " << String3 << " = " << Result << endl;
	}
	catch (const invalid_argument& e) {
		cerr << "Error: Invalid number format entered." << endl;
	}
	catch (const out_of_range e) {
		cerr << "Error: Number is too large." << endl;
	}

    return 0;
}