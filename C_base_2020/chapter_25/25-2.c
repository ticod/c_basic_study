#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int *input = (int *)malloc(sizeof(int) * 5);
    int i = 0;
    scanf("%d", &input[i]);
    while (input[i] != -1)
    {
        i++;
        if (i == sizeof(input) / sizeof(int))
        {
            input = (int *)realloc(input, sizeof(int) * (i + 3));
        }
        scanf("%d", &input[i]);
    }

    for (int j = 0; j < i; j++)
    {
        printf("%d ", input[j]);
    }
    putchar('\n');

    free(input);
    return 0;
}