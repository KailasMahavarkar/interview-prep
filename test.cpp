#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")

void backtrack(const string &s, int idx, vector<string> &curr, vector<vector<string>> &result) {
    // Adding current list of substrings to the result
    result.push_back(curr);

    // Loop through the string starting from the given index
    for (int i = idx; i < s.size(); i++) {
        if (i == idx) {
            // Generate substrings and add them to the current list
            curr.push_back(s.substr(idx, i - idx + 1));

            // Recursively call the backtrack function to continue the process
            backtrack(s, i + 1, curr, result);

            // Remove the last added substring to backtrack and explore other possibilities
            curr.pop_back();
        }
    }
}

vector<vector<string>> allSubstrings(const string &s) {
    vector<vector<string>> result;
    vector<string> curr;
    backtrack(s, 0, curr, result);
    return result;
}

int main() {
    string s = "bac";
    vector<vector<string>> result = allSubstrings(s);

    // Print all substrings
    for (const auto &subset : result) {
        for (const auto &str : subset) {
            cout << "\"" << str << "\" ";
        }
        cout << endl;
    }

    return 0;
}
