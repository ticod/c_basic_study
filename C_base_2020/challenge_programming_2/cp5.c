/* Bubble Sort */
#include <stdio.h>

void Swap(int *n1, int *n2){
    // Swap
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

void DesSort(int num[], int len){
    // Bubble Sort
    for(int i = 0; i < (len-1); i++){
        for(int j = 0; j < (len-1-i); j++){
            if(num[j]<num[j+1]){
                Swap(&num[j], &num[j+1]);
            }
        }
    }
}

int main(void){
    int num[7] = {3, 2, 5, 1, 4, 7, 6};

    DesSort(num, 7);
    // desc: 내림차순

    printf("정렬한 값 출력: ");
    for(int i = 0; i < 7; i++){
        printf("%d ", num[i]);
    }

    return 0;
}