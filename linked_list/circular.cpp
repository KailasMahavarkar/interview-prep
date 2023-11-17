#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *next = NULL;

    // constructor of type Node(int)
    Node(int data){
        this ->data = data;
        this ->next = NULL;
    }

    // destructor
    ~Node(){
        // mem free
        if (this->next != NULL){
            delete this->next; // clean up chain after current node
            this->next = NULL; // set next to NULL or it will point to garbage memory
        }
        cout << "mem free for node with data: " << (this ->data) << endl;
    }

};

void printLL(Node* &head, int &size){
    int count = 1;
    while (count < size){
        head = head->next;
        cout << head->data << endl;
    } cout << endl;

    cout << "size of LL: " << size << endl;
}



void insertPosition(Node* &tail,int position, int data, int size){

    if (tail->next == NULL){
        tail->next = tail;
    }

    size += 1;

}


int main(){

    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    int size = 1;

    insertPosition(tail, 2, 20, size);
    printLL(head, size);
    

    insertPosition(tail, 3, 30, size);
    printLL(head, size);

    return 0;
}