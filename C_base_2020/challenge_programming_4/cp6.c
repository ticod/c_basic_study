#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct info
{
    char name[30];
    char telNumber[10];
} Info;

int ReadFileToInfo(Info *info, FILE *rfp)
{
    int ret;
    int i = 0;
    while (1)
    {
        ret = fscanf(rfp, "%s %s", info[i].name, info[i].telNumber);
        if (ret == EOF)
            break;
        i++;
    }
    fclose(rfp);
    return i;
}

void WriteFileToInfo(Info *info, int length, FILE *wfp)
{
    for (int i = 0; i < length; i++)
    {
        fprintf(wfp, "%s %s\n", info[i].name, info[i].telNumber);
    }
    fclose(wfp);
}

void PrintMenu()
{
    puts("***** MENU *****");
    puts("1. Insert");
    puts("2. Delete");
    puts("3. Search");
    puts("4. Print All");
    puts("5. Exit");
}

int ChooseItem()
{
    int chooseItem = 0;
    printf("Chosse the item: ");
    scanf("%d", &chooseItem);
    getchar();
    return chooseItem;
}

int InsertInfo(Info *info, int length)
{
    puts("[ INSERT ]");
    printf("Input Name: ");
    scanf("%s", info[length].name);
    printf("Input Tel Number: ");
    scanf("%s", info[length].telNumber);
    puts("[ Data Inserted ]");
    return length + 1;
}

int DeleteInfo(Info *info, int length)
{
    char deleteName[30];
    puts("[ DELETE ]");
    printf("Input Name to Delete: ");
    scanf("%s", deleteName);
    int i = 0;
    for (; i < length; i++)
    {
        if (!strcmp(deleteName, info[i].name))
        {
            memmove(&info[i], &info[i + 1], sizeof(Info));
            break;
        }
    }
    if (i == length)
    {
        puts("검색 결과가 없습니다.");
    }
    return length - 1;
}

void SearchInfo(Info *info, int length)
{
    char searchName[30];
    puts("[ SEARCH ]");
    printf("Input Name to Search: ");
    scanf("%s", searchName);

    int i = 0;
    for (; i < length; i++)
    {
        if (!strcmp(searchName, info[i].name))
        {
            printf("Name: %s\n", info[i].name);
            printf("Tel: %s\n", info[i].telNumber);
            break;
        }
    }
    if (i == length)
    {
        puts("검색 결과가 없습니다.");
    }
}

void PrintAllInfo(Info *info, int length)
{
    puts("[ Print All Data ]\n");
    for (int i = 0; i < length; i++)
    {
        puts("===============");
        printf("Name: %s\n", info[i].name);
        printf("Tel: %s\n", info[i].telNumber);
        puts("===============\n");
    }
}

int main()
{
    Info info[100];
    int choiceItem = 0;
    int length = 0;

    FILE *rfp = fopen("./data/cp6_data.txt", "rt");
    length = ReadFileToInfo(info, rfp);
    FILE *wfp = fopen("./data/cp6_data.txt", "wt");

    while (1)
    {
        PrintMenu();
        choiceItem = ChooseItem();
        switch (choiceItem)
        {
        case 1:
            length = InsertInfo(info, length);
            break;
        case 2:
            length = DeleteInfo(info, length);
            break;
        case 3:
            SearchInfo(info, length);
            break;
        case 4:
            PrintAllInfo(info, length);
            break;
        case 5:
            WriteFileToInfo(info, length, wfp);
            return 0; // 종료
        default:
            puts("[ 올바르지 않은 입력입니다 ]");
            break;
        }
        puts("");
    }
    return 0;
}