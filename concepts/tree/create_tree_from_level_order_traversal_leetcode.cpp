#include <bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;

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
    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);

    cout << "Enter data for inserting in right of "<< data << endl;
    root->right = buildTree(root->right);
    return root;
}

void levelOrderTraversal(node* &root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        if (temp == NULL){
            // check if there are any elements
            // enter + add NULL
            if (!q.empty()){
                cout << endl;
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

void buildFromLevelOrder(node* &root){
    queue<node*> q;

    cout << "Enter Data for root" << endl;
    int data;
    cin >> data;
    root = new node(data);
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        cout << "enter left node for "<< temp->data << endl;
        int leftData;
        cin >> leftData;

        if (leftData != -1){
            temp->left = new node(leftData);
            q.push(temp->left);
        }

        cout << "enter right node for "<< temp->data << endl;
        int rightData;
        cin >> rightData;

        if (rightData != -1){
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }
}


void inorderTraversal(node* root, int &count){
    if (root == NULL){
        return;
    }
    inorderTraversal(root->left, count);

    if (root->left == NULL && root->right == NULL){
        count++;
    }

    inorderTraversal(root->right, count);

}

int countLeafNodes(node* root){
    int count = 0;
    inorderTraversal(root, count);
    return count;
}


int main(){
    node* root = NULL;
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // 1 2 4 -1 -1 3 -1 -1 -1

    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
    // create A tree
    // root = buildTree(root);

    // root = buildFromLevelOrder(root);
    // printLevelOrderTraversal(root);

    // buildFromLevelOrder(root);
    // levelOrderTraversal(root);

    root = buildTree(root);
    int leafCount = countLeafNodes(root);
    cout << leafCount << endl;
    

    return 0;
}