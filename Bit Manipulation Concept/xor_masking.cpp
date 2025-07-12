#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")

int main() {
    // Find Mask between two numbers (can you find at-least one bit which is different)
    // num a = 3
    // num b = 5

    // 0 1 1
    // 1 0 1
    // ------- (XOR)
    // 1 1 0
    // a b c <- lets give them index

    // Method 1 to get MASK: (get mask using loop and count)
    // c bit can only would've been zero if both other bits were 1
    // thus to find 1st non zero bit we could just shift right until we find 1st set bit and hold a count meanwhile
    // while((NUM >> 1) % 2 != 1) {
    // -- NUM >> 1
    // -- count++;
    // }
    // once we break out of it... we could just take 1 -> in binary 000000001
    // and left shift by count number of times to get a valid mask

    // Method 2 to get MASK: (XOR & (-XOR)) i.e (XOR & (2's component of XOR)) = MASK
    // 1 1 0 <- this is XOR of 3 and 5
    // 0 1 0 <- lets take 2's complement of this
    // --------
    // 0 1 0 <- this is & operation on same

    int a = 3;
    int b = 5;

    int xorr = a ^ b;
    int c = xorr & (-xorr);
    cout << bitset<8>(c) << endl;
}
