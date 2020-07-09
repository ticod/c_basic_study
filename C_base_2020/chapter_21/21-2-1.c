#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ctoi(char ch){
  int diff = '1' - 1;
  return ch - diff;
}

int main()
{
  char str[30];
  int sum = 0;

  fgets(str, sizeof(str), stdin);

  for(int i = 0; i < strlen(str); i++){
    if(str[i] >= '1' && str[i] <= '9'){
      sum += ctoi(str[i]);
    }
  }

  printf("%d", sum);

  return 0;
}