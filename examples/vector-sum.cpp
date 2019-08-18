#include <iostream>

using namespace std;

float vsum(float *v, int n) {
    float s = 0.0;

    #pragma omp simd
    for (int i = 0; i < n; i++) {
        s += v[i];
    }
    
    return s;
}

int main() {
    cout << sizeof(long int) << endl;
    return 0;
}


