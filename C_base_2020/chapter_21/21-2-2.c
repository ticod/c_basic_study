#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    char str1[20];
    char str2[20];
    char str3[40];

    fputs("str1 입력: ", stdout);
    fgets(str1, sizeof(str1), stdin);
    str1[strlen(str1)-1] = 0;
    fputs("str2 입력: ", stdout);
    fgets(str2, sizeof(str2), stdin);
    str2[strlen(str2)-1] = 0;

    strncpy(str3, str1, sizeof(str1)-1);
    str3[sizeof(str1)-1] = 0;
    strncat(str3, str2, sizeof(str2));

    printf("%s", str3);

    return 0;
}