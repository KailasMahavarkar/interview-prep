#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

class SolutionBruteForce {
   public:
    int mySqrt(int x) {
        int i = 0;

        while (i < x) {
            if ((long long)i * i > x) {
                break;
            }
            i++;
        }

        return i - 1;
    }
};

class Solution {
   public:
    int mySqrt(int x) {
        if (x < 2) return x;

        int s = 0, e = x;
        int result = 0;

        while (s <= e) {
            int mid = s + (e - s) / 2;

            if ((long long)mid * mid <= x) {
                result = mid;
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }

        return result;
    }
};

int main() {
    int x = 8;
    SolutionBruteForce sol;
    cout << "ans -->" << sol.mySqrt(x) << endl;
}
