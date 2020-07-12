#include <stdio.h>

int main()
{
    FILE *src = fopen("./data/abc.gif", "rb"); // binary 열기, jpg, gif 등 도 가능
    FILE *des = fopen("./data/D_abc.gif", "wb");
    char buf[20];
    int readCnt;

    if (src == NULL || des == NULL)
    {
        puts("파일 오픈 실패..");
        return -1;
    }

    while (1)
    {
        readCnt = fread((void *)buf, 1, sizeof(buf), src);
        if (readCnt < sizeof(buf))
        {
            if (feof(src))
            {
                fwrite((void *)buf, 1, readCnt, des);
                puts("파일 복사 완료!");
                break;
            }
            else
            {
                puts("파일 복사 실패..");
            }
            break;
        }
        fwrite((void *)buf, 1, sizeof(buf), des);
    }

    fclose(src);
    fclose(des);

    return 0;
}