#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <stack>
#include <queue>

// Implementing a queue to print elements of a bst in level order
// without using queue STL
// implementing using linked lists
// to use in levelorder(BFS), change to BtsNode;
typedef struct Queue {

    int data;
    Queue *next;

    // constructor class
    Queue(int x) {
        data = x;
        next = NULL;
    }

} Queue;


// check if the queue is already empty
bool isEmpty(Queue *q) {
    if(q == NULL)
        return true;
    else
        return false;
}

// printing elements from a queue
void print_queue(Queue *q) {

    if(isEmpty(q)) {
        std::cout << "NULL" << std::endl;
        return;
    }

    while(q != NULL) {
        std::cout << q->data << " ";
        q = q->next;
    }
    std::cout << std::endl;

}

// add elements to a queue
void add_queue(Queue **q, int x){

    // check if queue is empty
    if(isEmpty(*q)) {
        *q = new Queue(x);
        return;
    }

    // add elements at the final of queue
    Queue *tmp = *q;
    Queue *new_value = new Queue(x);
    while(tmp->next != NULL)
        tmp = tmp->next;
    // adding next element
    tmp->next = new_value;
}

// remove the first element from queue
void pop_queue(Queue **q) {

    // check if queue is empty
    if(isEmpty(*q))
        return;
    
    // remove first element from queue
    Queue *tmp = *q;
    *q = tmp->next;

    delete(tmp);

}

// gets the element that is in front of queue
int queue_top(Queue *q) {

    // check if is empty
    if(isEmpty(q)) {
        std::cout << "empty!\n";    
        return 0;
    }
    return q->data;

}


// ----------------------------------------------


// Implementing a binary search tree
typedef struct BstNode {
    int data;
    BstNode *left;
    BstNode *right;

    // constructor class
    BstNode(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
} BstNode;

// implementing methods of binary search tree
// inserting an element at a given root
void insert(BstNode *&root, int data) {

    // First, check if root is empty
    if(root == NULL) {
        root = new BstNode(data);
        return;
    }

    // if isn't empty, check all the elements
    if(data <= root->data) //subtree at left
        if(root->left == NULL)
            root->left = new BstNode(data);
        else
            insert(root->left,data);
    else // subtree at right
        if(root->right == NULL)
            root->right = new BstNode(data);
        else
            insert(root->right, data);

}

// finding min and max element from a bst
BstNode *findMin(BstNode *root) {

    // check if the tree is empty
    if(root == NULL) {    
        return 0;
    }

    // the lesser element is in the left vertice from a tree
    while(root->left != NULL)
        root = root->left;
    
    return root;

}

BstNode *findMax(BstNode *root) {

    // check if the tree is empty
    if(root == NULL) {    
        return 0;
    }

    // the lesser element is in the left vertice from a tree
    while(root->right != NULL)
        root = root->right;
    
    return root;

}

// Finding a height of a bst
/*
    Height of a tree = Number of edges in longest path from
    root to a leaf node

    Depth of a tree = Number of edges in path from root to a
    determinate node
*/
int findHeight(BstNode *root) {

    if(root == NULL) {
        return -1;
    }

    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);

    return std::max(leftHeight,rightHeight)+1;

}

// Binary tree traversal
/*
    DFS: depth order traversal

    BFS: Level order traversal
*/

// Implementing leve-order traversal (BFS) with queue
void levelOrder(BstNode *root) {

    // check if is empty
    if(root == NULL) {
        std::cout << "NULL" << std::endl;
        return;
    }

    // implementing with STL queue
    std::queue<BstNode*> q;
    q.push(root);

    while(!q.empty()) {
        BstNode *current = q.front();
        std::cout << current->data << " ";

        if(current->left != NULL)
            q.push(current->left);
        if(current->right != NULL)
            q.push(current->right);

        q.pop();

    }

    std::cout << std::endl;

}

// implementing deapth order traversal with recursion
// preorder
void preorder(BstNode *root) {

    // base condition
    if(root == NULL)
        return;
    
    std::cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);

}

// inorder
void inorder(BstNode *root) {

    // base condition
    if(root == NULL)
        return;
    
    preorder(root->left);
    std::cout << root->data << " ";
    preorder(root->right);

}

//postorder
void postorder(BstNode *root) {

    // base condition
    if(root == NULL)
        return;
    
    preorder(root->left);
    preorder(root->right);
    std::cout << root->data << " ";

}

// deleting a node in a BST
// We've to pay attention in three scenarios of deletion
BstNode *remove(BstNode *root, int x){

    // first, check if the tree is empty
    if(root == NULL)
        return root;
    
    // Now, we've to search the number to deletion
    if(x < root->data)
        root->left = remove(root->left, x);
    else if (x > root->data)
        root->right = remove(root->right, x);
    else { // case when we found the value to be deleted

        // case 1: no Child
        if(root->left == NULL && root->right == NULL) {
            delete root;
            root = NULL;
        } else if(root->left == NULL && root->right != NULL) { // case 2: one child
            BstNode *tmp = root;
            root = root->right;
            delete tmp;
        } else if (root->left != NULL && root->right == NULL) { // case 2: one child
            BstNode *tmp = root;
            root = root->left;
            delete tmp;
        } else { // case 3: two children
            // search for min element from right side
            BstNode *tmp = findMin(root->right);
            root->data = tmp->data;
            root->right = remove(root->right,tmp->data);
        }
         
    }

    return root;

}


int main() {
    // creating a new empty tree
    BstNode *root = NULL;

    // inserting elements statically
    insert(root, 15);        
    insert(root, 10);       
    insert(root, 20);      
    insert(root, 25);
    insert(root, 8);
    insert(root, 12);

    // printing min and max value from root
    findMin(root);
    findMax(root);
    std::cout << findHeight(root) << std::endl;

    std::cout << "printinf in level order(BFS): \n";
    levelOrder(root);

    std::cout << "printing in preorder(DFS): \n";
    preorder(root);
    std::cout << std::endl;

    std::cout << "printing in inorder(DFS): \n";
    inorder(root);
    std::cout << std::endl;

    std::cout << "printing in postrder(DFS): \n";
    postorder(root);
    std::cout << std::endl;

    // delete element function
    
    root = remove(root,10);

    std::cout << "-----------------------------------------------" << std::endl;
    std::cout << "After deletion" << std::endl;

    std::cout << "printinf in level order(BFS): \n";
    levelOrder(root);

    std::cout << "printing in preorder(DFS): \n";
    preorder(root);
    std::cout << std::endl;

    std::cout << "printing in inorder(DFS): \n";
    inorder(root);
    std::cout << std::endl;

    std::cout << "printing in postrder(DFS): \n";
    postorder(root);
    std::cout << std::endl;


}
