#include <iostream>
using namespace std;

typedef long long ll;

ll binary_exponentiation_recursive(ll a, ll b) {
    if (b == 0) return 1;

    ll half = binary_exponentiation_recursive(a, b / 2);
    ll result = half * half;

    if (b % 2 == 1) {
        result *= a;
    }

    return result;
}

int binary_exponentiation_iterative(int a, int b) {
    int result = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            result = result * a;
        }
        a = a * a;
        b = b / 2;
    }
    return result;
}

int main() {
    // int a, b;
    // cin >> a >> b;
    cout << binary_exponentiation_recursive(10, 5) << endl;
    return 0;
}