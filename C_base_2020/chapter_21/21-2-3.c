#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int returnSpace(char *str)
{
    int i = 0;
    while (str[i] != ' ')
        i++;
    return i;
}

void strip(char *str, char *st1, char *st2, int space)
{
    strncpy(st1, str, space);
    st1[space] = 0;
    strncpy(st2, str + space + 1, sizeof(str) - 1);
    st2[sizeof(str) - 1] = 0;
    printf("%d", sizeof(str));
}

int main(void)
{
    char str[2][20];
    char age[2][20];
    char name[2][20];
    int space = 0;

    for (int i = 0; i < 2; i++)
    {
        fputs("(이름) (나이): ", stdout);
        fgets(str[i], sizeof(str[i]), stdin);
        str[i][strlen(str[i]) - 1] = 0;

        strip(str[i], name[i], age[i], returnSpace(str[i]));
    }

    if (!strcmp(name[0], name[1]))
    {
        fputs("이름이 같습니다\n", stdout);
    }
    else
    {
        fputs("이름이 다릅니다.\n", stdout);
    }
    if (atoi(age[0]) == atoi(age[1]))
    {
        fputs("나이가 같습니다\n", stdout);
    }
    else
    {
        fputs("나이가 다릅니다.\n", stdout);
    }

    return 0;
}