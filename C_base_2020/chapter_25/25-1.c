#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int strSize = 0;
    scanf("%d", &strSize);
    getchar();

    char *str = (char *)malloc(sizeof(char) * (strSize + 1));
    //scanf("%s", str);
    fgets(str, strSize + 1, stdin);

    str[strlen(str) - 1] = 0;
    int len = strlen(str);

    for (int i = len; i > 0; i--)
    {
        if (str[i] == ' ')
        {
            printf("%s ", &str[i + 1]);
            str[i] = 0;
        }
    }
    printf("%s\n", &str[0]);

    return 0;
}