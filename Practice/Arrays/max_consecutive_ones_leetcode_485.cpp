#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int gmax = 0;
        int curr = 0;
        for (int i=0; i < nums.size(); i++){
            if (nums[i] == 1){
                curr++;
                gmax = max(curr, gmax);
            }else{
                curr = 0;
            }
            cout << "curr --> " << curr << endl;
            cout << "gmax --> " << gmax << endl;
            cout << endl;
        }

        return gmax;
    }
};

int main(){
    vector<int> arr = {1,1,0,1,1,1};
    Solution sol;
    int ans = sol.findMaxConsecutiveOnes(arr);
    cout << "answer: " << ans << endl;
}