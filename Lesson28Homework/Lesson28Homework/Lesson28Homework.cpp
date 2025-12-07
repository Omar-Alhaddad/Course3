
#include <iostream>
using namespace std;

enum enColor { Red, Green, Blue, Yellow, Purple, Orange, Black, White };

enum enGender { Male, Female };

enum enMaritalStatus { Single, Married };

struct stAddress {

	string City;
	string Country;
};

struct stPerson {

	stAddress Address;
	string FirstName;
	string LastName;
	float MonthlySalary;
	short Age;
	enGender Gender;
	enMaritalStatus MaritalStatus;
	enColor FavoriteColor;
};

string ColorToString(enColor color) {

	switch (color) {
	case Red: return "Red";
	case Green: return "Green";
	case Blue: return "Blue";
	case Yellow: return "Yellow";
	case Purple: return "Purple";
	case Orange: return "Orange";
	case Black: return "Black";
	case White: return "White";
	default: return "Color Not Find";
	}
}

string GenderToString(enGender gender) {

	return (gender == Male ? "Male" : "Female");
}

string MaritalStatusToString(enMaritalStatus status) {

	return (status == Married ? "Married" : "Single");
}

int main()
{
	//My Information Card
	stPerson Person;
	unsigned short tempInput;

	cout << "Please enter your first name?" << endl;
	cin >> Person.FirstName;

	cout << "Please enter your last name?" << endl;
	cin >> Person.LastName;

	cout << "Please enter your age?" << endl;
	cin >> Person.Age;

	cout << "Please enter your city?" << endl;
	cin >> Person.Address.City;

	cout << "Please enter your Country?" << endl;
	cin >> Person.Address.Country;

	cout << "Please enter your monthly salary?" << endl;
	cin >> Person.MonthlySalary;

	cout << "Please enter your gender (0. Male, 1. Female):" << endl;
	cin >> tempInput;
	Person.Gender = (enGender)tempInput;

	cout << "What is your marital status (0. Single, 1. Married)?" << endl;
	cin >> tempInput;
	Person.MaritalStatus = (enMaritalStatus)tempInput;

	cout << "What is your favorite color?" << endl;
	cout << "0. Red, 1. Green, 2. Blue, 3. Yellow, 4. Purple, 5. Orange, 6. Black, 7. White" << endl;
	cin >> tempInput;
	Person.FavoriteColor = (enColor)tempInput;

	cout << "*****************************************\n";
	cout << "Name: " << Person.FirstName << " " << Person.LastName << endl;
	cout << "Age : " << Person.Age << " years" << endl;
	cout << "City : " << Person.Address.City << endl;
	cout << "Country : " << Person.Address.Country << endl;
	cout << "Monthly Salary : " << Person.MonthlySalary << endl;
	cout << "yearly Salary : " << Person.MonthlySalary * 12 << endl;
	cout << "Gender : " << GenderToString(Person.Gender) << endl;
	cout << "Married : " << MaritalStatusToString(Person.MaritalStatus) << endl;
	cout << "Favorite Color : " << ColorToString(Person.FavoriteColor) << endl;
	cout << "*****************************************\n";

	return 0;
}