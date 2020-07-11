#include <iostream>
using namespace std;

int main()
{
    int T;
    cin >> T;
    int H[T], W[T], N[T];
    for (int i = 0; i < T; i++)
    {
        cin >> H[i] >> W[i] >> N[i];
    }

    for (int i = 0; i < T; i++)
    {
        cout << (N[i] % H[i] == 0 ? H[i] : N[i] % H[i]);
        if (((N[i] - 1) / H[i]) + 1 < 10)
            cout << 0;
        cout << ((N[i] - 1) / H[i]) + 1 << endl;
    }
    return 0;
}