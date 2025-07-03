
#include <iostream>
using namespace std;

int main()
{
    // Calculates the Area of a Triangle Given its Base and Height
    cout << "Welcome to the Triangle Area Calculator!\n\n";

    int Base, Height;

    cout << "Please enter the base?\n";
    cin >> Base;
    cout << "Please enter the height?\n";
    cin >> Height;

    float Area = 0.5 * Base * Height;
    //float TriangleArea = Base / 2.0 * Height;

    cout << "\nThe area of the triangle is: " << Area << endl;

    return 0;
}