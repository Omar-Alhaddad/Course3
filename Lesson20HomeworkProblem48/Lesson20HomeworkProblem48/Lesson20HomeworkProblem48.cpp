
#include <iostream>
using namespace std;

int main()
{
    // Calculate Monthly Installment for a Loan
    cout << "Welcome to the Monthly Installment for a Loan Calculator!\n\n";

    int LoanAmount, HowManyMonths;

    cout << "Please enter the loan amount?\n";
    cin >> LoanAmount;
    cout << "How many months you need to settle the loan?\n";
    cin >> HowManyMonths;

    float MonthlyInstallment = float(LoanAmount) / HowManyMonths;

    cout << "Your monthly installment is: " << MonthlyInstallment << endl;

    return 0;
}