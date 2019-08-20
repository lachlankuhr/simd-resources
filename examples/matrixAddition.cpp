#include <iostream>
#include <immintrin.h>
float vsum(float *vectorInput, int n) {
  __m128 vv, vectorHold;
  float sum = 0.0f;
  int i;
  vectorHold = _mm_setzero_ps();
  for (i = 0; i < n - 4 + 1; i += 4) {
    vv = _mm_loadu_ps(&vectorInput[i]);
    vectorHold = _mm_add_ps(vv, vectorHold);
  }
  sum = vectorHold[0] + vectorHold[1] + 
        vectorHold[2] + vectorHold[3];
  for (; i < n; i++) {
    sum += vectorInput[i];
  }
  return sum;
}



int main() {
  float x[12] = {6,5,4,5,6,7,8,4,5,6,7,12};
  printf("%f\n",vsum(x,12));
  return 0;
}





