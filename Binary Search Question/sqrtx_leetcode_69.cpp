#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int mySqrt(int x) {
        if (x < 2) return x;

        int s = 1, e = x / 2;
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
    Solution sol;
    cout << "ans -->" << sol.mySqrt(x) << endl;
}
