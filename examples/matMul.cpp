
//g++ -O3 -march=native -ffast-math -flto matMul.cpp -o matMul
#include <immintrin.h>
#include <iostream>

int main()
{
    float matrixA[4][4] = {{1, 2, 3, 4}, {5,6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    float matrixB[4][4] = {{16, 2, 77, 40}, {16, 2, 77, 40}, {16, 2, 77, 40}, {16, 2, 77, 40}};
    float matrixC[4][4] = {};

    __m128 x, y, result;
    int size = 4;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 3; j += 4)
        {
            result = _mm_set1_ps(0);
            for (int k = 0; k < size; k++)
            {
                x = _mm_set1_ps(matrixA[i][k]);
                y = _mm_loadu_ps(matrixB[k]);
                result = _mm_add_ps(_mm_mul_ps(x, y), result);
            }
            _mm_storeu_ps(&matrixC[i][j], result);
        }
    }
    for (int a = 0; a < 4; a++)
    {
        for (int b = 0; b < 4; b++)
        {
            printf("%.1f ", matrixC[a][b]);
        }
        printf("\n");
    }
    return 0;
}
