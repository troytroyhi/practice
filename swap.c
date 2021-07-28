#include <stdio.h>
void swap(int a, int b);
void swap_addr(int * a, int * b);

int main_swap(void)
{
  // swap
  int a = 10;
  int b = 20;

  printf("a 의 주소 : %d\n", &a);
  printf("b 의 주소 : %d\n", &b);

  // a 와 b 의 값을 바꾼다.
  printf("swap 함수 전 => a : %d, b : %d\n", a, b);
  swap(a, b);
  printf("swap 함수 후 => a : %d, b : %d\n", a, b);

  // 값에 의한 복사 (Call by Value) -> 값만 복사한다는 의미

  // 주소값을 넘기면? 메모리 공간에 있는 주소값 자체를 넘김
  printf("(주소값 전달) swap 함수 전 => a : %d, b : %d\n", a, b);
  swap_addr(&a, &b);
  printf("주소값 전달) swap 함수 후 => a : %d, b : %d\n", a, b);

  return 0;
}

void swap(int a, int b)
{
  printf("(swap 함수 내) a 의 주소 : %d\n", &a);
  printf("(swap 함수 내) b 의 주소 : %d\n", &b);

  int temp = a;
  a = b;
  b = temp;
  printf("swap 함수 내 => a : %d, b : %d\n", a, b);
}

void swap_addr(int * a, int * b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
  printf("주소값 전달) swap 함수 내 => a : %d, b : %d\n", *a, *b);
}
