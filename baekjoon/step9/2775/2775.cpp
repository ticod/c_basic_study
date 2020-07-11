#include <iostream>
using namespace std;

int calc_person(int k, int n)
{
    if (k == 0)
        return n;
    else if (n == 1)
        return 1;
    else
        return calc_person(k, n - 1) + calc_person(k - 1, n);
}

int main()
{
    int T;
    cin >> T;
    // 테스트 케이스 수
    int k[T], n[T];
    for (int i = 0; i < T; i++)
    {
        cin >> k[i];
        cin >> n[i];
    }
    // k : 층 , n : 호
    // 층은 0부터, 호는 1부터
    // 0층의 i호에는 i명이 산다 -> 1호
    for (int i = 0; i < T; i++)
    {
        cout << calc_person(k[i], n[i]) << endl;
    }
}