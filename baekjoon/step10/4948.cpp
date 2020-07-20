#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n != 0)
    {
        unsigned char primeArray[2 * n + 1];
        primeArray[0] = 0, primeArray[1] = 0;
        for (int i = 2; i <= 2 * n; i++)
            primeArray[i] = 1;

        for (int i = 2; i * i <= 2 * n; i++)
        {
            if (!primeArray[i])
                continue;
            for (int j = 2; i * j <= 2 * n; j++)
                primeArray[i * j] = 0;
        }

        int count = 0;
        for (int i = n + 1; i <= 2 * n; i++)
            if (primeArray[i])
                count++;
        cout << count << '\n';
        cin >> n;
    }
    return 0;
}