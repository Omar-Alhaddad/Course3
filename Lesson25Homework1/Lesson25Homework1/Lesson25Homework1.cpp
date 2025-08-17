
#include <iostream>
using namespace std;

int main()
{
    // Relational Operators & Logical Operators Practice

    cout << "12 >= 12 : " << (12 >= 12) << endl; //1
    cout << "12 > 7 : " << (12 > 7) << endl; //1
    cout << "8 < 6 : " << (8 < 6) << endl; //0
    cout << "8 == 8 : " << (8 == 8) << endl; //1
    cout << "12 <= 12 : " << (12 <= 12) << endl; //1
    cout << "7 == 5 : " << (7 == 5) << endl; //0
    cout << "_________________________________________" << endl;

    cout << "NOT (12 >= 12) : " << !(12 >= 12) << endl; //0
    cout << "NOT (12 < 7) : " << !(12 < 7) << endl; //1
    cout << "NOT (8 < 6) : " << !(8 < 6) << endl; //1
    cout << "NOT (8 == 8) : " << !(8 == 8) << endl; //0
    cout << "NOT (12 <= 12) : " << !(12 <= 12) << endl; //0
    cout << "NOT (7 == 5) : " << !(7 == 5) << endl; //1
    cout << "_________________________________________" << endl;

    cout << "1 AND 1 : " << (1 && 1) << endl; //1
    cout << "True AND 0 : " << (true && 0) << endl; //0
    cout << "0 OR 1 : " << (0 || 1) << endl; //1
    cout << "0 OR 0 : " << (0 || 0) << endl; //0
    cout << "NOT 0 : " << !(0) << endl; //1
    cout << "NOT (1 OR 0) : " << !(1 || 0) << endl; //0
    cout << "_________________________________________" << endl;

    cout << "(7 == 7) AND (7 > 5) : " << ((7 == 7) && (7 > 5)) << endl; //1
    cout << "(7 == 7) AND (7 < 5) : " << ((7 == 7) && (7 < 5)) << endl; //0
    cout << "(7 == 7) OR (7 < 5) : " << ((7 == 7) || (7 < 5)) << endl; //1
    cout << "(7 < 7) OR (7 > 5) : " << ((7 < 7) || (7 > 5)) << endl; //1
    cout << "NOT (7 == 7) AND (7 > 5) : " << (!(7 == 7) && (7 > 5)) << endl; //0
    cout << "(7 == 7) AND NOT (7 < 5) : " << ((7 == 7) && !(7 < 5)) << endl; //1
    cout << "_________________________________________" << endl;

    return 0;
}