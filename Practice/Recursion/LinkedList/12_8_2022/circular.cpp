#include <algorithm>
#include <climits>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

class Node
{
public:
    int data;
    Node *next = NULL;

    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // destructor
    ~Node()
    {
        // when node is deleted
        // check if node is already null
        if (this->next != NULL)
        {
            delete this->next;
            this->next = NULL;
        }
    }
};


// print will always from head never from tail
void printLL(Node* &head){
    Node *temp = head;
    while (temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    } cout << endl;
}

void printMeta(Node* head, Node* tail){
    cout << "head is pointing at : " << head->data << endl;
    cout << "tail is pointing at : " << tail->data << endl;
}


void insertNode(Node* &tail, int element, int data){
    if (tail == NULL){
        Node* temp = new Node(data);
        tail = temp;
        temp->next = temp;
    }else{
        // element is present in list

        Node* curr = tail;

        while(element != curr->data){
            curr = curr->next;
        }

        // element is found and pointing to curr
        Node* temp = new Node(data);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void deleteNode(Node* &tail, int value){

    if (tail == NULL){
        cout << "list is empty" << endl;
        return;
    }else{


        // assuming "value" is present in linked list
        Node* prev = tail;
        Node* curr = prev -> next;

        while(curr->data != value){
            prev = curr;
            curr = curr->next;
        }

        // 1 node in linked list
        if (curr == prev){
            tail = NULL;
        }  

        if (tail == curr){
            tail = prev;
        }

        prev->next = curr->next;
        curr->next = NULL;
        delete curr;

    }
}


void print(Node* tail){
    Node* storedAddress = tail;

    if (tail == NULL){
        cout << "list is empty"<< endl;
        return;
    }

    while(tail->next != storedAddress){
        cout << tail->data << " ";
        tail = tail->next;
    }
    cout << tail->data << endl;
}

int main(){
    Node* tail = NULL;

    insertNode(tail, 5, 3);
    // insertNode(tail, 3, 5);
    // insertNode(tail, 5, 7);
    // insertNode(tail, 5, 6);
    // insertNode(tail, 7, 36);
    // insertNode(tail, 3, 15);

    deleteNode(tail, 3);



    print(tail);

    return 0;
}