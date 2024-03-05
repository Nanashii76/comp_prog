#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// Implementation of binary search tree
class Node {

    public:
        int value;
        int height;
        Node *left;
        Node *right;

        // constructor 
        Node(int value) {
            this->value = value;
            this->left = nullptr;
            this->right = nullptr;
            this->height = 0;
        }
};

// Creating new nodes, the first'll be the root
Node *newNode(int n) {
    return new Node(n);
}

// insert nodes
void insert(Node *&root, int n) {

    // if the root is empty we create a new tree, n being root
    if(root == nullptr) {
        newNode(n);
        return;
    }

    // else, check if n is greater than or lesser than actual node
    Node *tmp = root;

    // check the left case
    if(n < tmp->value) {
        if(tmp->left == nullptr) {
            tmp->left = newNode(n);
            return;
        } else
            insert(tmp->left,n);
    } else if(n > tmp->value) // check the right case
        if(tmp->right == nullptr) {
            tmp->right = newNode(n);
            return;
        } else
            insert(tmp->right,n);

}

// printing tree values in pre-order method
void print(Node *root) {

    // base case
    if(root == nullptr)
        return;
    
    // recursion calls
    std::cout << root->value << " ";
    print(root->left);
    print(root->right);

}

// Balancing Binary tree







int main(void){

    Node *tree = newNode(12);
    insert(tree,9);
    insert(tree,7);
    insert(tree,10);
    insert(tree,13);
    insert(tree,14);

    print(tree);


}



