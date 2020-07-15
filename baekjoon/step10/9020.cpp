#include <iostream>
using namespace std;

int primeArray[10000];

void primeArray_init()
{
    primeArray[0] = 0, primeArray[1] = 0;

    for (int i = 2; i < 10000; i++)
        primeArray[i] = 1;

    for (int i = 2; i * i <= 10000; i++)
    {
        if (!primeArray[i])
            continue;
        for (int j = i * i; j <= 10000; j += i)
            primeArray[j] = 0;
    }
}

int main()
{
    int T;
    cin >> T;
    primeArray_init();

    for (int i = 0; i < T; i++)
    {
        int even;
        cin >> even;
        for (int j = even / 2; j <= even - 2; j--)
            if (primeArray[j] && primeArray[even - j])
            {
                cout << j << ' ' << even - j << '\n';
                break;
            }
    }

    return 0;
}