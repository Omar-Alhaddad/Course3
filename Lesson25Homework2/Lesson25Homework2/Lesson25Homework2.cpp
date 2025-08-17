
#include <iostream>
using namespace std;

int main()
{
    // Relational Operators & Logical Operators Practice

    cout << "_________________________________________" << endl;
    cout << "(5 > 6 AND 7 == 7) OR (1 OR 0) : " << ((5 > 6 && 7 == 7) || (1 || 0)) << endl; //1
    cout << "NOT (5 > 6 AND 7 == 7) OR (1 OR 0) : " << (!(5 > 6 && 7 == 7) || (1 || 0)) << endl; //1
    cout << "NOT (5 > 6 AND 7 == 7) OR NOT (1 OR 0) : " << (!(5 > 6 && 7 == 7) || !(1 || 0)) << endl; //1
    cout << "NOT (5 > 6 OR 7 == 7) AND NOT (1 OR 0) : " << (!(5 > 6 || 7 == 7) && !(1 || 0)) << endl; //0
    cout << "((5 > 6 AND 7 <= 8) OR (8 > 1 AND 4 <= 3)) AND True : " << (((5 > 6 && 7 <= 8) || (8 > 1 && 4 <= 3)) && true) << endl; //0
    cout << "((5 > 6 AND NOT (7 <= 8)) AND (8 > 1 OR 4 <= 3)) OR True : " << (((5 > 6 && !(7 <= 8)) && (8 > 1 || 4 <= 3)) || true) << endl; //1
    cout << "_________________________________________" << endl;

    return 0;
}