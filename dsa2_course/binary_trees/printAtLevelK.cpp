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


// build a tree at pre-order level
node *buildTree_preorder(){

    int d; cin >> d;

    if(d == -1)
        return NULL;

    node *n = new node(d);
    n->left = buildTree_preorder();
    n->right = buildTree_preorder();

    return n;

}

// getting height of the tree
int height_tree(node *root) {

    if(root == NULL)
        return 0;
    
    int left = height_tree(root->left);
    int right = height_tree(root->right);

    return 1+max(left,right);
}

// printing at level K
void printAtK(node *root, int k) {

    if(root==NULL)
        return;

    int count = 0;
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {

        if(count == k) {
            while(q.front() != NULL) {
                cout << q.front()->data << " ";
                q.pop();
            }
            cout << endl;
            return;
        }

        if(q.front() == NULL) {
            count++;
            q.pop();
            if(!q.empty())
                q.push(NULL);
        } else {
            node *tmp = q.front();
            q.pop();
            if(tmp->left)
                q.push(tmp->left);
            if(tmp->right)
                q.push(tmp->right);
        }
    }

    cout << "K > height" << endl;
    cout << "Actual height: " << height_tree(root) << endl;
    cout << "Actual K: " << k+1 << endl;

}


int main(){

    node *root = buildTree_preorder();
    printAtK(root, 4);

    return EXIT_SUCCESS;
}