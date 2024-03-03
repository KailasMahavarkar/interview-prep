#include <bits/stdc++.h>
using namespace std;

int main() {
    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            for(int k = j+1; k < 5; k++){
                if (nums[i] < nums[j] && nums[j] < nums[k]){
                    return true;
                }
            }
        }
    }
    return false;

    string currString = "abcd";
    cout << currString.substr(0, 3) << endl;
}