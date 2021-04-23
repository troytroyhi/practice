#include <iostream>

int main() {
  float fa = 1.1, fb = 2.2;
  float *pf;
  
  pf = &fa;
  *pf = 11.1; // (2)

  pf = &fb;
  *pf = 22.2;

  printf("fa=%.2f, fb=%.2f\n", fa, fb); // (3)
}