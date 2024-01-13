#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main() {
    int num1 = 6;
    int num2 = 4;

    int result = lcm(num1, num2);
    cout << "LCM: " << result << endl;
    return 0;
}
