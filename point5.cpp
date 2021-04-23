#include <iostream>

void swap(int *num1, int *num2) {
  int temp = *num1;
  *num1 = *num2;
  *num2 = temp;
}

int main() {
  int num1 = 10;
  int num2 = 20;

  printf("num1의 값 : %d\n", num1);
    printf("num2의 값 : %d\n", num2);

  swap(&num1, &num2);
  printf("\nSwap 함수 실행 후\n\n");

  printf("num1의 값 : %d\n", num1);
  printf("num2의 값 : %d\n", num2);
}