#include <stdio.h>
#include <stdlib.h>

int main(void){
    int num[10];
    int n;
    int j = 0, h = 0;

    for(int i = 0; i < 10; i++){
        printf("%d번째 정수 입력: ", i+1);
        scanf("%d", &n);
        if(n%2==0) {
            num[9-j] = n;
            j++;
        } else {
            num[h] = n;
            h++;
        }
    }

    printf("배열 요소의 출력: ");
    for(int i = 0; i < 10; i++){
        printf("%d ", num[i]);
    }

    return 0;
}