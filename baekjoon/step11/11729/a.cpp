#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

void solve(int n, int from, int by, int to)
{
    if(n == 1)
    {
        printf("%d %d\n", from, to);
    }
    else
    {
        solve(n-1, from, to, by);
        printf("%d %d\n", from, to);
        solve(n-1, by, from, to);
    }
    
}

int main()
{
    int n;
    cin >> n;

    solve(n, 1, 2, 3);
    
    return 0;
}