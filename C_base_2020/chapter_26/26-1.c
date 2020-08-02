#include <stdio.h>
#define GOB(X, Y, Z) ((X) * (Y) * (Z))
#define PLUS(X, Y, Z) ((X) + (Y) + (Z))
#define PI 3.1415
#define AREA(X) ((X) * (X)*PI)
#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))

#define PRINT_PR_NUM(STR) printf("\n//// " #STR " ////\n");

void solve1()
{
    PRINT_PR_NUM("문제 1번");
    int n[3];
    scanf("%d %d %d", &n[0], &n[1], &n[2]);
    printf("%d / %d \n", GOB(n[0], n[1], n[2]), PLUS(n[0], n[1], n[2]));
}

void solve2()
{
    PRINT_PR_NUM("문제 2번");
    double n;
    scanf("%lf", &n);
    printf("%lf\n", AREA(n));
}

void solve3()
{
    PRINT_PR_NUM("문제 3번");
    int a, b;
    scanf("%d %d", &a, &b);
    printf("큰 값은 %d\n", MAX(a, b));
}

int main()
{
    solve1();
    solve2();
    solve3();
    return 0;
}