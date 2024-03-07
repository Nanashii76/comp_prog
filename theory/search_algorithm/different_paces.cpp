#include <iostream>
#include <vector>

/*
    check if a list is a circular-linked list or not
*/

typedef struct Node {

    int value;
    int size;
    Node *next;

    Node(int n) {
        value = n;
        size = 0;
        next = NULL;
    }

}Node;

// Creating a linked list passing a referenced vector
Node *createLinkedList(std::vector<int> &nums)  {

    Node *newlist = new Node(nums[0]);
    newlist->size++;
    Node *tmp = newlist;

    for(int i = 1; i < (int)nums.size(); ++i) {
        tmp->next = new Node(nums[i]);
        tmp = tmp->next;
        newlist->size++;
    }

    tmp->next=newlist;

    return newlist;

}

// printing linked lis
void printList(Node *head) {

    if(head == NULL)
        return;

    Node *tmp = head;
    int i = 0;
    while(i < head->size) {
        std::cout << tmp->value << "->";
        tmp = tmp->next;
        i++;
    }
    
    std::cout << std::endl;

}

bool isCircular(Node *head) {
    
    if (head == NULL)
        return false;
    
    Node *slowpointer = head;
    Node *fastpointer = head->next;

    while(fastpointer != NULL) {
        if(fastpointer == slowpointer)
            return true;
        slowpointer = slowpointer->next;
        fastpointer = fastpointer->next;
        if(fastpointer != NULL)
            fastpointer = fastpointer->next;
    }

    return false;

}


int main(){

    std::vector<int> nums = {1,2,3,4};
    Node *ls = createLinkedList(nums);

    if(isCircular(ls))
        std::cout << "Is a circular linked list" << std::endl;
    else
        std::cout << "Isn't circular" << std::endl;

    return EXIT_SUCCESS;

}

