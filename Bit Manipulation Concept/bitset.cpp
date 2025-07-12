#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

class Solution {
   public:
    int bitsetPuzzle(vector<int>& arr) {
        bitset<8> bs;

        bs[1] = 1;
        bs[4] = 1;
        bs[5] = 1;

        // bitset to int
        int ans = (int)bs.to_ulong();
        cout << "ans --> " << ans << endl;

        // int to bitset
        int num = 50;
        bs = num;

        cout << "new bitset -->" << bs << endl;

        // bitset to int
        int ans2 = (int)bs.to_ulong();
        cout << "ans2 --> " << ans2 << endl;

        vector<bitset<8>> v;
        v.push_back(bs);

        return -1;
    }
};

int main() {
    vector<int> arr = {4, 3, 5, 2};
    Solution sol;
    int ans = sol.bitsetPuzzle(arr);
    cout << "ans --> " << ans << endl;
}