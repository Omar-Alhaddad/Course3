
#include <iostream>
using namespace std;

int main()
{
    // Calculate The Sum of Three Numbers
    cout << "Welcome to The Sum of Three Numbers Calculator!\n\n";

    int Number1, Number2, Number3;

    cout << "Please enter the first number?\n";
    cin >> Number1;
    cout << "Please enter the second number?\n";
    cin >> Number2;
    cout << "Please enter the third number?\n";
    cin >> Number3;

    int SumOfNumbers = Number1 + Number2 + Number3;

    cout << endl;
    cout << Number1 << " + " << Number2 << " + " << Number3 << " = " << SumOfNumbers << std::endl;

    return 0;
}