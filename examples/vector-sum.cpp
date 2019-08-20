#include <iostream>

using namespace std;

float vsum(float *v, int n) {
    float s = 0.0;

    for (int i = 0; i < n; i++) {
        s += v[i];
    }
    return s;
}

int main() {
    float foo[4] = {16, 2, 77, 40}; 
    float res = vsum(foo, 4);
    cout << res << endl;
    return 0;
}

// gcc -O3 -fopt-info-vec vector-sum.cpp -lstdc++
