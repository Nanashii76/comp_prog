#include <iostream>
#include <vector>
#include <queue>

// Creating new tree
typedef struct Node {
    char value;
    Node *left;
    Node *right;

    Node(char n) {
        value = n;
        left = right = NULL;
    }
} Node;

Node *newTree(char n) {
    Node *node = new Node(n);
    return node;
}


// BFS -> level Order Search implementation to Binary trees
std::vector<std::vector<char>> BFSimplementation(Node *root) {

    std::vector<std::vector<char>> ans;

    if(root == NULL)
        return ans;
    
    std::queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        int size = q.size();
        std::vector<char> level;
        for(int i = 0; i < size; ++i) {
            Node *node = q.front();
            q.pop();
            if(node->left != NULL)
                q.push(node->left);
            if(node->right != NULL)
                q.push(node->right);
    
            level.push_back(node->value);
        }
        ans.push_back(level);
    }

    return ans;

}





int main(void) {

    Node *tree = newTree('a');
    tree->left = newTree('b');
    tree->right = newTree('c');

    tree->left->left = newTree('d');
    tree->left->right = newTree('e');

    tree->right->left = newTree('f');

    std::vector<std::vector<char>> ans = BFSimplementation(tree);
    for(const auto& level : ans) {
        for(const auto& value : level)
            std::cout << value << " ";
        std::cout << std::endl;
    }

    return EXIT_SUCCESS;

}

