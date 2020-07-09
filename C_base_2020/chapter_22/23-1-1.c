#include <stdio.h>

typedef struct
{
    int x;
    int y;
} Point;

void SwapPoint(Point *p1, Point *p2)
{
    Point temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main(void)
{
    Point p1 = {5, 7};
    Point p2 = {2, 4};
    SwapPoint(&p1, &p2);
    printf("p1: %d %d\n", p1.x, p1.y);
    printf("p2: %d %d\n", p2.x, p2.y);
    return 0;
}