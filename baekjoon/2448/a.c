#include <stdio.h>

const char space[3][3] =
{
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
};

const char semo[3][6] =
{
    {' ', ' ', '*', ' ', ' ', ' '},
    {' ', '*', ' ', '*', ' ', ' '},
    {'*', '*', '*', '*', '*', ' '}
};

char temp[6144][3072];

void star(int x, int y, int n)
{
    if(n == 1){
        for(int i = 0; i < x; i++) //printf("   "); printf("%s", semo[0]);
            temp[i] = 
        for(int i = 0; i < x; i++) //printf("   "); printf("%s", semo[1]);
        for(int i = 0; i < x; i++) //printf("   "); printf("%s", semo[2]);
    }

    n/=2;
    star(n/2+1  ,1      ,n); // 상단
    star(1      ,n/2+1  ,n); // 우하단
    star(n+1    ,n/2+1  ,n); // 좌하단
}

int main(){
    
    int input = 0;

    // printf("숫자 입력: ");
    // scanf("%d", &input);
    input = 12;
    int num = input / 3;
    star(1,1,num);

    return 0;
}