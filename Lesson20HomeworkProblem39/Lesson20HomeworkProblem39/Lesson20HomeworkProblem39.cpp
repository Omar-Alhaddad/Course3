
#include <iostream>
using namespace std;

int main()
{
	// Calculates the Remainder to be Paid Back After a Bill is Paid
	cout << "Welcome to the Remainder Calculator!\n\n";

	int TotalBill, CashPaid;

	cout << "Please enter the total bill amount?\n";
	cin >> TotalBill;
	cout << "Please enter the cash paid?\n";
	cin >> CashPaid;

	int Remainder = CashPaid - TotalBill;

	cout << "\nThe remainder to be paid back is: " << Remainder << endl;

    return 0;
}