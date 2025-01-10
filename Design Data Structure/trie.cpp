#include <bits/stdc++.h>
using namespace std;

struct trieNode {
    bool isEndOfWord;
    trieNode* children[26];
};

class Trie {
   public:
    trieNode* root;
    Trie() {
        root = makeNode();
    }

    trieNode* makeNode() {
        trieNode* newNode = new trieNode();
        newNode->isEndOfWord = false;

        for (int i = 0; i < 26; i++) {
            newNode->children[i] = NULL;
        }

        return newNode;
    }

    void insert(string word) {
        trieNode* crawler = root;

        for (auto& ch : word) {
            int idx = ch - 'a';

            if (crawler->children[idx] == NULL) {
                trieNode* temp = makeNode();
                crawler->children[idx] = temp;
            }
            crawler = crawler->children[idx];
        }

        crawler->isEndOfWord = true;
    }

    bool search(string word) {
        trieNode* crawler = root;

        for (auto& ch : word) {
            int idx = ch - 'a';

            if (crawler->children[idx] == NULL) {
                return false;
            }

            crawler = crawler->children[idx];
        }

        if (crawler != NULL && crawler->isEndOfWord) {
            return true;
        }
        return false;
    }

    bool startsWith(string prefix) {
        trieNode* crawler = root;
        int i = 0;

        for (auto& ch : prefix) {
            int idx = ch - 'a';

            if (crawler->children[idx] == NULL) {
                return false;
            }

            crawler = crawler->children[idx];
            i++;
        }

        if (i == prefix.length()) {
            return true;
        }
        return false;
    }
};

int main() {
    Trie* trie = new Trie();

    trie->insert("apple");
    cout << "Search 'apple': " << trie->search("apple") << endl;      // Returns true
    cout << "Search 'app': " << trie->search("app") << endl;          // Returns false
    cout << "StartsWith 'app': " << trie->startsWith("app") << endl;  // Returns true
    trie->insert("app");
    cout << "Search 'app' after inserting 'app': " << trie->search("app") << endl;  // Returns true

    delete trie;
    return 0;
}