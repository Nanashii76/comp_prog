#include <iostream>

// Implementing a linked list using struct
typedef struct Node{

    int data;
    Node *next;

    // Creating a constructor
    Node(int x) {
        data = x;
        next = NULL;
    }

} Node;

// Creating a head pointer to list
Node *newNode(int x) {
    return new Node(x);
}

// Insert at end of list
void insert_end(Node **head, int x) {

    if(*head == NULL) {
        *head = newNode(x);
        return;
    }

    Node *tmp = *head;
    while(tmp->next != NULL)
        tmp = tmp->next;
    
    tmp->next = newNode(x);

}

// Insert at beginning of list
// passing by reference
void insert_begin(Node **head, int x) {
    Node *new_node = newNode(x);

    if(*head == NULL) {
        return;
    }

    new_node->next = *head;
    *head = new_node;
}

// Insert at nth position
void insert_ith(Node **head, int position, int x) {

    if(*head == NULL) {
        return;
    }

    int cout = 1;
    Node *tmp = *head;

    if(position == 1) {
        insert_begin(head,x);
        return;
    }


    while(cout < position-1 && tmp->next != NULL) {
        cout++;
        tmp = tmp->next;
    }

    Node *new_node = newNode(x);
    new_node->next = tmp->next;
    tmp->next = new_node;
    
}

// Deleting a node at a particular nth position
void delete_node(Node **head, int position) {

    if(head == NULL)
        return;
    
    Node *temp1 = *head;

    if(position == 1) {
        *head = temp1->next;
        return;
    }

    int cout = 1;
    while(cout < position-1 && temp1->next != NULL) {
        cout++;
        temp1 = temp1->next;
    }

    Node *temp2 = temp1->next;
    temp1->next = temp2->next; 

}

// Printing Elements
void print_list(Node *head) {

    if(head == NULL) {
        std::cout << "NULL" << std::endl;
        return;
    }

    Node *tmp = head;
    while(tmp != NULL) {
        std::cout << tmp->data << "-->";
        tmp=tmp->next;
    }

    std::cout<<"NULL"<<std::endl;

}

// Reversing a linked list

// 1. Method (Interative)
void reverse(Node **head) {

    if(*head == NULL)
        return;

    // Declare three variables, to get the previous and the current
    // element at list
    Node *current, *prev, *next;
    current = *head;
    prev = NULL;

    while(current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;

}




// Working with recursion
// printing elements from a list using recursion
void print_list_recusrive(Node *head) {

    if(head == NULL) {
        std::cout << "NULL" << std::endl;
        return;
    }

    std::cout << head->data << "-->";
    print_list_recusrive(head->next);

}

// printing reverse elements from a list using recursion
void print_reverseList_recursive(Node *head) {

    if(head == NULL) {
        std::cout << "NULL ";
        return;
    }

    print_reverseList_recursive(head->next);
    std::cout << head->data << " ";

}

// Reversing a linked list using recursion
void reverse_recursive(Node **head, Node *p) {

    // base condition
    if(p->next == NULL) {
        *head = p;
        return;
    }
    reverse_recursive(head,p->next);
    Node *current = p->next; // we actually're in the past node
    current->next = p;
    p->next = NULL;

}


int main(){
    
    int elements;

    Node *h1 = NULL;

    std::cout << "How many elements to add: \n";
    std::cin >> elements;
    for(int i = 0; i < elements; ++i) {
        int aux;
        std::cout<<"Add element " << i << " : \n";
        std::cin >> aux;
        insert_end(&h1,aux);
    }

    print_list_recusrive(h1);
    std::cout << "Printing in reverse order list: " << std::endl;
    print_reverseList_recursive(h1);

    std::cout << "\nPrinting after reverse recursive: " << std::endl;
    reverse_recursive(&h1,h1);
    print_list_recusrive(h1);

    /*
    insert_begin(&h1,12); // returns a new node, because store in a variable
    insert_ith(&h1,1,20);

    print_list(h1);

    std::cout << "After Delete an element: " << std::endl;

    delete_node(&h1,2);
    print_list(h1);

    reverse(&h1);

    std::cout << "After reverse list: " << std::endl;
    print_list(h1);
    */
}









