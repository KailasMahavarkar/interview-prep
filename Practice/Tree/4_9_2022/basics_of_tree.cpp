#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

class node{
    public:
    int data;
    node* left = NULL;
    node* right = NULL;

    node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node* buildTree(node* root){

    cout << "Enter the data: " << endl;
    int data;
    cin >> data;

    root = new node(data);

    if (data == -1){
        return NULL;
    }

    // add left nodes
    cout << "add node left of " << root->data << endl;
    root->left = buildTree(root->left);

    // add right nodes
    cout << "add node right of " << root->right << endl;
    root->right = buildTree(root->right);

    return root;
}

void levelOrderTraversal(node* root){

    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()){
        node* temp = q.front();
        q.pop();

        if (temp == NULL){
            cout << endl;
            if (!q.empty()){
                q.push(NULL);
            }
        }else{
            cout << temp->data << " ";
            if (temp->left){
                q.push(temp->left);
            }
            if (temp->right){
                q.push(temp->right);
            }
        }
    }

}

int main(){
    node* root = NULL;

    root = buildTree(root);
    levelOrderTraversal(root);

}