
#include <iostream>
using namespace std;

int main()
{
	// Calculate Half Of The Number
    cout << "Welcome to The Half Number Calculator!\n\n";
    float Number;

    cout << "Please enter the number?\n";
    cin >> Number;

    float HalfNumber = Number / 2;

    cout << "Half of " << Number << " is " << HalfNumber;

    return 0;
}