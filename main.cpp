#include <stdio.h>

int main(int argc, char* args[])
{
  int num1, num2;

  printf("두 개의 값 입력 : ");
  scanf("%d %d", &num1, &num2);

  printf("덧셈 결과 : %d\n", num1+num2);

  return 0;
}