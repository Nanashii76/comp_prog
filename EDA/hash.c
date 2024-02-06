#include <stdlib.h>
#include <stdio.h>

/*
    To program a hash Table with chaining, we've to create
    the basic linked list functions

    but the insertion has to bem sorted

*/

typedef struct node {
    int data;
    struct node *next;
} node;


// Sorted insertion and creation of linked list 
void sorted_insert(node *node, int x) {

    struct node *temp = node, *q = NULL, *new;
    new = malloc(sizeof(node));
    new->data = x;
    new->next = NULL;

    if(node == NULL)
        node = new;
    else {
        while(temp && temp->data < x){
            q=temp;
            temp=temp->next;
        }
        if(temp == node){
            new->next = node;
            node = new;
        }
        else{
            new->next=q->next;
            q->next=new;
        }
    }
    
}

// Searching in linked list
node *search(node *node, int key) {

    while (node != NULL) {
        if(key == node->data)
            return node;
        node=node->next;
    }

    return NULL;

}











