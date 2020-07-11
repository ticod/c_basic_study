#include <iostream>
using namespace std;

long long int get_step(long long int d)
{
    long long int i = 1;
    for (; i * (i + 1) < d; i++)
        ;
    return i;
}

long long int get_times(long long int d)
{
    long long int s = get_step(d);
    if (d <= s * s)
        return 2 * s - 1;
    else
        return 2 * s;
}

int main()
{
    int T;
    cin >> T;
    int x[T], y[T];
    for (int i = 0; i < T; i++)
    {
        cin >> x[i] >> y[i];
    }
    for (int i = 0; i < T; i++)
    {
        long long int d = y[i] - x[i];
        cout << get_times(d) << endl;
    }

    return 0;
}