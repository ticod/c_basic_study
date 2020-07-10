#include <stdio.h>
#include <math.h>

#define SQUARED(X) ((X)*(X)) 

typedef struct circle{
    double x;
    double y;
    double r;
} Circle;

double Linear(double a, double b)
{ // ax + b = 0
    if(a != 0)  return -b/a;
    else        return -1; // error
}

double Quadratic(double a, double b, double c)
{ // ax^2 + bx + c = 0
    double temp = SQUARED(b) - 4*a*c;
    
    if(temp >= 0) return (-b+sqrt(temp))/2*a;
    if(temp < 0) return -1; // error
}

double y_calc(Circle c1, Circle c2)
{
    double y = 0;

    double a = (SQUARED(2*c1.y-2*c2.y))+(4*SQUARED(c2.x));  // 이차항
    double b = -8*SQUARED(c2.x)*c1.y;                       // 일차항
    double c = (-4*SQUARED(c2.x)*SQUARED(c1.r))+(4*SQUARED(c2.x)*SQUARED(c1.y))+SQUARED(c1.r)-SQUARED(c1.y)+SQUARED(c2.y)-SQUARED(c2.r);

    if(a == 0)
    { // 일차 방정식
        y = Linear(b,c);
    }
    else
    { // 이차 방정식
        y = Quadratic(a,b,c);
    }

    if(y == -1); // error
    else return y;
}

int main()
{
    Circle AP[3] =
    {
        {0,0,5},
        {5,2,4},
        {3,7,7}
    };

    Circle location; // 찾아야 하는 좌표값
    location.r = 0;

    // x^2      + y^2       = 25
    // (x-5)^2  + (y-2)^2   = 16
    // (x-3)^2  + (y-7)^2   = 49

    // 1)
    // y^2  = 25 - x^2
    // y    = sqrt(25-x^2)
    // 2)
    // (x-5)^2 + (y-2)^2 = 16
    // x^2 - 10x + 25 + y^2 - 4y + 4 = 16
    // 1) -> 2)
    // x^2 - 10x + 25 + (25 - x^2) + 4*(sqrt(25-x^2)) = 12
    // -10x + 4*(sqrt(25-x^2)) = -38
    // 16(25-x^2) = 38^2 + 100x
    // -16x^2 = 38^2 - 16*25 + 100x
    // 16x^2 + 100x = 16*25 - 38^2
    // 16x^2 + 100x - A = 0 => two_bang(16, 100, -A);

    int x1, y1;


    printf("\nx: %d\ny: %d\n", location.x, location.y);

    return 0;
}