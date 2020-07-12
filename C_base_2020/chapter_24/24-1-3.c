#include <stdio.h>

typedef struct personInfo
{
    char name[30];
    char id[20]; // 주민번호
    char phoneNumber[20];
    char favoriteFood[30];
    char hobby[30];
} PersonInfo;

int main()
{
    FILE *fp = fopen("./data/mystory.txt", "rt");
    int ch;

    if (fp == NULL)
        return -1;

    while ((ch = fgetc(fp)) != EOF)
        fputc(ch, stdout);

    if (feof(fp))
        puts("파일 읽기 완료");
    else
        puts("파일 읽기 실패");

    fclose(fp);
    return 0;
}