#include <iostream>

int main() {
  int ia = 1;
  int *ip = &ia; // (1)
  *ip = 2; // (2)
  printf("ia=%d, *ip=%d", ia, *ip); // (3)
}