#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;
string action(string word1, string word2, int i, int idx, int mode) {
    if (mode == 0) {
        word1.insert(i, 1, word2[idx]);
        return word1;
    }

    if (mode == 1) {
        word1.replace(0, 1, word2[idx]);
        return word1;
    }

    word1.erase(i, 1);
    return word1;
}
int main() {
    string s = "kai";
    int i = 0;
    int idx = 0;

    string ans = action("kai", "zeno", i, idx, 1);

    cout << s << endl;
    cout << ans << endl;

    return 0;
}