#include <iostream>
using namespace std;

int main()
{
    int x, y, w, h;
    cin >> x >> y >> w >> h;
    // x, y, w-x, h-y 비교
    int min = x;
    if (min > y)
        min = y;
    if (min > w - x)
        min = w - x;
    if (min > h - y)
        min = h - y;

    cout << min << '\n';
    return 0;
}