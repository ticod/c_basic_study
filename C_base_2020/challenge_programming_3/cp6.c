/* 야구 게임
 *
 * 컴퓨터는 0~9 세 개의 랜덤한 숫자를 고름
 * 숫자와 위치 일치 : strike
 * 숫자만 일치 : ball
 * 
 * 3 strike시 게임 종료, 몇 번 시도했는지 출력
 * */

#include <stdio.h>
#include <stdlib.h> // rand(), srand()
#include <time.h> // time()

int main(){

    int com_num[3] = {0,};
    int user_num[3] = {0,};
    int strike = 0;
    int ball = 0;
    int count = 0;

    printf("Start Game!\n");
    srand((int)time(NULL));

    for(int i = 0; i < 3; i++){
        com_num[i] = rand()%10;
        for(int j = 0; j < i; j++){
            while(com_num[i] == com_num[j]) com_num[i] = rand()%10;
        }
        printf("%d ", com_num[i]);
    }

    while(1){
        printf("세 개의 숫자 선택! ");

        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(user_num[i] == com_num[j]){
                    if(i == j) strike++;
                    else ball++;
                }
            }
        }
        count++;
        

        printf("%d번째 도전 결과! %dstrike, %dball!\n", count, strike, ball);

        if(strike == 3){
            break;
        }

        strike = 0;
        ball = 0;

    }
    printf("Game Over!\n");
    return 0;
}