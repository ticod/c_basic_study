#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int solve(int M)
{
    return M +
           M / 1000000 +
           M % 1000000 / 100000 +
           M % 100000 / 10000 +
           M % 10000 / 1000 +
           M % 1000 / 100 +
           M % 100 / 10 +
           M % 10;
}

int main()
{
    int N;
    cin >> N;

    int min = 0;
    for (int i = N - 1; i >= 1; i--)
        if (solve(i) == N)
            min = i;

    cout << min << '\n';

    return 0;
}