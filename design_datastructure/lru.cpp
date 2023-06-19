#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

void printLL(Node* head) {
    if (head == NULL) {
        cout << "Empty Linked list" << endl;
    } else {
        Node* temp = head;
        cout << endl;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

class LRUCache {
   public:
    int capacity;
    map<int, Node*> hmap;
    Node* head = NULL;
    Node* tail = NULL;

    LRUCache(int capacity) {
        this->capacity = capacity;
        this->head = new Node(-1);
        this->tail = new Node(-1);
    }

    int get(int key) {
        // check if key in hmap
        if (hmap.find(key) != hmap.end()) {
            Node* node = hmap[key];

            // when we access get query we have to update LRU
            moveToTail(node);

            // key surely exists
            // thus its reference in DLL must exists
            return node->data;
        }

        return -1;
    }

    void put(int key, int value) {
        if (hmap.find(key) != hmap.end()) {
            Node* node = hmap[key];
            node->data = value;
            moveToTail(node);
        } else {
            // check if capacity has been reached
            if (hmap.size() == capacity) {
                // remove item from hmap
                Node* nodeToRemove = head->next;
                removeNode(nodeToRemove);

                // erase ref from hmap
                hmap.erase(nodeToRemove->data);

                // deallocate memory
                delete nodeToRemove;
            } else {
                // add item to linked list and hmap
                Node* newNode = new Node(value);
                hmap[key] = newNode;
                insertAtTail(newNode);
            }
        }
    }

   private:
    void moveToTail(Node* node) {
        removeNode(node);
        insertAtTail(node);
    }

    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insertAtTail(Node* node) {
        node->prev = tail->prev;
        tail->prev->next = node;
        node->next = tail;
        tail->prev = node;
    }
};

int main() {
    // use LRUCache class
    LRUCache* cache = new LRUCache(5);
    cout << cache->capacity << endl;
    cache->put(1, 1);
    cache->put(2, 2);
    cout << cache->get(1) << endl;  // returns 1
    // cache->put(3, 3);               // evicts key 2
    // cout << cache->get(2) << endl;  // returns -1 (not found)
    // cache->put(4, 4);               // evicts key 1
    // cout << cache->get(1) << endl;  // returns -1 (not found)
    // cout << cache->get(3) << endl;  // returns 3
    // cout << cache->get(4) << endl;  // returns 4
    return 0;
}