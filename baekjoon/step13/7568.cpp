#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

struct Person
{
    int weight;
    int height;
};

int main()
{
    int N;
    cin >> N;
    Person p[N];

    for (int i = 0; i < N; i++)
        cin >> p[i].weight >> p[i].height;

    for (int i = 0; i < N; i++)
    {
        int rank = 1;
        for (int j = 0; j < N; j++)
            if (p[i].weight < p[j].weight && p[i].height < p[j].height)
                rank++;
        printf("%d ", rank);
    }
    cout << '\n';

    return 0;
}