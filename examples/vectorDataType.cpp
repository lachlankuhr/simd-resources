/* vectorf is a vector of elements of type float; 
variables of type vectorf occupy 16 bytes 
of contiguous memory */
#include <iostream>
typedef float vectorf __attribute__((vector_size(16)));
#define VLEN (sizeof(vectorf) / sizeof(float))
float vsum(float *vectorInput, int vectorSize)
{
  vectorf vectorHold = {0.0f, 0.0f, 0.0f, 0.0f};
  vectorf *vv = (vectorf *)vectorInput;
  int i;
  float sum = 0.0f;
  for (i = 0; i < vectorSize - VLEN + 1; i += VLEN)
  {
    vectorHold += *vv;
    vv++;
  }
  sum = vectorHold[0] + vectorHold[1] + 
          vectorHold[2] + vectorHold[3];
  for (; i < vectorSize; i++)
  {
    sum += vectorInput[i];
  }
  return sum;
}


int main() {
  float x[12] = {6,5,4,5,6,7,8,4,5,6,7,12};
  printf("%f\n",vsum(x,12));
  return 0;
}
