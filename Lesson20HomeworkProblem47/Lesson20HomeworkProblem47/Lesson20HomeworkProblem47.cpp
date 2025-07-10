
#include <iostream>
using namespace std;

int main()
{
    // Calculate the Number of Months Required to Settle the Loan
    cout << "Welcome to the Loan Settlement Calculator!\n\n";

    int LoanAmount, MonthlyInstallment;

    cout << "Please enter the loan amount?\n";
    cin >> LoanAmount;
    cout << "Please enter the monthly installment?\n";
    cin >> MonthlyInstallment;

    float TotalMonths = ceil(float(LoanAmount) / MonthlyInstallment);

    cout << "\nThe total months required to settle the loan is: " << TotalMonths << " Months" << endl;

    return 0;
}