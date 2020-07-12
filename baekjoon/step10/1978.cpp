#include <iostream>
using namespace std;

int main()
{
    int N, count = 0; // count : 소수의 수
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;

        int k = 0;
        for (int j = 1; j <= num; j++)
        {
            if (num % j == 0)
                k++;
        }
        if (k == 2)
            count++;
    }

    cout << count << endl;
    return 0;
}