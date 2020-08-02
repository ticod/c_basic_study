#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct book
{
    char author[30];
    char title[50];
    int page;
} Book;

// 배열
void cp1()
{
    Book b[3];
    puts("도서 정보 입력");
    for (int i = 0; i < 3; i++)
    {
        printf("저자: ");
        scanf("%s", b[i].author);
        printf("제목: ");
        scanf("%s", b[i].title);
        printf("페이지 수: ");
        scanf("%d", &b[i].page);
        getchar();
    }

    puts("도서 정보 출력");
    for (int i = 0; i < 3; i++)
    {
        printf("book %d\n", i + 1);
        printf("저자: %s\n", b[i].author);
        printf("제목: %s\n", b[i].title);
        printf("페이지 수: %d\n", b[i].page);
    }
}

// 동적할당
void cp2()
{
    Book *b = (Book *)malloc(sizeof(Book) * 3);
    puts("도서 정보 입력");
    for (int i = 0; i < 3; i++)
    {
        printf("저자: ");
        scanf("%s", b[i].author);
        printf("제목: ");
        scanf("%s", b[i].title);
        printf("페이지 수: ");
        scanf("%d", &b[i].page);
        getchar();
    }

    puts("도서 정보 출력");
    for (int i = 0; i < 3; i++)
    {
        printf("book %d\n", i + 1);
        printf("저자: %s\n", b[i].author);
        printf("제목: %s\n", b[i].title);
        printf("페이지 수: %d\n", b[i].page);
    }
    free(b);
}

int main()
{
    cp2();
    return 0;
}