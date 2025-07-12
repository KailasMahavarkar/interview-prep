#include <algorithm>
#include <climits>
#include <iostream>
#include <numeric>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int num1 = 6;
    int num2 = 4;

    int result = gcd(num1, num2);
    cout << "GCD: " << result << endl;
    return 0;
}
