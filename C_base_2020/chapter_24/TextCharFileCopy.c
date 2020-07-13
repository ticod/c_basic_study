#include <stdio.h>

int main()
{
    FILE *src = fopen("./data/src.txt", "rt");
    FILE *des = fopen("./data/dst.txt", "wt");
    int ch;

    if (src == NULL || des == NULL)
    {
        puts("파일 오픈 실패..");
        return -1;
    }

    // String : while(fgets(buffer, sizeof(buffer), src) != NULL)
    // buffer : char[1234]
    while ((ch = fgetc(src)) != EOF)
        fputc(ch, des);

    if (feof(src) != 0)
        puts("파일 복사 완료!");
    else
        puts("파일 복사 실패..");

    fclose(src);
    fclose(des);

    return 0;
}