
#include <iostream>
using namespace std;

int main()
{
    // Calculate the Total Bill Value With a 10% Service Fee and 16% Sales Tax
    cout << "Welcome to the Total Bill Value Calculator!\n\n";

    int BillValue;

    cout << "Please enter the bill value?\n";
    cin >> BillValue;

    float TotalBill = BillValue * 1.1;
    TotalBill *= 1.16;

    cout << "\nThe total bill value is: " << TotalBill << endl;

    return 0;
}