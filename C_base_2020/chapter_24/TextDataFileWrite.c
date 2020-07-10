#include <stdio.h>

int main()
{
    FILE *fp = fopen("./data/simple.txt", "wt");
    // 특정 디렉토리의 파일을 열 때 디렉토리가 존재하지 않으니까 NULL값을 불러옴
    if (fp == NULL)
    {
        puts("파일 오픈 실패..");
        return -1;
    }

    fputc('A', fp);
    fputc('B', fp);
    fputs("My Name is Hong \n", fp);
    fputs("Your name is Yoon \n", fp);
    fclose(fp);

    return 0;
}