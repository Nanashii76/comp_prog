#include <iostream>
#include <vector>
#include <list>

// Singled linked list
class Node {
    public:
        int data;
        int size = 0;
        Node *next;

    // methods
    void head(Node *head) {
        if(head != nullptr)
            std::cout << head->data << std::endl;
        else
            std::cout << "NULL" << std::endl;
    }

    void tail(Node *head) {

        if(head == nullptr) {
            std::cout << "NULL" << std::endl;
            return;
        }
        
        Node *tmp = head;
        while(tmp->next != nullptr)
            tmp = tmp->next;

        std::cout << tmp->data << std::endl;

    }

    int getSize(Node *head) {
        Node *tmp = head;
        while(tmp->next != nullptr) {
            head->size++;
            tmp = tmp->next;
        }
        return head->size;
    }


    // constructor
        Node(int data) {
            this->data = data;
            next = nullptr;
        }
};

// Creating a new node
// initialy, adding to the first position, but this function
// is called to add at the final
void addFinal(Node *&head, int n) {

    Node *newNode = new Node(n);
    Node *tmp = head;
    while(tmp->next != nullptr)
        tmp = tmp->next;

    tmp->next = newNode;

}

// Adding elements at the first position
void addFirst(Node *&head, int n) {

    if(head == nullptr) {
        addFinal(head,n);
        return;
    }

    Node *newNode = new Node(n);
    Node *tmp = head;
    head = newNode;
    head->next = tmp;

}

// Adding element at an i position 
void addAt(Node *&head, int n, int i) {

    if(head == NULL)
        return;
    
    Node *tmp = head;
    int index = 0;
    while(index < i-1) {
        tmp = tmp->next;
        index++;
    }

    Node *tmp2 = tmp->next;
    Node *newNode = new Node(n);
    tmp->next = newNode;
    newNode->next = tmp2;

}

// Function to print list
void printList(Node *head) {

    Node *tmp = head;
    while(tmp != nullptr) {
        std::cout << tmp->data << "->";
        tmp = tmp->next;
    }
    std::cout << "NULL" << std::endl;

}


int main(){

    // Statically lists
    Node n1(1);
    Node n2(2);
    n1.next = &n2;

    // Dinamically lists
    Node *n3 = new Node(3);
    Node *n4 = new Node(4);
    n3->next = n4;

    //Creating a linked list with n nodes
    Node *node = new Node(10);
    addFinal(node,12);
    addFinal(node,122);
    addFinal(node,1112);
    addFinal(node,3412);
    addFinal(node,2);

    printList(node);

    std::cout << "Atual head: ";
    node->head(node);

    std::cout << "Atual tail: ";
    node->tail(node);

    addFirst(node,20);
    addAt(node,1,2);

    printList(node);
    std::cout << node->getSize(node) << std::endl;

}












