#include <iostream>
using namespace std;

int main()
{
    long A, B, C;
    cin >> A >> B >> C;
    // A + Bx <= Cx
    // A <= (C-B)x
    // A/(C-B) <= x

    cout << ((C > B) ? (A / (C - B)) + 1 : -1);

    return 0;
}