/* 달팽이 배열
 *
 * 숫자 n 입력, n x n에 해당하는 달팽이 배열 만들기
 * 
 * 1. 0,0 ~ 0,n     / x 0 ~ n
 * 2. 1,n ~ n,n     / y 1 ~ n
 * 3. n,n ~ n,0     / x n ~ 0
 * 4. n,0 ~ 1,0     / y n ~ 1 -- 1 cycle
 * 
 * 5. 1,1 ~ 1,n-1      / x 1 ~ (n-1)
 * 6. 2,n-1 ~ n-1,n-1  / y 2 ~ n-1
 * 7. n-1,n-1 ~ n-1,1  / x n-1 ~ 1
 * 8. n-1,1 ~ 2,1      / y n-1 ~ 2  -- 2 cycle
 * 
 * 9. 만약 n이 홀수인 경우
 *    -> n/2, n/2가 마지막
 *    -> 반복문에서 처리가 가능할까?
 * 
 * n x n : 배열 크기
 * n / 2 : 
 * */

    // 기본 설계
    //for(int i = times; i < n-1; i++){
    //    num[0][i] = count;
    //    num[i][n] = count+n;
    //    num[n][n-i] = count+n+n;
    //    num[n-i][0] = count+n+n+n;
    //    count++;
    //} 


#include <stdio.h>

void dalpeng(int (*num)[100], int n, int count, int times){
    // count는 재귀함수를 활용하기 위해 넣음
    // times 변수로 함수가 몇 번 반복됐는지 체크함
    count++;
    if(n-times == 1){
        num[(n+times)/2][(n+times)/2] = count;
    } else if(n-times == 0){
        return;
    } else {
        for(int i = times; i < n-1; i++){
            num[times][i] = count;
            num[i][n-1] = count+(n-1-times);
            num[n-1][n-i-1+times] = count+(2*(n-1-times));
            num[n-i-1+times][times] = count+(3*(n-1-times));
            count++;
        }
        count = (--count) + ((n-1-times)*3);
        dalpeng(num, --n, count, ++times);
    }
}

void dalpeng_2(int (*num)[100], int len, int n, int count, int times){
    // count: 1씩 증가, 저장 | times: 함수 반복 횟수
    if(n == 1){
        num[len/2][len/2] = count;
    } else if(n == 0){
        return;
    } else {
        int ntimes = n + times;
        for(int i = times; i < ntimes-1; i++){
            num[times][i] = count;
            num[i][ntimes-1] = count+(n-1);
            num[ntimes-1][len-1-i] = count+(2*(n-1));
            num[len-1-i][times] = count+(3*(n-1));
            count++;
        }
        count += ((n-1)*3);
        dalpeng_2(num, len, (n-2), count, ++times);
    }
}

void printArr(int (*num)[100], int n){
    printf("print :: \n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%d\t", num[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int num[100][100] = {0,};
    int n = 0;
    int *len = &n;

    printf("input n(0<n<100): ");
    scanf("%d", &n);

    dalpeng_2(num, *len, n, 1, 0);
    printArr(num, *len);

    return 0;
}