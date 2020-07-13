#include <iostream>
using namespace std;

int main()
{
    long long int M, N;
    cin >> M >> N;
    unsigned int buf[N + 1];

    buf[0] = 0, buf[1] = 0;
    for (long long int i = 2; i <= N; i++)
    {
        buf[i] = 1;
    }

    for (long long int i = 2; i * i <= N; i++)
    {
        if (!buf[i])
        {
            continue;
        }
        for (long long int j = 2; i * j <= N; j++)
        {
            buf[i * j] = 0;
        }
    }
    for (int i = M; i <= N; i++)
    {
        if (buf[i])
        {
            cout << i << '\n';
        }
    }

    return 0;
}