#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    // 3x + 5y = N
    // x + y -> 출력
    // y가 클수록 x+y는 작아짐

    int output = -1;

    for (int i = 0; 5 * i <= N; i++)
        if (((N - (5 * i)) % 3) == 0)
            output = i + ((N - (5 * i)) / 3);

    cout << output;
    return 0;
}