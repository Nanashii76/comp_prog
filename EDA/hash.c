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
void sorted_insert(struct node *node, int x) {

    struct node *new, *temp = node, *q = NULL;
    new = (struct node*)malloc(sizeof(struct node));
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

int hash(int key) {
    return key%10;
}

// Insert in a Hash Table
void insert(node *H[], int key) {
    int index=hash(key);
    sorted_insert(&(H[index]),key);
}


int main(void) {

    struct node *HT[10];
    
    for(int i = 0; i<10; ++i)
        HT[i] = NULL;

    insert(HT,12);
    insert(HT,22);
    insert(HT,42);



}









