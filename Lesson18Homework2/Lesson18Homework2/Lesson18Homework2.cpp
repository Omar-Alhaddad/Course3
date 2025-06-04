
#include <iostream>
using namespace std;

int main()
{
    // Sum of Three Numbers
    int a, b, c;

    cout << "Please enter the first number?" << endl;
    cin >> a;

    cout << "Please enter the second number?" << endl;
    cin >> b;

    cout << "Please enter the third number?" << endl;
    cin >> c;

    int Sum = a + b + c;

    cout << a << " + " << endl;
    cout << b << " + " << endl;
    cout << c << endl;
    cout << "--------------" << endl;

    cout << Sum << endl;

    return 0;
}