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

            // Sliding window to figure out maximum line length
            // current formed length + (end - start) <-- spaces shoud not exceed maxWidth
            while (end < words.size() && lineLength + words[end].length() + end - start <= maxWidth) {
                lineLength += words[end].length();
                end++;
            }

            int numOfWords = end - start;
            int spaces = maxWidth - lineLength;

            string line = words[start];

            // Case 1: (single word)
            // since we already added word to line
            // we just need to add remaining spaces

            // Case 2: (Multiple words and words getting added to last line)
            // we add words and its spaces
            // we later add remaining spaces
            // Note: In this specific scenario we are justifying text to left and then adding spaces

            // Case 3: (Multiple words) -> normal line
            // we need to carefully measure how many extraspaces we have
            // we then need to distribute these extra spaces after each word

            if (numOfWords == 1) {
                line += string(maxWidth - line.length(), ' ');
            } else if (end == words.size()) {
                // we are justifying content to left (as per question) then adding spaces
                for (int i = start + 1; i < end; i++) {
                    line += " " + words[i];
                }
                line += string(maxWidth - line.length(), ' ');
            } else {
                for (int i = start + 1; i < end; i++) {
                    int extraSpaces = (spaces / (numOfWords - 1)) + ((spaces % (numOfWords - 1)) > 0 ? 1 : 0);
                    line += string(extraSpaces, ' ') + words[i];
                    spaces -= extraSpaces;
                    numOfWords--;
                }
            }

            start = end;
            result.push_back(line);
        }
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
