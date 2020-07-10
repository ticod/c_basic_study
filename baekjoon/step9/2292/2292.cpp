#include <iostream>
using namespace std;

int bulzip(int i)
{
    if (i != 1)
        return ((i - 1) * 6) + bulzip(i - 1);
    else
        return 1;
}

int main()
{
    int N;
    cin >> N;

    // bulzip(i) >= N > bulzip(i-1)
    // N-1 / 6 => 0.xx~1 / 1.xx~3 / 3.xx~6 / ...
    //

    int i = 1;
    for (; bulzip(i) < N; i++)
        ;
    cout << i << endl;
    return 0;
}