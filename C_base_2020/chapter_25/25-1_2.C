#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int len = 0;
    scanf("%d", &len);
    getchar();

    char *str = (char *)malloc(sizeof(char) * (len + 1));
    fgets(str, len + 1, stdin);
    len = strlen(str);
    str[len - 1] = 0;

    for (int i = len - 1; i >= 0; i--)
    {
        if (str[i] == ' ')
        {
            str[i] = 0;
            printf("%s ", &str[i + 1]);
        }
    }
    printf("%s\n", str);

    return 0;
}