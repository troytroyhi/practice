#include <stdio.h>
int main_pointer(void)
{
  // // 포인터

  // // [철수] : 101호 -> 메모리 공간의 주소
  // // [영희] : 201호
  // // [민수] : 301호
  // // 각 문 앞에 '암호' 가 걸려 있음
  // int 철수 = 1; // 암호
  // int 영희 = 2;
  // int 민수 = 3;

  // printf("철수네 주소 : %d, 암호 : %d\n", &철수, 철수);
  // printf("영희네 주소 : %d, 암호 : %d\n", &영희, 영희);
  // printf("민수네 주소 : %d, 암호 : %d\n", &민수, 민수);

  // // 미션맨 !

  // // 첫 번째 미션 : 아파트의 각 집에 방문하여 문에 적힌 암호 확인
  // int * 미션맨; // 포인터 변수
  // 미션맨 = &철수;
  // *미션맨 = *미션맨 * 3;
  // printf("미션맨이 방문하는 곳 주소 : %d, 암호 : %d\n", 미션맨, 미션맨);

  // 미션맨 = &영희;
  // *미션맨 = *미션맨 * 3;
  // printf("미션맨이 방문하는 곳 주소 : %d, 암호 : %d\n", 미션맨, 미션맨);

  // 미션맨 = &민수;
  // *미션맨 = *미션맨 * 3;
  // printf("미션맨이 방문하는 곳 주소 : %d, 암호 : %d\n", 미션맨, 미션맨);

  // // 스파이
  // // 미션맨이 바꾼 암호에서 2를 빼라 !
  // int * 스파이 = 미션맨;
  // printf("\n . . . 스파이가 미션 수행하는 중 . . . \n\n");
  // 스파이 = &철수;
  // *스파이 = *스파이 - 2; // 철수 = 철수 - 2;
  // printf("스파이가 방문하는 곳 주소 : %d, 암호 : %d\n", 스파이, *스파이);

  // 스파이 = &영희;
  // *스파이 = *스파이 - 2; 
  // printf("스파이가 방문하는 곳 주소 : %d, 암호 : %d\n", 스파이, *스파이);

  // 스파이 = &민수;
  // *스파이 = *스파이 - 2;
  // printf("스파이가 방문하는 곳 주소 : %d, 암호 : %d\n", 스파이, *스파이);

  // printf("\n . . . 철수 영희 민수는 집에 오고서는 바뀐 암호를 보고 깜놀 . . . \n\n");

  // printf("철수네 주소 : %d, 암호 : %d\n", &철수, 철수);
  // printf("영희네 주소 : %d, 암호 : %d\n", &영희, 영희);
  // printf("민수네 주소 : %d, 암호 : %d\n", &민수, 민수);

  // // 참고로.. 미션맨이 사는 곳의 주소는 . . &미션맨 으로 확인
  // printf("미션맨의 주소 : %d\n", &미션맨);
  // printf("스파이의 주소 : %d\n", &스파이);

  // 배열 ?
  // int arr[3] = {5, 10, 15};
  // int * ptr = arr;
  // for(int i = 0; i<3; i++)
  // {
  //   printf("배열 arr[%d] 의 값 : %d\n", i, arr[i]);
  // }
  // for (int i = 0; i<3; i++)
  // {
  //   printf("포인터 ptr[%d] 의 값 : %d\n", i, ptr[i]);
  // }

  // ptr[0] = 100;
  // ptr[1] = 200;
  // ptr[2] = 300;
  // for(int i = 0; i<3; i++)
  // {
  //   // printf("배열 arr[%d] 의 값 : %d\n", i, arr[i]);
  //   printf("배열 arr[%d] 의 값 : %d\n", i, *(arr + i));
  // }
  // for (int i = 0; i<3; i++)
  // {
  //   // printf("포인터 ptr[%d] 의 값 : %d\n", i, ptr[i]);
  //   printf("포인터 ptr[%d] 의 값 : %d\n", i, *(ptr + i));
  // }
  // // *(arr + i) == arr[i] 똑같은 표현
  // // arr == arr 배열의 첫번째 값의 주소와 동일 == &arr[0]
  // printf("arr 자체의 값 : %d\n", arr);
  // printf("arr[0]의 주소 : %d\n", &arr[0]);

  // printf("arr 자체의 값이 가지는 주소의 실제 값 : %d\n", *arr); // *(arr + 0)
  // printf("arr[0] 의 실제 값 : %d\n", *&arr[0]);

  // // *& 는 아무것도 없는 것과 같다. & 는 주소이며, * 는 그 주소의 값이기 때문에
  // // *& 는 서로 상쇄된다.
  // printf("arr[0]의 실제 값 : %d\n", *&arr[0]);
  // printf("arr[0]의 실제 값 : %d\n", arr[0]);

  return 0;
}