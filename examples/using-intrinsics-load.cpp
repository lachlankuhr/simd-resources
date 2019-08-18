#include "nmmintrin.h"
#include <iostream>

using namespace std;

int main() {
    /* SSE register is 128 bits wide and is named __m128 and is used to store 4 floats.
    Using a union, we can access the memory locations of the four floats in __m128. */
    union { __m128 a4; float a[4]; }; 

    /* __mm_set_ps keywords are called intrinsics. SSE intrinics all compile to a single assembler instruction.
    This means we are essentially writing assembly in C++. There is an intrinics for nearly all scalar operations. */
    a4 = _mm_set_ps(4.0f, 4.1f, 4.2f, 4.3f);

    // Prints out in reverse order. Standard practice by Intel. 
    for (int i = 0; i < 4; ++i) {
        cout << a4[i] << endl;
    }

    return 0;
}

