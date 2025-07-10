
#include <iostream>
using namespace std;

int main()
{
    // Calculate the Total Amount of Money in Dollars and Pennies
    cout << "Welcome to the Money Calculator!\n\n";

    int Pennies, Nickels, Dimes, Quarters, Dollars;

    cout << "Please enter the Pennies?\n";
    cin >> Pennies;
    cout << "Please enter the Nickels?\n";
    cin >> Nickels;
    cout << "Please enter the Dimes?\n";
    cin >> Dimes;
    cout << "Please enter the Quarters?\n";
    cin >> Quarters;
    cout << "Please enter the Dollars?\n";
    cin >> Dollars;

    int TotalPennies = Pennies + Nickels * 5 + Dimes * 10 + Quarters * 25 + Dollars * 100;
    float TotalDollars = TotalPennies / 100.0;

    cout << "\nTotal amount in pennies: " << TotalPennies << " Pennies";
    cout << "\nTotal amount in dollars: " << TotalDollars << " Dollars";

    return 0;
}