#include <bits/stdc++.h>
using namespace std;

class ListNode {
   public:
    int data;
    ListNode* next;
    ListNode* back;

    ListNode(int x) {
        this->data = x;
        this->next = nullptr;
        this->back = nullptr;
    }

    ListNode(int x, ListNode* backward, ListNode* forward) {
        this->data = x;
        this->back = backward;
        this->next = forward;
    }
};

ListNode* vectorToDLL(vector<int>& arr) {
    if (arr.size() == 0) {
        return nullptr;
    }

    ListNode* head = new ListNode(arr[0]);
    ListNode* prev = head;

    for (int i = 1; i < arr.size(); i++) {
        // create a new node that is floating in space -> call it temp
        ListNode* temp = new ListNode(arr[i]);

        // connect that mid's back to prev
        // [prev which is head]-----[temp]-----[next which is nullptr]
        temp->back = prev;

        // now this new prev will be current temp
        // so we move pointer of prev->next to temp (our new previous)
        prev->next = temp;

        prev = prev->next;
    }

    return head;
}

ListNode* deleteHeadDLL(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return nullptr;
    }

    ListNode* temp = head;
    head = head->next;

    temp->back = nullptr;
    temp->next = nullptr;
    delete temp;

    head->back = nullptr;

    return head;
}

ListNode* deleteTailDLL(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return nullptr;
    }

    ListNode* tail = head;
    while (tail->next != nullptr) {
        tail = tail->next;
    }

    // temp must be pointing at last element in linked list
    ListNode* newTail = tail->back;
    newTail->next = nullptr;
    tail->back = nullptr;

    delete tail;

    return head;
}

ListNode* deleteKthNodeDLL(ListNode* head, int k) {
    if (head == nullptr) return head;

    int count = 0;
    ListNode* kthNode = head;

    while (kthNode != nullptr) {
        count++;
        if (count == k) break;
        kthNode = kthNode->next;
    }

    // I must be at kth node
    ListNode* prev = kthNode->back;
    ListNode* nxt = kthNode->next;

    if (prev == nullptr && nxt == nullptr) {
        delete kthNode;
        return nullptr;
    } else if (prev == nullptr) {
        return deleteHeadDLL(head);
    } else if (nxt == nullptr) {
        return deleteTailDLL(head);
    } else {
        prev->next = nxt;
        nxt->back = prev;

        kthNode->next = nullptr;
        kthNode->back = nullptr;

        delete kthNode;
        return head;
    }
}

ListNode* insertBeforeHead(ListNode* head, int x) {
    if (head == nullptr) {
        return new ListNode(x);
    }

    ListNode* newHead = new ListNode(x, nullptr, head);
    head->back = newHead;
    return newHead;
}

ListNode* insertBeforeTail(ListNode* head, int x) {
    if (head == nullptr) {
        ListNode* newHead = new ListNode(x, nullptr, head);
        return newHead;
    }

    ListNode* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    ListNode* prev = temp->back;

    // temp must be pointing at last node at this point
    ListNode* newHead = new ListNode(x, prev, temp);
    temp->back = newHead;
    prev->next = newHead;

    return head;
}

ListNode* insertBeforeKthNode(ListNode* head, int k, int x) {
    if (head == nullptr || k == 1) {
        return insertBeforeHead(head, x);
    }

    int count = 0;
    ListNode* temp = head;
    while (temp->next != nullptr) {
        count++;
        if (count == k) {
            break;
        }
        temp = temp->next;
    }

    // we must be standint at node
    ListNode* prev = temp->back;

    // temp must be pointing at last node at this point
    ListNode* newHead = new ListNode(x, prev, temp);
    temp->back = newHead;
    prev->next = newHead;
    return head;
}

void printDLL(ListNode* head) {
    if (head == nullptr) {
        cout << "ll is empty" << endl;
        return;
    }
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    vector<int> arr = {3, 2, 0, 1};
    ListNode* ll = vectorToDLL(arr);
    ListNode* newLL = insertBeforeKthNode(ll, 1, 8);
    printDLL(newLL);
}