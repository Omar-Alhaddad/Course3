
#include <iostream>
using namespace std;

int main()
{
    // Calculates the Area of a Rectangle Given its Length and Width.
    cout << "Welcome to the Rectangle Area Calculator!\n\n";

    int Length, Width;

    cout << "Please enter Length?\n";
    cin >> Length;
    cout << "Please enter Width?\n";
    cin >> Width;

    int Area = Length * Width;

    cout << "\nThe area of the rectangle is: " << Area << endl;

    return 0;
}