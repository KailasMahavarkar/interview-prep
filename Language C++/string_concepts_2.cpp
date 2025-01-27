#include <bits/stdc++.h>
using namespace std;


void replace(string &str, string from, string to){
    size_t pos = str.find(from);

    if (pos != string::npos){
        // replace(pos_found, how_many_position_after_pos_to_replace_by, what_to_Sreplace)
        str.replace(pos, from.size(), to); 
    }
}

void replace_all(string &str, string from, string to) {
    // we try to find the string for 1st time
    size_t pos = str.find(from);

    while(pos != string::npos){
        // assuming we found the string... we need to perform replacement
        str.replace(pos, from.size(), to);

        // we need to find next occurence of the from string while avoiding infinite loop
        pos = str.find(from, pos + to.size());
    }
}

int main() {
    string s = "umm i like to say something to this girl... umm... its hard... idk why for this girl";
    //           x                                           y
    string replaceText = "123";
    string searchText = "umm";

    size_t pos = s.find(searchText);
    replace(s, searchText, replaceText);

    // custom_replace_all(s, searchText, replaceText);
    cout << "s --> " << s << endl;
}