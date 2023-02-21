#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<vector<int>> vvi;

void printVI(vector<int> arr){
    cout << "vector --> ";
    for (int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    } cout << endl;
}


class Solution {
public:
    ll maxMatrixSum(vvi& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        ll res = INT_MIN;

        // make 2 pointers
        int left = 0;
        int right = 0;

        // loop over cols
        for (int l=0; l < cols; ++l){
            vector<ll> sums(rows);
            for (int r=l; r < cols; ++r){
                for (int i=0; i < rows; i++){
                    sums[i] += matrix[i][r];
                }
                res = max(res, *max_element(sums.begin(), sums.end()));                 
            }
        }
        return res;
    }
};

// [[1,-1],[-1,1]]
int main(){
    vector<vector<int>> sample = {
        {1, -1}, 
        {-1, 1}
    };
    Solution sol;
    int ans = sol.maxMatrixSum(sample);
    cout << ans << endl;
}