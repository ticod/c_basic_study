/*
 * 배열의 요소 90도 회전
 * 
 * num[0][0] => num[0][3]
 * num[0][1] => num[1][3]
 * num[0][2] => num[2][3]
 * num[0][3] => num[3][3] // [x][y] => [y][3-x] (3=len-1)
 * 
 * num[1][0] => num[0][2]
 * num[1][1] => num[1][2]
 * num[1][2] => num[2][2]
 * num[1][3] => num[3][2]
 * 
 * */
#include <stdio.h>

void printNum(int (*num)[4]){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            printf("%d\t", num[i][j]);
        }
        printf("\n");
    } 
    printf("\n");
}

void turnArray(int (*num)[4]){
    int temp[4][4];

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            temp[j][3-i] = num[i][j];
        }
    }
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            num[i][j] = temp[i][j];
        }
    }
    printNum(num);
}


int main(void){

    int num[4][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};

    printNum(num);
    for(int i = 0; i < 4; i++){
        turnArray(num);
    }

    return 0;
}