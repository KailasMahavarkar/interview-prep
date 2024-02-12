#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int accumulator = 0;
    int steps = 0;

    pair<int, int> balancePair(int numA, int numB) {
        if (numA < numB) {
            swap(numA, numB);
        }
        if (numA == 0 || numB == 0) {
            return make_pair(numA, numB);
        }

        if (numA % 2 == 1 && numB % 2 == 1) {
            if (numA / numB > 1) {
                accumulator += (numA - 1) + numB;
                return balancePair((numA - 1) >> 1, (numB - 1) << 1);
            }
        }

        if (numA % 2 == 0 && numB % 2 == 0) {
            if (numA / numB > 1) {
                return balancePair(numA >> 1, numB << 1);
            }
        }

        if (numA % 2 == 1 && numB % 2 == 0) {
            if (numA / numB > 1) {
                accumulator += numB;
                return balancePair((numA - 1) >> 1, (numB << 1));
            }
        }

        if (numA / numB > 1) {
            accumulator += numA;
            return balancePair(numA >> 1, (numB - 1) << 1);
        }

        return make_pair(numA, numB);
    }

    int square(int num) {
        int pow = 0, res = 0;
        int tmp = num;
        while (tmp) {
            if (tmp & 1) {
                res += (num << pow);
            }
            pow++;
            tmp = tmp >> 1;
        }
        return res;
    }

    int solve(int numA, int numB) {
        if (numA == 0 || numB == 0) {
            return 0;
        }

        if (numA == numB) {
            return square(numA);
        }

        if (numA == 2 && numB == 2) {
            return 4;
        } else if (numA == 1 && numB == 0) {
            return 0;
        }

        int maxN = max(numA, numB);
        int minN = min(numA, numB);

        steps++;
        return square(minN) + solve(minN, maxN - minN);
    }

    int multiply(int numA, int numB) {
        pair<int, int> ans = balancePair(numA, numB);
        return accumulator + solve(ans.first, ans.second);
    }
};

int main() {
    Solution sol;
    int answer = sol.accumulator + sol.multiply(9, 5);
    cout << "answer --> " << answer << endl;
}