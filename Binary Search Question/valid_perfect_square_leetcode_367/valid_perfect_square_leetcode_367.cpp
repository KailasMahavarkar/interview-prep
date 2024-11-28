#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")

/*
    Problem Link   : https://leetcode.com/problems/valid-perfect-square/description/
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
    Similarities   : Leetcode 69
*/

// Approach-1 (Normal)
// TC : O(n)
// SC : O(1)
class SolutionBruteforce {
   public:
    bool isPerfectSquare(int num) {
        if (num < 2) return num;

        for (int i = 0; i < num; i++) {
            if ((long long)i * i == num) {
                return true;
            }

            if ((long long)i * i > num) {
                break;
            }
        }

        return false;
    }
};

class Solution {
   public:
    bool isPerfectSquare(int num) {
        int s = 0;
        int e = num;

        while (s <= e) {
            int mid = s + (e - s) / 2;  // safe way to find mid (video-2)

            if ((long long)mid * mid == num) {
                return true;
            }

            if ((long long)mid * mid > num) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }

        return false;
    }
};

int main() {
    int x = 16;
    SolutionBruteforce sol;
    cout << "ans -->" << boolalpha << sol.isPerfectSquare(x) << endl;
}
