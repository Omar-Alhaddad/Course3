
#include <iostream>
using namespace std;

int main()
{
    //My Information Card
    string Name;
    short Age;
    string City;
    string Country;
    float MonthlySalary;
    char Gender;
    bool isMarried;

    cout << "Please enter Your Name?" << endl;
    cin >> Name;

    cout << "Please enter Your Age?" << endl;
    cin >> Age;

    cout << "Please enter Your City?" << endl;
    cin >> City;

    cout << "Please enter Your Country?" << endl;
    cin >> Country;

    cout << "Please enter Your Monthly Salary?" << endl;
    cin >> MonthlySalary;

    cout << "Please enter Your Gender M/F ?" << endl;
    cin >> Gender;

    cout << "Are you married 1/0 ?" << endl;
    cin >> isMarried;

    cout << "*****************************************\n";
    cout << "Name: " << Name << endl;
    cout << "Age : " << Age << endl;
    cout << "City : " << City << endl;
    cout << "Country : " << Country << endl;
    cout << "Monthly Salary : " << MonthlySalary << endl;
    cout << "Yearly Salary : " << MonthlySalary * 12 << endl;
    cout << "Gender : " << Gender << endl;
    cout << "Married : " << isMarried << endl;
    cout << "*****************************************\n";

    return 0;
}