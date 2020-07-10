#include <stdio.h>
#include <stdlib.h>

// 왜안될깡..

int main()
{
    FILE *fp = fopen("hello_world.c", "wt");
    if (fp == NULL)
    {
        puts("파일 열기 실패..");
        return -1;
    }

    fputs("#include <stdio.h>\n", fp);
    fputc('\n', fp);
    fputs("int main(void)", fp);
    fputc('\n', fp);
    fputc('{', fp);
    fputc('\n', fp);
    fputs("\tprintf(\"Hello World!\\n\");", fp);
    fputc('\n', fp);
    fputs("\treturn 0;", fp);
    fputc('\n', fp);
    fputc('}', fp);
    fputc('\n', fp);

    system("gcc -o hello_world hello_world.c");
    system("./hello_world");
    fclose(fp);

    return 0;
}