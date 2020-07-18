#include <iostream>
using namespace std;

int fac(int N)
{
    if(N == 0)
        return 1;
    else
        return N * fac(N-1);
}

int main()
{
    int N;
    cin >> N;

    cout << fac(N) << '\n';
    
    return 0;
}