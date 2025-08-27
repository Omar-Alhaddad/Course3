
#include <iostream>
#include <string>
using namespace std;

struct Address
{
    string City;
    string Country;
    string PostalCode;
    string Street;
    string BuildingNumber;
};

struct UserInfo
{
    Address Address;
    string Name;
    short Age;
    double MonthlySalary;
    char Gender;
    bool isMarried;
};

int main()
{
    // User Information Card Application

    UserInfo User;

    cout << "Please enter Your Name?" << endl;
    getline(cin, User.Name);

    cout << "Please enter Your Age?" << endl;
    cin >> User.Age;

    cout << "Please enter Your City?" << endl;
    cin >> User.Address.City;

    cout << "Please enter Your Country?" << endl;
    cin >> User.Address.Country;

    cout << "Please enter Your Postal Code?" << endl;
    cin >> User.Address.PostalCode;
    cin.ignore();

    cout << "Please enter Street Name?" << endl;
    getline(cin, User.Address.Street);

    cout << "Please enter Building Number?" << endl;
    cin >> User.Address.BuildingNumber;

    cout << "Please enter Your Monthly Salary?" << endl;
    cin >> User.MonthlySalary;

    cout << "Please enter Your Gender M/F ?" << endl;
    cin >> User.Gender;

    cout << "Are you married 1/0 ?" << endl;
    cin >> User.isMarried;

    cout << string(43, '*') << endl;
    cout << "Name: " << User.Name << endl;
    cout << "Age : " << User.Age << endl;
    cout << "City : " << User.Address.City << endl;
    cout << "Country : " << User.Address.Country << endl;
    cout << "Monthly Salary : " << User.MonthlySalary << endl;
    cout << "Yearly Salary : " << User.MonthlySalary * 12 << endl;
    cout << "Gender : " << User.Gender << endl;
    cout << "Married : " << User.isMarried << endl;
    cout << "Postal Code : " << User.Address.PostalCode << endl;
    cout << "Street Name : " << User.Address.Street << endl;
    cout << "Building Number : " << User.Address.BuildingNumber << endl;
    cout << string(43, '*') << endl;

    return 0;
}