/* ���� 2-4: ȸ�� �Ǵ� */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[20];
    int length;
    int count = 0;

    printf("문자열 입력: ");
    scanf("%s", str);

    length = strlen(str);

    for (int i = 0; i < length / 2; i++)
    {
        if (*(str + i) == *(str + (length - 1) - i))
            count++;
    }
    if (count == (length / 2))
        printf("%s는 회문입니다.\n", str);

    return 0;
}