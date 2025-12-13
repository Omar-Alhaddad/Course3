
#include <iostream>
using namespace std;

enum enColor { Red, Green, Blue, Yellow, Purple, Orange, Black, White };

enum enGender { Male, Female };

enum enMaritalStatus { Single, Married };

struct stAddress
{
	string City;
	string Country;
	string StreetName;
	string BuildingNo;
	string POBox;
	string ZipCode;
};

struct stContactInfo
{
	stAddress Address;
	string Phone;
	string Email;
};

struct stPerson
{
	string FirstName;
	string LastName;
	stContactInfo ContactInfo;
	float MonthlySalary = 0.0;
	short Age = 0;
	enMaritalStatus MaritalStatus = enMaritalStatus::Single;
	enGender Gender = enGender::Male;
	enColor FavoriteColor = enColor::Blue;
};

static string ColorToString(enColor color)
{
	switch (color)
	{
	case enColor::Red: return "Red";
	case enColor::Green: return "Green";
	case enColor::Blue: return "Blue";
	case enColor::Yellow: return "Yellow";
	case enColor::Purple: return "Purple";
	case enColor::Orange: return "Orange";
	case enColor::Black: return "Black";
	case enColor::White: return "White";
	default: return "Unknown Color";
	}
}

static string GenderToString(enGender gender)
{
	return (gender == enGender::Male ? "Male" : "Female");
}

static string MaritalStatusToString(enMaritalStatus status)
{
	return (status == enMaritalStatus::Married ? "Married" : "Single");
}


int main()
{
	//My Information Card
	stPerson Person;

	Person.FirstName = "Thomas";
	Person.LastName = "Willson";
	Person.Age = 25;
	Person.MonthlySalary = 3000;
	Person.ContactInfo.Email = "Thomasewe@gmail.com";
	Person.ContactInfo.Phone = "+14434342529";
	Person.ContactInfo.Address.City = "Alabama";
	Person.ContactInfo.Address.Country = "USA";
	Person.ContactInfo.Address.StreetName = "1st Main Sreet";
	Person.ContactInfo.Address.POBox = "65640";
	Person.ContactInfo.Address.ZipCode = "00000";
	Person.ContactInfo.Address.BuildingNo = "121";

	Person.Gender = enGender::Male;
	Person.MaritalStatus = enMaritalStatus::Single;
	Person.FavoriteColor = enColor::Purple;

	cout << string('*', 42) << "\n";
	cout << "Name: " << Person.FirstName << " " << Person.LastName << endl;
	cout << "Age : " << Person.Age << endl;
	cout << "Email : " << Person.ContactInfo.Email << endl;
	cout << "Phone : " << Person.ContactInfo.Phone << endl;
	cout << "City : " << Person.ContactInfo.Address.City << endl;
	cout << "Country : " << Person.ContactInfo.Address.Country << endl;
	cout << "Street Name : " << Person.ContactInfo.Address.StreetName << endl;
	cout << "Building No : " << Person.ContactInfo.Address.BuildingNo << endl;
	cout << "PO Box : " << Person.ContactInfo.Address.POBox << endl;
	cout << "Zip Code : " << Person.ContactInfo.Address.ZipCode << endl;
	cout << "Monthly Salary : " << Person.MonthlySalary << endl;
	cout << "Yearly Salary : " << Person.MonthlySalary * 12 << endl;
	cout << "Gender : " << GenderToString(Person.Gender) << endl;
	cout << "Married : " << MaritalStatusToString(Person.MaritalStatus) << endl;
	cout << "Favorite Color : " << ColorToString(Person.FavoriteColor) << endl;
	cout << string('*', 42) << "\n";

	return 0;
}