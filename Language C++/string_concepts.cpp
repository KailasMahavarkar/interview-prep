#include <bits/stdc++.h>
using namespace std;

int main() {
    string str = "pppppouia";
    //            kai
    //            012
    // cout << str.substr(0, 3) << endl;  <- ( ] ... 0 is inclusive, 3 is exclusive
    char c = str[1];
    cout << "charr --> " << c << endl;
    size_t pos = str.find("ell");  // Returns 1 (starting index)

    int res = str.find_first_of("aeiou");

    cout << "res --> " << res << endl;
}