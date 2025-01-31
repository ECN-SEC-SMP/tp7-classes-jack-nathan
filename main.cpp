#include <iostream>
#include "src/Point.hpp"

using namespace std;

int main()
{
    Point p1(2, 3);
    Point p2(4, 5);

    cout << "p1 = " << p1 << endl;
    cout << "p2 = " << p2 << endl;

    p1 += p2;
    cout << "\nAprès p1 += p2 :" << endl;
    cout << "p1 = " << p1 << endl;

    return 0;
}