/* 비콘을 활용한 위치 측위
 * 예외 처리는 따로 하지 않음
 * 해당 좌표값을 정수로 출력 
 * 
 * 2~4개의 원의 반지름 값을 넣어
 * 하나의 교점 좌표(x, y)를 구하는 프로그램
 * 
 * Beacon1: (x-5)^2 + (y-5)^2 = R1 
 * Beacon2: (x-10)^2 + (y-5)^2 = R2
 * Beacon3: (x-5)^2 + (y-10)^2 = R3
 * Beacon4: (x-10)^2 + (y-10)^2 = R4
 * 이 때 R1~R4는 rssi의 세기로 계산 ex) (rssi/10)^2 
 * 
 * ex) <B1, B2, B4> 
 * 1. B1 - B2 계산: x = (R1-R2)/10 -> 식 A1로 하자
 * 2. B1에 A1 대입: (A1-5)^2 + (y-5)^2 = R1 */
/* -- 참고 사이트
 * https://gaussian37.github.io/math-algorithm-intersection_point/
 * https://blog.ghatdev.xyz/10 
 * */

#include <stdio.h>
#include <math.h>

#define POW(X) ((X) * (X))

typedef struct Beacon
{
    double r; // 반지름
    double x; // x좌표
    double y; // y좌표
} Beacon;

int x_calc(Beacon b1, Beacon b2, Beacon b3)
{
    if ((((2 * b2.x - 2 * b1.x) * (2 * b3.y - 2 * b2.y)) - ((2 * b3.x - 2 * b2.x) * (2 * b2.y - 2 * b1.y))) != 0)
    {
        // 두 직선이 평행한 경우
        return ((2 * b2.y - 2 * b1.y) * (POW(b2.x) + POW(b2.y) - POW(b3.x) - POW(b3.y) - POW(b2.r) + POW(b3.r))) - ((2 * b3.y - 2 * b2.y) * (POW(b1.x) + POW(b1.y) - POW(b2.x) - POW(b2.y) - POW(b1.r) + POW(b2.r))) / (((2 * b2.x - 2 * b1.x) * (2 * b3.y - 2 * b2.y)) - ((2 * b3.x - 2 * b2.x) * (2 * b2.y - 2 * b1.y)));
        // b1-b2 교점의 직선, b2-b3 교점의 직선
        // 위 두 직선의 교점의 x좌표값
    }
    else
    {
        return -1; // 에러
    }
}

int y_calc(Beacon b1, Beacon b2, Beacon b3, int _x)
{
    if (b2.y - b1.y != 0)
    {
        return ((-((2 * b2.x - 2 * b1.x) / (2 * b2.y - 2 * b1.y)) * _x) - ((POW(b1.x) + POW(b1.y) - POW(b2.x) - POW(b2.y) - POW(b1.r) + POW(b2.r)) / (2 * b2.y - 2 * b1.y)));
    }
    else
    {
        return y_calc(b2, b3, b1, _x);
        // y값이 나오지 않는 경우 x값을 다른 식에 대입하여 계산
    }
}

Beacon InitBeacon(int x, int y, int r)
{
    // 비콘의 좌표 설정
    Beacon beacon;
    beacon.x = x;
    beacon.y = y;
    beacon.r = r;
    return beacon;
}

int main(void)
{
    int xy[15][15] = {
        0,
    }; // 출력할 xy평면
    int rssi[4] = {0, 0, 0, 0};
    int count = 0; // 신호를 받은 비콘의 개수를 셈
    Beacon beacon[4];
    int x = 0, y = 0;

    //beaconInit(beacon);

    for (int i = 0; i < 4; i++)
    {
        printf("rssi값 입력: ");
        scanf("%d", &rssi[i]);
        rssi[i] /= 10; // rssi/10 => 거리로 환산
    }

    beacon[0] = InitBeacon(5, 5, rssi[0]);
    beacon[1] = InitBeacon(10, 5, rssi[1]);
    beacon[2] = InitBeacon(5, 10, rssi[2]);
    beacon[3] = InitBeacon(10, 10, rssi[3]);

    x = x_calc(beacon[0], beacon[1], beacon[2]);
    y = y_calc(beacon[0], beacon[1], beacon[2], x);

    printf("x: %d / y: %d\n", x, y);
    xy[x][y] = 1; // 카트 위치
    /* 좌표 출력 */
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            printf("%d ", xy[j][i]);
        }
        printf("\n");
    }

    return 0;
}