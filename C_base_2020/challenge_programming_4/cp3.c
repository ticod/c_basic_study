#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct complexNumber
{
    double real;
    double imaginary;
} ComplexNumber;

double RealTimes(ComplexNumber num1, ComplexNumber num2)
{
    return (num1.real * num2.real) - (num1.imaginary * num2.imaginary);
}

double ImaginaryTimes(ComplexNumber num1, ComplexNumber num2)
{
    return (num1.imaginary * num2.real) + (num1.real * num2.imaginary);
}

int main()
{
    ComplexNumber num[2];
    for (int i = 0; i < 2; i++)
    {
        printf("복소수 입력%d[실수 허수]: ", i + 1);
        scanf("%lf %lf", &num[i].real, &num[i].imaginary);
        getchar();
    }

    printf("합의 결과] 실수: %lf, 허수: %lf\n", num[0].real + num[1].real, num[0].imaginary + num[1].imaginary);
    printf("곱의 결과] 실수: %lf, 허수: %lf\n", RealTimes(num[0], num[1]), ImaginaryTimes(num[0], num[1]));
}