#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
    int val;
    Node *next;
    Node *random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node *vectorToNode(vector<int> &arr) {
    Node *head = new Node(arr[0]);
    Node *temp = head;
    for (int i = 1; i < arr.size(); i++) {
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }
    return head;
}

vector<int> NodeToVector(Node *head) {
    vector<int> arr;
    Node *temp = head;
    while (temp != NULL) {
        arr.push_back(temp->val);
        temp = temp->next;
    }
    return arr;
}

void printLinkedList(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        cout << temp->val << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

class Solution {
   public:
    Node *copyRandomList(Node *head) {
        if (!head)
            return NULL;

        map<Node *, Node *> mp;

        // travel original linked list
        Node *curr = head;
        Node *prev = NULL;  // to connect new linked list while making
        Node *newHead = NULL;

        // this code is like ... snake moving forward dragging it tail (read code you will know it)
        while (curr) {
            Node *temp = new Node(curr->val);
            mp[curr] = temp;
            if (newHead == NULL) {
                newHead = temp;
                prev = newHead;
            } else {
                prev->next = temp;
                prev = temp;
            }
            curr = curr->next;
        }

        // fill random pointers with help or hashmap
        curr = head;
        Node *newCurr = newHead;
        while (curr) {
            if (curr->random == NULL) {
                newCurr->random = NULL;
            } else {
                newCurr->random = mp[curr->random];
            }

            newCurr = newCurr->next;
            curr = curr->next;
        }
        return newHead;
    }
};

int main() {
    vector<int> arr = {7, 13, 11, 10, 1};
    Node *head = vectorToNode(arr);
    printLinkedList(head);

    Solution sol;
    Node *newHead = sol.copyRandomList(head);
    printLinkedList(newHead);

    return 0;
}