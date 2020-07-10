#include <stdio.h>

int main()
{
    FILE *fp = fopen("./data/simple.txt", "rt");
    // 특정 디렉토리의 파일을 열 때 디렉토리가 존재하지 않으니까 NULL값을 불러옴
    char str[30];
    int ch;
    if (fp == NULL)
    {
        puts("파일 오픈 실패..");
        return -1;
    }

    ch = fgetc(fp);
    printf("%c\n", ch);
    ch = fgetc(fp);
    printf("%c\n", ch);

    fgets(str, sizeof(str), fp);
    printf("%s", str); // str 안에 \n 포
    fgets(str, sizeof(str), fp);
    printf("%s", str);
    fclose(fp);

    return 0;
}