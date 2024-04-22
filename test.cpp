#include <bits/stdc++.h>
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

        return -1;
    }
};

int main() {
    vector<int> arr = {4, 3, 5, 2};
    Solution sol;
    int ans = sol.bitsetPuzzle(arr);
    cout << "ans --> " << ans << endl;
}