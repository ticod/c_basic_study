#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cp4()
{
    FILE *fp = fopen("./data/text.txt", "rt");

    int ret;
    int count_A = 0;
    int count_P = 0;

    while (1)
    {
        char word[20];
        ret = fscanf(fp, "%s", word);
        if (ret == EOF)
            break;
        if (word[0] == 'A')
            count_A++;
        else if (word[0] == 'P')
            count_P++;
    }

    printf("A로 시작하는 단어의 수: %d\n", count_A);
    printf("P로 시작하는 단어의 수: %d\n", count_P);

    fclose(fp);
}

void cp5()
{
    FILE *fp1 = fopen("./data/d1.txt", "rt");
    FILE *fp2 = fopen("./data/d2.txt", "rt");
    FILE *fp3 = fopen("./data/d3.txt", "rt");
    int ch1, ch2;
    int check = 1;

    while ((ch1 = fgetc(fp1)) != EOF)
    {
        ch2 = fgetc(fp2);
        if ((ch1 != ch2) || (ch2 == EOF))
        {
            check = 0;
            break;
        }
    }

    if (check)
        printf("두 개의 파일은 완전히 일치");
    else
    {
        printf("두 개의 파일은 불일치");
    }
}

int main()
{
    cp5();
    return 0;
}