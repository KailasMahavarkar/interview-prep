#include <bits/stdc++.h>
using namespace std;


void printVI(vector<int> arr){
    cout << "vector --> ";
    for (int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    } cout << endl;
}


class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if (matrix.empty()) return 0;

        int res = INT_MIN;
        int rows = matrix.size();
        int cols = matrix[0].size();

        // column wise loop karna h
        for (int l=0; l < cols; ++l){
            // row ke space jitna array allocate karna h 
            vector<int> sums(rows);

            // loop karo r ko (l -> cols)
            for (int r = l; r < cols; ++r){
                for (int i = 0; i < rows; ++i){
                    sums[i] += matrix[i][r];
                }

                set<int> s;
                s.insert(0);

                int running_sum = 0;
                int currMax = INT_MIN;

                for (int sum: sums){
                    running_sum += sum;
                    auto it = s.lower_bound(running_sum - k);
                    if (it != s.end()){
                        currMax = max(currMax, running_sum - *it);
                    }
                    s.insert(running_sum);
                }

                res = max(res, currMax);
            }
        }

        return res;
    }
};


class Solution{
    public:
        int maxSumSubMatrix(vector<vector<int>>& matrix, int k){
           
        }
};


int main(){
    vector<vector<int>> sample = {
        {3, 3}, 
        {2, -3}
    };
    Solution sol;
    int ans = sol.maxSumSubMatrix(sample, 1);
    cout << ans << endl;
}