#include <iostream>
int main() {

  int a[] = {10, 20, 30, 40, 50};

  printf("배열 a[0]의 주소값 = %p \n", a);
  printf("배열 a[1]의 주소값 = %p \n", a+1);
  printf("배멸 a[0]의 값 = %d \n", *a);
  printf("배열 a[1]의 값 = %d \n", *(a+1));

  return 0;
}