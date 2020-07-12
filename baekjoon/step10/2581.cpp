#include <iostream>
using namespace std;

int main()
{
    int M, N;
    cin >> M >> N;
    int sum = 0, min = N;

    for (int i = M; i <= N; i++)
    {
        int k = 0;
        for (int j = 1; j <= i; j++)
        {
            if (i % j == 0)
                k++;
        }
        if (k == 2)
        {
            sum += i;
            if (sum == i)
                min = i;
        }
    }
    if (sum == 0)
        cout << -1 << endl;
    else
        cout << sum << endl
             << min << endl;
    return 0;
}