#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

const char base[3][3] = {
    '*','*','*',
    '*',' ','*',
    '*','*','*'
};
char star[6580][6580] = {0,};

void make(int x, int y, int N)
{
    if(N == 3)
    {
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                star[x+i][y+j] = base[i][j];
        return;
    }
    else
    {
        N /= 3;
        make(x,y,N);
        make(x,y+N,N);
        make(x,y+2*N,N);

        make(x+N,y,N);
        // make(x+N,y+N,N); = 빈칸
        make(x+N,y+2*N,N);

        make(x+2*N,y+0,N);
        make(x+2*N,y+N,N);
        make(x+2*N,y+2*N,N);
    }
}

int main()
{
    int N;
    cin >> N;

    // init
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            star[i][j] = ' ';
        }
    }

    make(0,0,N);

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cout << star[i][j];
        }
        cout << '\n';
    }
    
    return 0;
}