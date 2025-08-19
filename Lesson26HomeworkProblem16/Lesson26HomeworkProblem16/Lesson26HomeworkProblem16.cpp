
#include <iostream>
#include<cmath>
using namespace std;

int main()
{
	// Calculate the Area of a Rectangle Given the Length of One Side and the Diagonal
	cout << "Welcome to the Rectangle Area Calculator from One Side and the Diagonal!\n\n";

	float SideLength = 0, Diagonal = 0;

	cout << "Please enter the side length of the rectangle?\n";
	cin >> SideLength;
	cout << "Please enter the diagonal length of the rectangle?\n";
	cin >> Diagonal;

	//double Area = SideLength * sqrt((Diagonal * Diagonal) - (SideLength * SideLength));
	double Area = SideLength * sqrt(pow(Diagonal, 2) - pow(SideLength, 2));

	cout << "\nThe area of the rectangle is: " << Area << endl;

    return 0;
}