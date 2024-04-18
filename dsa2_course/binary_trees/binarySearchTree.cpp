#include <bits/stdc++.h>
using namespace std;

class Node {

public:
    int key;
    Node *left;
    Node *right;

    Node(int key) {
        this->key = key;
        left = right = NULL;
    }

};

Node *insert(Node *root, int x){

    // base condition
    if(root == NULL) {
        Node *n = new Node(x);
        return n;
    }

    // rec case
    if(x < root->key) {
        root->left = insert(root->left,x);
    } else
        root->right = insert(root->right,x);

    return root;
}

bool search(Node *root, int key) {

    if(root==NULL)
        return false;

    if(key < root->key)
        search(root->left,key);
    else
        search(root->right,key);

    return true;

}

void print_inorder(Node *root){

    // base condition
    if(root == NULL)
        return;
    
    // recursion call (left, root, right)
    print_inorder(root->left);
    cout << root->key << " ";
    print_inorder(root->right);

}

int main(){

    Node *root = NULL;
    int arr[] = {8,3,10,1,6,14,4,7,13};

    for(int element : arr) 
        root = insert(root,element);

    print_inorder(root);
    cout << endl;

    if(search(root,13))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return EXIT_SUCCESS;
}