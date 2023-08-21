#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
    int data;
    Node* next = NULL;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }

    ~Node() {
        if (this->next != NULL) {
            delete this->next;
            this->next = NULL;
        }
    }
};

void insertNode(Node*& tail, int element, int data) {
    // empty list h
    if (tail == NULL) {
        Node* temp = new Node(data);
        tail = temp;
        temp->next = temp;
    }
    // list me 1 element h
    else {
        Node* curr = tail;

        while (curr->data != element) {
            curr = curr->next;
        }

        // abhi curr pointer data pe hoga jo search karna tha
        Node* temp = new Node(data);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void deleteNode(Node*& tail, int data) {
    if (tail == NULL) {
        cout << "list is empty, recheck it" << endl;
        return;
    } else {
        // list is not empty and element is present in linked list
        Node* prev = tail;
        Node* curr = prev->next;

        while (curr->data != data) {
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;

        if (tail == curr) {
            tail = prev;
        }

        curr->next = NULL;
        delete curr;
    }
}

void printLL(Node* tail) {
    if (tail == NULL) {
        cout << "list is empty, recheck it" << endl;
        return;
    }

    Node* temp = tail;

    while (tail->next != temp) {
        cout << tail->data << " ";
        tail = tail->next;
    }
    cout << tail->data << endl;
}

bool isCircular(Node* head) {
    if (head == NULL)
        return true;

    Node* temp = head->next;

    // temp != NULL -> non-circular case
    // temp != head -> circular case
    while (temp != head && temp != NULL) {
        temp = temp->next;
    }

    if (temp == head) {
        return true;
    }
    return false;
}

bool detectLoop(Node* head) {
    if (head == NULL) {
        return false;
    }

    map<Node*, bool> visited;

    Node* temp = head;

    while (temp != NULL) {
        // cycle is present
        if (visited[temp] == true) {
            return 1;
        }
        visited[temp] = true;
        temp = temp->next;
    }

    return false;
}

int main() {
    Node* tail = NULL;
    insertNode(tail, 0, 3);
    insertNode(tail, 3, 5);
    deleteNode(tail, 3);
    insertNode(tail, 5, 7);

    bool answer = isCircular(tail);

    if (answer) {
        cout << "its circular" << endl;
    } else {
        cout << "its not ciruclar" << endl;
    }

    // printLL(tail);
}