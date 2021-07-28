#include <stdio.h>
void changeArray(int * ptr);

int main_pointerarr(void)
{
  // 배열일 때, arr2 -> 주소
  int arr2[3] = { 10, 20, 30 };
  //changeArray(arr2);
  changeArray(arr2[0]);
  for(int i=0; i<3; i++)
  {
    printf("%d\n", arr2[i]);
  }

  // scnaf 에서 &num 과 같이 & 를 사용하는 이유?
}

void changeArray(int * ptr)
{
  ptr[2] = 50;
}