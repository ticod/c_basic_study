#include <stdio.h>

typedef struct point
{
    int xpos;
    int ypos;
} Point;

typedef struct rectangle
{
    Point point_one;
    Point point_two;
} Rectangle;

int main()
{
    Rectangle rect;
    rect.point_one.xpos = 0;
    rect.point_one.ypos = 0;

    rect.point_two.xpos = 4;
    rect.point_two.ypos = 2;

    int nul = 0;
    nul = (rect.point_two.xpos - rect.point_one.xpos) *
          (rect.point_two.ypos - rect.point_one.ypos);
    printf("넓이: %d", nul);

    return 0;
}