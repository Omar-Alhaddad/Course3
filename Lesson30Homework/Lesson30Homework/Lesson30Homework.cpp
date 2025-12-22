
#include <iostream>
#include <string>  // For string operations
#include <format> // C++20 feature; if not available, consider using <sstream> for formatting
using namespace std;

int main()
{
	// Type Conversion in C++

	// Convert string st1 to int, float, double
	string st1 = "43.22";

	// Warning: Converting "43.22" to int loses decimal portion
	int st1ToInt = stoi(st1);
	cout << "The integer value of string \"st1\" is: " << st1ToInt << "\n";

	float st1ToFloat = stof(st1);
	cout << "The float value of string \"st1\" is: " << st1ToFloat << "\n";

	double st1ToDouble = stod(st1);
	cout << "The double value of string \"st1\" is: " << st1ToDouble << "\n";

	// Convert integer N1 to string
	int N1 = 20;

	string N1ToString = to_string(N1);
	cout << "The string value of integer \"N1\" is: " << N1ToString << "\n";

	// Convert double N2 to string
	double N2 = 33.5;

	string N2ToString = to_string(N2);
	cout << "The string value of double \"N2\" is: " << N2ToString << "\n";

	string N2ToStringFormat = format("{:.2f}", N2); // Format to 2 decimal places
	cout << "The string value of double \"N2\" is: " << N2ToStringFormat << "\n";

	// Convert float N3 to string
	float N3 = 55.23f;

	string N3ToString = to_string(N3);
	cout << "The string value of float \"N3\" is: " << N3ToString << "\n";

	string N3ToStringFormat = format("{:.2f}", N3); // Format to 2 decimal places
	cout << "The string value of float \"N3\" is: " << N3ToStringFormat << "\n";

	// Convert float N3 to Integer
	int N3ToInt1 = N3; // Implicit conversion from float to int (avoid)
	cout << "The integer value of float \"N3\" is: " << N3ToInt1 << "\n";

	int N3ToInt2 = (int)N3; // C-style cast Explicit conversion from float to int (legacy)
	cout << "The integer value of float \"N3\" is: " << N3ToInt2 << "\n";

	int N3ToInt3 = int(N3); // Functional cast Explicit conversion from float to int (rarely used)
	cout << "The integer value of float \"N3\" is: " << N3ToInt3 << "\n";

	int N3ToInt4 = static_cast<int>(N3); // C++ style cast Explicit conversion from float to int (BEST)
	cout << "The integer value of float \"N3\" is: " << N3ToInt4 << "\n";

    return 0;
}