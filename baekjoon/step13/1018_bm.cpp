#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

const unsigned char chess[8] =
    {0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55};

int main()
{
    int N, M;
    cin >> N >> M;
    unsigned long long int inChess[N] = {
        0,
    };

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            char ch;
            cin >> ch;
            if (ch == 'W')
                inChess[i] = inChess[i] | (1 << j);
        }
    }

    int min = 64;
    for (int i = 0; i <= N - 8; i++)
    {
        for (int j = 0; j <= M - 8; j++)
        {
            unsigned int diff[2] = {0, 0};
            for (int k = 0; k < 8; k++)
            {
                unsigned char temp;
                temp = (((inChess[i + k] >> (j)) & 0b11111111) ^ chess[k]);
                for (int l = 0; l < 8; l++)
                    diff[0] += (temp >> (l)) & 1;
                temp = (((inChess[i + k] >> (j)) & 0b11111111) ^ (~chess[k]));
                for (int l = 0; l < 8; l++)
                    diff[1] += (temp >> (l)) & 1;
            }

            if (min > diff[0])
                min = diff[0];
            if (min > diff[1])
                min = diff[1];
        }
    }
    cout << min << '\n';
    return 0;
}