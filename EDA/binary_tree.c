#include <stdio.h>
#include <stdlib.h>

// Binary tree implementation with linked list
typedef struct treenode {
    int data;
    struct treenode *left, *right;
} treenode;

// function to create a new root
treenode *createnode(int data) {

    // Alloc a new space in memory to root
    treenode *new = malloc(sizeof(treenode));
    new->left = NULL;
    new->right = NULL;
    new->data = data;

    return new;

}

// Inserting elements in a binary tree
treenode *insert_node(treenode *node, int data) {

    // Checking if the tree is empty
    if(node == NULL) return createnode(data);

    // If isn't empty, now check if de data is lesser than root
    if(data < node->data)
        node->left = insert_node(node->left, data);
    // If isn't empty. now check if de data is greater than root
    else if(data > node->data)
        node->right = insert_node(node->right, data);
 
    // Return the node with the new leaf
    return node;

}

// Printing elements in a tree pre-order
void print_tree(treenode *node) {

    if(node != NULL) {
        
        printf("%d\n", node->data);
        print_tree(node->left);
        print_tree(node->right);

    }

}

// Searching elements in a tree
treenode *search_tree(treenode *node, int value) {

    // If not found the value
    if(node == NULL) return NULL;

    // If found the value 
    if (value == node->data)
        return node;
    
    // Same logic in printing, we search for values lesser or higher
    else if(value < node->data)
        return search_tree(node->left, value);
    else if (value > node->data)
        return search_tree(node->right, value);

}

// founding the min value (aux to delete_tree)
treenode *find_min(treenode *node) {
    
    while(node->left != NULL)
        node = node->left;
    
    return node;

}

// Deleting a given node value
treenode *delete_tree(treenode *node, int value) {

    // End of recursion or empty tree
    if(node == NULL) return node;

    // Choosing the direction to found the value to be deleted
    if(value < node->data)
        node->left = delete_tree(node->left, value);
    else if(value > node->data)
        node->right = delete_tree(node->right,value);
    
    else {
        // case 1 and 2, if the node has 0 or 1 child
        if(node->left == NULL) {
            treenode *temp = node->right;
            free(node);
            return temp;
        } else if (node->right == NULL) {
            treenode *temp = node->left;
            free(node);
            return temp;
        }

        // Third case: If the node has two children, we've to found the lesser
        treenode *temp = find_min(node->right);

        //copy the content of the sucessor for te actual node
        node->data = temp->data;

        // Now, delete de sucessor
        node->right = delete_tree(node->right, temp->data);    

    }

    return node;

}

// Example using each function 

/*
int main(void) {

    treenode *n1 = createnode(10);
    insert_node(n1, 8);
    insert_node(n1, 6);
    insert_node(n1, 9);
    insert_node(n1, 12);
    insert_node(n1, 11);
    insert_node(n1, 13);

    print_tree(n1);

    if(search_tree(n1,13))
        printf("Found\n");

    delete_tree(n1,10);

    print_tree(n1);

}
*/



