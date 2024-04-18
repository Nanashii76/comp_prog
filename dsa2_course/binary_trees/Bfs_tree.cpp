#include <bits/stdc++.h>
using namespace std;

// Creating class node to store each node of a binary tree
class node {

public:
    int data;
    node *left;
    node *right;

    // constructor method
    node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }

};

// creating a function to create a binary tree in pre-order
node *build_tree(){

    int d; 
    cin >> d;

    // base case
    if(d == -1)
        return NULL;

    // calling recursively
    node *n = new node(d);
    n->left = build_tree();
    n->right = build_tree();

    return n;
}

// creating a function to build a tree at level order
node *build_treeBFS() {

    int data; 
    cin >> data;

    if(data == -1)
        return NULL;

    node *root = new node(data);
    queue<node*> q;
    q.push(root);

    while(!q.empty()) {
        node *tmp = q.front();
        q.pop();
        
        int leftData, rightData;
        cin >> leftData >> rightData;
        
        if(leftData != -1) {
            tmp->left = new node(leftData);
            q.push(tmp->left);
        }
        if(rightData != -1) {
            tmp->right = new node(rightData);
            q.push(tmp->right);
        }
    }

    return root;

}

// creating a function to output elements at level order (BFS)
void bfs_tree(node *root){

    if(root == NULL) {
        cout << "It's empty!" << endl;
        return;
    }

    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {

        node *tmp = q.front();
        q.pop();

        // Verificar se é um marcador de nível
        if(tmp == NULL) {
            cout << endl;
            // Verificar se a fila ainda tem elementos antes de adicionar outro marcador de nível
            if(!q.empty())
                q.push(NULL);
        } else {
            cout << tmp->data << " ";
            if(tmp->left)
                q.push(tmp->left);
            if(tmp->right)
                q.push(tmp->right);
        }
    }
}

// To find the diamater, we need to calculate the height of a tree
int height(node *root){

    // base condition
    if(root==NULL)
        return 0;

    // recursions calls
    int h1 = height(root->left);
    int h2 = height(root->right);
    return 1 + max(h1,h2);

}

// Diameter of a tree
int diameter(node *root) {

    //base condition
    if(root==NULL)
        return 0;
    
    int d1 = height(root->left) + height(root->right);
    int d2 = height(root->left);
    int d3 = height(root->right);

    return max(d1,max(d2,d3));

}

// Diamater optmised
class HDPair {
public:
    int height;
    int diameter;
};

HDPair diameter_opt(node *root) {

    HDPair p;

    // rec call
    if(root==NULL) {
        p.diameter = p.height = 0;
        return p;
    }

    // otherwise
    HDPair left = diameter_opt(root->left);
    HDPair right = diameter_opt(root->right);

    p.height = max(left.height,right.height) + 1;

    int d1 = left.height + right.height;
    int d2 = left.height;
    int d3 = right.height;

    p.diameter = max(d1,max(d2,d3));

    return p;

}

int main(){

    // input : 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
    //node *root = build_tree();

    // input : 1 2 3 4 5 -1 6 -1 -1 7 -1 -1 -1 -1 -1
    node *root = build_treeBFS();
    bfs_tree(root);

    HDPair p = diameter_opt(root);

    cout << "Height of actual tree: " << p.height << endl;
    cout << "Diamater of actual tree: " << p.diameter << endl;
    

    return EXIT_SUCCESS;
}

