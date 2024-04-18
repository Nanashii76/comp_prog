#include <bits/stdc++.h>
using namespace std;


class node {

public:
    int data;
    node *left;
    node *right;

    node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }

};

node *build_preorder() {

    int data; cin >> data;
    
    if(data == -1)
        return NULL;
    
    node *n = new node(data);
    n->left = build_preorder();
    n->right = build_preorder();

    return n;

}

void print_preorder(node *root) {

    if(root==NULL)
        return;
    
    cout << root->data << " ";
    print_preorder(root->left);
    print_preorder(root->right);

}

void print_BFS(node *root) {

    if(root==NULL)
        return;

    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {

        if(q.front() == NULL) {
            cout << endl;
            q.pop();
            if(!q.empty())
                q.push(NULL);
        } else {
            node *tmp = q.front();
            cout << tmp->data << " ";
            q.pop();
            if(tmp->left)
                q.push(tmp->left);
            if(tmp->right)
                q.push(tmp->right);
        }
    }
}

int replaceWithSum(node *root) {

    // base case
    if(root==NULL)
        return 0;
    if(root->left == NULL and root->right == NULL)
        return root->data;

    // recursive call
    int leftSum = replaceWithSum(root->left);
    int rightSum = replaceWithSum(root->right);

    int tmp = root->data;
    root->data = leftSum + rightSum;
    return root->data+tmp;

}

// Implementing a function to check if a binary tree is balanced
pair<int,bool> isBalanced(node *root) {

    pair<int,bool> p, left, right;
    if(root==NULL) {
        p.first = 0, p.second = true;
        return p;
    }
        
    // rec calls
    left = isBalanced(root->left);
    right = isBalanced(root->right);

    int height = max(left.first,right.first) + 1;

    if(abs(left.first - right.first) <= 1 and left.second == true and right.second == true)
        return make_pair(height,true);

    return make_pair(height, false);
}

// creating a function to get the max subset sum of any binary tree
// first, creating a class to store to points
class Pair {
public:
    int inc;
    int exc;
};
Pair maxSubsetSum(node *root) {

    Pair p;
    if(root==NULL) {
        p.inc = p.exc = 0;
        return p;
    }

    Pair left, right;
    left = maxSubsetSum(root->left);
    right = maxSubsetSum(root->right);

    p.inc = root->data + left.exc + right.exc;
    p.exc = max(left.inc,left.exc) + max(right.inc, right.exc);

    return p;

}


int main(){

    node *root = build_preorder();
    //replaceWithSum(root);
    pair<int,bool> balanced = isBalanced(root);

    print_BFS(root);
    cout << "Height curr tree: " << balanced.first << endl;
    cout << "Is balanced: " << balanced.second << endl;

    Pair p = maxSubsetSum(root);
    cout << "Max Subset sum: " << max(p.inc,p.exc) << endl;

    return EXIT_SUCCESS;
}