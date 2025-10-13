#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
#include <iostream>
#include <stack>


int main() {
string s = "Hello World";

// Length operations
s.size()        // 11
s.length()      // 11 (same as size)
s.empty()       // false
s.capacity()    // Current capacity

// Access operations
s[0]            // 'H'
s.at(0)         // 'H' (with bounds checking)
s.front()       // 'H'
s.back()        // 'd'

// Substring operations
s.substr(6)     // "World"
s.substr(6, 3)  // "Wor"

// Search operations
s.find("Wor")   // 6 (position)
s.find('o')     // 4 (first occurrence)
s.rfind('o')    // 7 (last occurrence)
s.find_first_of("aeiou")  // 1 ('e')
s.find_last_of("aeiou")   // 7 ('o')

// Modification operations
s.push_back('!');           // "Hello World!"
s.pop_back();              // "Hello World"
s.append(" C++");          // "Hello World C++"
s.insert(5, ",");          // "Hello, World C++"
s.erase(5, 1);            // "Hello World C++"
s.replace(6, 5, "C++");    // "Hello C++"

return 0;
}