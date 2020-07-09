/* 가위바위보 프로그램
 * 컴퓨터는 난수 생성을 통해 가위 바위 보 중 하나를 선택
 * 사용자는 가위 바위 보 중 입력을 통해 하나를 선택
 * 사용자가 질 때 까지 계속되고, 게임의 결과를 출력한다 */
#include <stdio.h>
#include <stdlib.h> // rand(), srand()
#include <time.h> // time()

int main(){
    int user_rsp = 0; // 가위바위보 입력
    int com_rsp = 0;
    int res[2] = {0,}; // res[0] = 승, res[1] = 무
    char *rsp[3] = {"바위", "가위", "보"};
    int repeat = 1; // 질 때까지 반복

    srand((int)time(NULL));
    
    while(repeat){
        printf("바위는 1, 가위는 2, 보는 3: ");
        scanf("%d", &user_rsp);
        // 바위 > 가위 > 보 > 바위
        // 1 > 2 > 3 > 1
        // 1이 2이기고 2가 3이기고 3이 1이기고
        com_rsp = (rand()%3)+1;
        printf("당신은 %s 선택, 컴퓨터는 %s 선택, ", rsp[user_rsp-1], rsp[com_rsp-1]);
        if(com_rsp == user_rsp){
            // 무승부
            printf("비겼습니다!\n");
            res[1]++;
        }
        else if(com_rsp == 2 && user_rsp == 1 ||
        com_rsp == 3 && user_rsp == 2 ||
        com_rsp == 1 && user_rsp == 3){
            // 승리
            printf("이겼습니다!\n");
            res[0]++;
        }
        else{
            printf("당신이 졌습니다..\n");
            repeat = 0; // break;
        }
    }

    printf("게임의 결과 : %d승, %d무\n", res[0], res[1]);
    return 0;
}