#include <algorithm>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <list>
#include <string>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;


class Node{
    public:
    int data;
    Node *next;
    Node *prev;


    // constructor
    Node(int data){
        this ->data = data;
        this ->next = NULL;
        this ->prev = NULL;
    }

    // destructor
    ~Node(){
        if (this ->next != NULL){
            
            this ->prev = NULL;
            this ->next = NULL;
            delete this ->next;
            delete this ->prev;
            cout << "mem free" << this ->data << endl;
            
        }
    }

};

void printLL(Node* head){
    if (head == NULL){
        cout << "Empty Linked list" << endl;
    }else{
        Node* temp = head;
        cout << endl;
        while (temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

void printNode(Node* node, string name){
    cout << endl;
    cout << name <<" data: " << node->data << endl;
    cout << name <<" prev: " << node->prev << endl;
    cout << name <<" next: " << node->next << endl;
}

int getLength(Node* head){
    int count = 0;
    Node* temp = head;
    while (temp != NULL){
        temp = temp->next;
        count++;
    }
    return count;
}

void insertAtHead(Node* &head, Node* &tail, int data){
    if (head == NULL){
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
    }else{
        Node* temp = new Node(data);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void insertAtTail(Node* &head, Node* &tail, int data){
    if (tail == NULL){
        Node* temp = new Node(data);
        tail = temp;
        head = temp;
    }else{
        Node* temp = new Node(data);
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
    }
}

void insertAtMiddle(Node* &head, Node* &tail,  int position, int data){
    if (position == 1){
        insertAtHead(head,tail, data);
        return;
    }

    Node* prev = NULL;
    Node* curr = head;

    int count = 1;
    while (count < position - 1){
        prev = curr;
        curr = curr->next;
        count++;
    }

    if (curr->next == NULL){
        insertAtTail(head, tail, data);
        return;
    }

    Node* temp = new Node(data);
    curr->prev = temp;
    temp->prev = prev;
    prev->next = temp;
    temp->next = curr;
}


void deleteAtHead(Node* &head){
    head->next->prev = NULL;
    head = head->next;
}

void deleteAtTail(Node* &tail){
    Node* temp = tail;
    delete tail;

    tail = temp->prev;
    temp->prev->next = NULL;
}


void deleteAtPosition(Node* &head, Node* &tail, int position){

    if (position == 1){
        Node* temp = head;

        // break backwards link
        temp->next->prev = NULL;

        // move head
        head = temp->next;

        // break forward link
        temp -> next = NULL;

        // destroy node 
        delete temp;

        return;
    }

    Node* prev = NULL;
    Node* curr = head;

    int count = 1;

    while (count < position){
        prev = curr;
        curr = curr->next;
        count++;
    }

    
    curr->prev = NULL;
    prev->next = curr->next;
    curr->next = NULL;

    delete curr;
}

int main(){

    Node* head = NULL;
    Node* tail = NULL;

    insertAtTail(head, tail, 10);
    insertAtTail(head, tail, 20);
    insertAtTail(head, tail, 30);
    deleteAtPosition(head, tail, 3);

    printLL(head);
    
}