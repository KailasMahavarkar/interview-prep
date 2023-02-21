#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> vvi;
typedef vector<int> vi;

void printVI(vi arr){
    for (int i=0; i < arr.size(); i++){
        cout << arr[i] << " ";
    } cout << endl;
}


void solve(vi nums, vi output, vvi& ans, int index){
    if (index > nums.size()){
        return;
    }

    // exclude call
    solve(nums, output, ans, index+1);

    // include call
    output.push_back(nums[index]);
    solve(nums, output, ans, index+1);
}


vvi powerSet(vi nums){
    vvi ans;
    vi output;

    int index = 0;
    solve(nums, output, ans, index);
    return ans;
}

int main(){
    
    vi arr = {1, 2, 3};
    powerSet(arr);
    
}