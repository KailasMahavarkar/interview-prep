#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

typedef vector<vector<string>> vvs;
typedef vector<string> vs;

void printVS(string str){
    for(int i=0; i< str.size(); i++){
        cout << str[i] << " ";
    } cout << endl;
}

void solve(string str, int index, vs& answer){
    if (index >= str.length()){
        answer.push_back(str);
        return;
    }

    for (int i=index; i < str.length(); i++){
        swap(str[index], str[i]);
        solve(str, index+1, answer);

        // backtrack
        swap(str[index], str[i]);
    }

    
}

int main(){
    vs answer;
    string str = "kai";
    int index = 0;
    solve(str, index, answer);

    return 1;
}