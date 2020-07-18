#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    int card[N];
    for(int i = 0; i < N; i++)
        cin >> card[i];
    
    int sum = 0;
    for(int i = 0; i < N-2; i++)
    {
        for(int j = i+1; j < N-1; j++)
        {
            for(int k = j+1; k < N; k++)
            {
                if(card[i] + card[j] + card[k] > sum
                    && card[i] + card[j] + card[k] <= M)
                    sum = card[i] + card[j] + card[k];
            }
        }
    }

    cout << sum << '\n';
    
    return 0;
}