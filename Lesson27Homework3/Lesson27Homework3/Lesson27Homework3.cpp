
#include <iostream>
#include <string>
using namespace std;

struct Contacts
{
    string Phone;
    string Email;
    string Twitter;
    string Telegram;
};

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
    Contacts Contacts;
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
    const string separator(43, '*');

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

    cout << "Please enter Street Name?" << endl;
    cin.ignore();
    getline(cin, User.Address.Street);

    cout << "Please enter Building Number?" << endl;
    cin >> User.Address.BuildingNumber;

    cout << "Please enter Your Monthly Salary?" << endl;
    cin >> User.MonthlySalary;

    cout << "Please enter Your Gender M/F ?" << endl;
    cin >> User.Gender;

    cout << "Are you married 1/0 ?" << endl;
    cin >> User.isMarried;

    cout << "Please enter Your Phone?" << endl;
    cin >> User.Contacts.Phone;

    cout << "Please enter Your Email?" << endl;
    cin >> User.Contacts.Email;

    cout << "Please enter Your Twitter Username?" << endl;
    cin >> User.Contacts.Twitter;

    cout << "Please enter Your Telegram Username?" << endl;
    cin >> User.Contacts.Telegram;

    if (User.Contacts.Twitter.at(0) != '@')
    {
        User.Contacts.Twitter = '@' + User.Contacts.Twitter;
    }

    if (User.Contacts.Telegram.at(0) != '@')
    {
        User.Contacts.Telegram = '@' + User.Contacts.Telegram;
    }

    cout << separator << endl;
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
    cout << "Phone Number : " << User.Contacts.Phone << endl;
    cout << "Email : " << User.Contacts.Email << endl;
    cout << "Twitter : " << User.Contacts.Twitter << endl;
    cout << "Telegram : " << User.Contacts.Telegram << endl;
    cout << separator << endl;

    return 0;
}