#include <iostream>
#include <vector>
using namespace std;

#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int start = 0;

        while (start < words.size()) {
            int end = start;
            int lineLength = 0;

            // 1. Sliding window to figure out maximum line length
            // current formed length + (end - start) <-- spaces shoud not exceed maxWidth
            while (end < words.size() && lineLength + words[end].length() + end - start <= maxWidth) {
                lineLength += words[end].length();
                end++;
            }

            int numOfWords = end - start;
            int spaces = maxWidth - lineLength;

            // either this was only words in array or end pointer
            string line = words[start];
            if (numOfWords == 1 || end == words.size()) {
                // concatinate words
                for (int i = start + 1; i < end; i++) {
                    line += " " + words[i];
                }

                // concatinate remaining spaces
                line += string(maxWidth - line.length(), ' ');
            } else {
                // distribute words evenly
                for (int i = start + 1; i < end; i++) {
                    int extraSpaces = (spaces / (numOfWords - 1)) + ((spaces % (numOfWords - 1)) > 0 ? 1 : 0);
                    line += string(extraSpaces, ' ') + words[i];
                    spaces -= extraSpaces;
                    numOfWords--;
                }
            }

            start = end;
        }
        result.push_back(line);
        return result;
    }
};

int main() {
    Solution solution;
    vector<string> words = {"What", "must", "be", "acknowledgment", "s", "be"};
    int maxWidth = 16;

    vector<string> justifiedText = solution.fullJustify(words, maxWidth);

    for (const string& line : justifiedText) {
        cout << line << endl;
    }

    return 0;
}
