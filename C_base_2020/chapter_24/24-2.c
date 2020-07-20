#include <stdio.h>

int main()
{
    char fileName[30] = {
        0,
    };
    scanf("%s", fileName);

    FILE *fp = fopen(fileName, "rt");

    long fpos = ftell(fp);
    fseek(fp, 0, SEEK_END);
    long fileSize = ftell(fp);
    fseek(fp, fpos, SEEK_SET);

    printf("파일 크기: %d\n", fileSize);

    return 0;
}