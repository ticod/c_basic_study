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
    FILE *fp = fopen("./data/mystory.txt", "wt");
    PersonInfo p;

    puts("이름 입력: ");
    gets(p.name);

    puts("주민번호 입력: ");
    gets(p.id);

    puts("전화번호 입력: ");
    gets(p.phoneNumber);

    puts("좋아하는 음식 입력: ");
    gets(p.favoriteFood);

    puts("취미 입력: ");
    gets(p.hobby);

    fputs("#이름: ", fp);
    fputs(p.name, fp);
    fputc('\n', fp);

    fputs("#주민번호: ", fp);
    fputs(p.id, fp);
    fputc('\n', fp);

    fputs("#전화번호: ", fp);
    fputs(p.phoneNumber, fp);
    fputc('\n', fp);

    fputs("#좋아하는 음식: ", fp);
    fputs(p.favoriteFood, fp);
    fputc('\n', fp);

    fputs("#취미: ", fp);
    fputs(p.hobby, fp);
    fputc('\n', fp);

    fclose(fp);
    return 0;
}