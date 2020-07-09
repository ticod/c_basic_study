#include <stdio.h>

const char semo[3][6] =
{
    {' ', ' ', '*', ' ', ' ', ' '},
    {' ', '*', ' ', '*', ' ', ' '},
    {'*', '*', '*', '*', '*', ' '}
};

int main(){
    
    int input = 0;
    printf("숫자 입력: ");
    scanf("%d", &input);
    int num = input / 3;
    for(int i = 1; i <= num; i++){
        for(int loop = 0; loop < 3; loop++){
            for(int j = 0; j < num-i; j++){
                printf("   ");
            }
            for(int j = 0; j < i; j++){
                if(j & (i-1)-j) { // != 0
                    printf("      ");
                } else { // == 0
                    for(int k = 0; k < 6; k++){
                        printf("%c", semo[loop][k]);
                    }
                }
            }
            printf("\n");
        }
    }

    return 0;
}