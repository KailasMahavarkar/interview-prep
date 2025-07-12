#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
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

void solve(string str, string output, vs& ans, int index){
    if (index > str.length()){
        if (output.length() > 0){
            ans.push_back(output);
        }
        return;
    }


    // exclude call
    solve(str, output, ans, index+1);

    // include call
    output.push_back(str[index]);
    solve(str, output, ans, index+1);

}

vs subsequence(string str){
    vs ans;
    string output = "";
    int index = 0;
    solve(str, output, ans, index);
    return ans;
}

int main(){
    string str = "kai";
    subsequence(str);

    return 0;
}