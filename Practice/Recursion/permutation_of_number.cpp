#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> vvi;
typedef vector<int> vi;

void printVI(vector<int> nums){
    for(int i=0; i< nums.size(); i++){
        cout << nums[i] << " ";
    } cout << endl;
}

void solve(vi nums, int index, vvi& answer){
    if (index >= nums.size()){
        answer.push_back(nums);
        return;
    }


    for (int i=index; i < nums.size(); i++){
        swap(nums[index], nums[i]);
        solve(nums, index+1, answer);
        
        // backtrack
        swap(nums[index], nums[i]);
    }
    
}

int main(){
    vvi answer;
    vi nums = {1, 2, 3};
    int index = 0;
    solve(nums, index, answer);

    return 1;
}