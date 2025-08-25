
#include <iostream>
using namespace std;

struct UserInfo
{
    string Name;
    short Age;
    string City;
    string Country;
    float MonthlySalary;
    char Gender;
    bool isMarried;
};

int main()
{
    // User Information Card Application

    UserInfo User;

    cout << "Please enter Your Name?" << endl;
    cin >> User.Name;

    cout << "Please enter Your Age?" << endl;
    cin >> User.Age;

    cout << "Please enter Your City?" << endl;
    cin >> User.City;

    cout << "Please enter Your Country?" << endl;
    cin >> User.Country;

    cout << "Please enter Your Monthly Salary?" << endl;
    cin >> User.MonthlySalary;

    cout << "Please enter Your Gender M/F ?" << endl;
    cin >> User.Gender;

    cout << "Are you married 1/0 ?" << endl;
    cin >> User.isMarried;

    cout << "*****************************************\n";
    cout << "Name: " << User.Name << endl;
    cout << "Age : " << User.Age << endl;
    cout << "City : " << User.City << endl;
    cout << "Country : " << User.Country << endl;
    cout << "Monthly Salary : " << User.MonthlySalary << endl;
    cout << "Yearly Salary : " << User.MonthlySalary * 12 << endl;
    cout << "Gender : " << User.Gender << endl;
    cout << "Married : " << User.isMarried << endl;
    cout << "*****************************************\n";

    return 0;
}