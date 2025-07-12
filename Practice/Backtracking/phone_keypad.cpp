#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

void printVS(string str){
    for(int i=0; i< str.size(); i++){
        cout << str[i] << " ";
    } cout << endl;
}

 
void solve(string digits, vector<string>& ans, string output, int index,string mapping[]){
    // base condition
    if (index >= digits.length()){
        ans.push_back(output);
        return;
    }

    // current char of digit
    // - '0' for ascii conversion
    int currentChar = digits[index] - '0';
    string mapString = mapping[currentChar];

    for (int i=0; i < mapString.length(); i++){
        output.push_back(mapString[i]);
        solve(digits, ans, output, index + 1, mapping);
        // printVS(output);

        // backtracking step to clear previous output
        output.pop_back();
    }

}

void keypadCombinations(string digits){

    vector<string> ans;
    string output = "";
    string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqr", "stuv", "wxyz"};
    int index = 0;
    solve(digits, ans, output, index, mapping);

}


int main(){
    string str = "92";
    keypadCombinations(str);
}