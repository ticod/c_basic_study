#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct //person <- 생략 가능(typedef)
{
    char name[40];
    char id[16]; // 주민등록번호
    int pay;
} Person;

void inputPerson(Person *person, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("\n%d번째 종업원\n", i + 1);
        fputs("이름 입력: ", stdout);
        fgets(person[i].name, sizeof(person[i].name), stdin);
        person[i].name[strlen(person[i].name) - 1] = 0;

        fputs("주민등록번호 입력: ", stdout);
        fgets(person[i].id, sizeof(person[i].id), stdin);
        person[i].id[strlen(person[i].id) - 1] = 0;

        fputs("급여 정보 입력: ", stdout);
        scanf("%d", &person[i].pay);
        while (getchar() != '\n')
            ;
    }
}

void printPerson(Person *person, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("\n%d번째 종업원\n", i + 1);
        printf("이름: %s\n", person[i].name);
        printf("주민등록번호: %s\n", person[i].id);
        printf("급여 정보: %d\n", person[i].pay);
    }
}

int main()
{
    Person employee[3];

    inputPerson(employee, 3);
    printPerson(employee, 3);

    return 0;
}