#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>

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

// printing tree values in pre-order method (DFS)
void printDFS(Node *root) {

    // base case
    if(root == nullptr)
        return;
    
    // recursion calls
    std::cout << root->value << " ";
    printDFS(root->left);
    printDFS(root->right);

}

// printing tree values in pre-order method (DFS) interative
void preorderInterative(Node *root) {

    if(root == nullptr)
        return;

    // using stack to store the values
    std::stack<Node*> st;
    st.push(root);
    while(!st.empty()) {
        Node *node = st.top();
        st.pop();
        std::cout << node->value << " ";
        if(node->right != NULL)
            st.push(node->right);
        if(node->left != NULL)
            st.push(node->left);
        }
    }

// printing tree values by level (BFS)
std::vector<std::vector<int>> leveOrderBFS(Node *root) {
    
    std::vector<std::vector<int>> ans;

    // checking if the tree exist
    if(root == nullptr)
        return ans;
    
    std::queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        int size = q.size();
        std::vector<int> level;
        for(int i = 0; i < size; ++i) {
            Node *node = q.front();
            q.pop();
            if(node->left != nullptr) 
                q.push(node->left);
            if(node->right != nullptr) 
                q.push(node->right);
            level.push_back(node->value);
        }
        ans.push_back(level);
    }
    return ans;
}

// Maximum depth of a binary tree
int maxDepth(Node *tree) {

    if(tree == nullptr)
        return 0;


    int left = maxDepth(tree->left);
    int right = maxDepth(tree->right);

    return 1+std::max(left,right);

}



int main(void){

    Node *tree = newNode(12);
    insert(tree,9);
    insert(tree,7);
    insert(tree,10);
    insert(tree,13);
    insert(tree,14);

    std::cout << "Max depth of the tree: ";
    std::cout << maxDepth(tree) << std::endl;

    std::cout << "DFS(pre-order) traversal: ";
    printDFS(tree);
    std::cout << std::endl;

    std::vector<std::vector<int>> bfsTraversal = leveOrderBFS(tree);
    std::cout << "BFS traversal: ";
    for(const auto& level : bfsTraversal) {
        for(const auto& value : level)
            std::cout << value << " ";
    }
    std::cout << std::endl;

    std::cout << "Preorder Interative: ";
    preorderInterative(tree);
    std::cout << std::endl;
    
}



