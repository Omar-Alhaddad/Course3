
#include <iostream>
using namespace std;

int main()
{
    //My Information Card
    string Name = "Omar Al-haddad";
    short Age = 27;
    string City = "Mukalla";
    string Country = "Yemen";
    float MonthlySalary = 5000;
    float YearlySalary = MonthlySalary * 12;
    char Gender = 'M';
    bool isMarried = false;

    cout << "*****************************************\n";
    cout << "Name: " << Name << endl;
    cout << "Age : " << Age << " Years" << endl;
    cout << "City : " << City << endl;
    cout << "Country : " << Country << endl;
    cout << "Monthly Salary : " << MonthlySalary << endl;
    cout << "Yearly Salary : " << YearlySalary << endl;
    cout << "Gender : " << Gender << endl;
    cout << "Married : " << isMarried << endl;
    cout << "*****************************************\n";

    return 0;
}