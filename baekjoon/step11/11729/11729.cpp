#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

void solve(int n, int from, int by, int to)
{
    if(n == 1)
    {
        printf("%d %d\n", from, to); // F -> T
    }
    else
    {
        solve(n-1, from, to, by); // F -> B
        printf("%d %d\n", from, to); // F -> T
        solve(n-1, by, from, to); // B -> T
    }
}

int main()
{
    int n;
    cin >> n;

    int count = 1;
    for(int i = 0; i < n; i++)
        count *= 2;
    cout << --count << '\n';
    solve(n, 1, 2, 3);
    
    return 0;
}