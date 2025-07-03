
#include <iostream>
using namespace std;

int main()
{
    // Swaps Two Numbers Using a Temporary Variable
    cout << "Welcome to Swaps Two Numbers Using a Temporary Variable!\n\n";

    int Number1, Number2, Temp;

    cout << "Please enter the first number?\n";
    cin >> Number1;
    cout << "Please enter the second number?\n";
    cin >> Number2;

    cout << endl;
    cout << Number1 << endl;
    cout << Number2 << endl;

    Temp = Number1;
    Number1 = Number2;
    Number2 = Temp;

    cout << endl;
    cout << Number1 << endl;
    cout << Number2 << endl;

	cout << string(50, '-') << endl;

    // Swaps Two Numbers Using XOR Bitwise Operator
    cout << "Welcome to Swaps Two Numbers Using XOR Bitwise Operator\n\n";

    int Num1, Num2;

    cout << "Please enter the first number?\n";
    cin >> Num1;
    cout << "Please enter the second number?\n";
    cin >> Num2;

    cout << endl;
    cout << Num1 << endl;
    cout << Num2 << endl;

    Num1 = Num1 ^ Num2;
    Num2 = Num1 ^ Num2;
    Num1 = Num1 ^ Num2;

    cout << endl;
    cout << Num1 << endl;
    cout << Num2 << endl;

    return 0;
}