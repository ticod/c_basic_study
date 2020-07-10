#include <iostream>
using namespace std;
// 계차 수열 원리

int main()
{
    int N;
    cin >> N;

    // 계차수열
    // 1 + ( 6 * (i*(i-1)/2))
    int i = 1;
    for (; 3 * i * (i - 1) + 1 < N; i++)
        ;
    cout << i << endl;
    return 0;
}