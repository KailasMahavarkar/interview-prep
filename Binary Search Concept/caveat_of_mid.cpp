#include <bits/stdc++.h>
using namespace std;

int main() {
    int s = INT_MAX - 1;  // 2^31 - 2
    int e = INT_MAX;      // 2^31 - 1

    // Unsafe middle calculation that can overflow
    int midUnsafe = (s + e) / 2;
    cout << "Unsafe Mid: " << midUnsafe << endl;

    // Safe middle calculation
    int midSafe = s + (e - s) / 2;
    cout << "Safe Mid: " << midSafe << endl;

    return 0;
}
