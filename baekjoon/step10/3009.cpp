#include <iostream>
using namespace std;

int main()
{
    int x[4], y[4];
    int sum_x = 0, sum_y = 0;
    for (int i = 0; i < 3; i++)
    {
        cin >> x[i] >> y[i];

        sum_x += x[i];
        if (x[i] != x[i - 1])
            x[3] = (x[i] + x[i - 1]) * 2;

        sum_y += y[i];
        if (y[i] != y[i - 1])
            y[3] = (y[i] + y[i - 1]) * 2;
    }
    cout << x[3] - sum_x << ' ' << y[3] - sum_y << '\n';

    return 0;
}