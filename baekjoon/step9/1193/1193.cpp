#include <iostream>

using namespace std;

int sigma(int x)
{
    return x * (x - 1) / 2 + (x - 1) + 1;
}

int main()
{
    int X;
    cin >> X;

    int a = 1;
    for (; sigma(a) < X; a++)
        ;

    if (a % 2 == 0)
        cout << a - (sigma(a) - X) << "/" << sigma(a) - X + 1 << endl;
    else
        cout << sigma(a) - X + 1 << "/" << a - (sigma(a) - X) << endl;

    return 0;
}