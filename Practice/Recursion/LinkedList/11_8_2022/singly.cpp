#include <algorithm>
#include <climits>
#include <iostream>
#include <iterator>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

class Node
{
public:
    int data;
    Node* next = NULL;

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
    Node* temp = head;
    while (temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    } cout << endl;

}

void insertAtHead(Node* &head, int data)
{
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int data){
    Node* temp = new Node(data);
    tail->next = temp;
    tail = temp;
}

void insertAtPosition(Node* &head, Node* &tail, int position, int data){
    Node* temp = head;

    if (position == 1){
        insertAtHead(head, data);
        return;
    }

    int counter = 1;

    while(counter < (position - 1)){
        cout << temp->data << endl;
        temp = temp->next;
        counter++;
    }

    if (temp->next == NULL){
        insertAtTail(tail, data);
        return;
    }

    Node* NodeToInsert = new Node(data);
    NodeToInsert->next = temp->next;
    temp->next = NodeToInsert;

    cout << ">> " << head->data << endl;
    
}


void deleteAtPosition(Node* &head, int position){
    // deleting ar start
    if (position == 1){
        Node* temp = head;
        head = head->next;

        // memory free 
        temp->next = NULL;
        delete temp;

    }else{
        // deleting any middle or last node
        Node* curr = head;
        Node* prev = NULL;
        int count = 1;

        while(count < position){
            prev = curr;
            curr = curr->next;
            count++;
        }

        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

void printMeta(Node* head, Node* tail){
    cout << "head is pointing at : " << head->data << endl;
    cout << "tail is pointing at : " << tail->data << endl;
}

int main()
{
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    insertAtPosition(head, tail, 2, 30);
    insertAtPosition(head, tail, 2, 20);

    printLL(head);
    printMeta(head, tail);


    deleteAtPosition(head, 3);

    printLL(head);
    printMeta(head, tail);

    


}