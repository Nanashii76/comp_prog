#include <iostream>

// Implementing a queue with linked list
typedef struct Queue {

    int data;
    Queue *next;

    // constructor class
    Queue(int x) {
        data = x;
        next = NULL;
    }

} Queue;


// check if the queue is already empty
bool isEmpty(Queue *q) {
    if(q == NULL)
        return true;
    else
        return false;
}

// printing elements from a queue
void print_queue(Queue *q) {

    if(isEmpty(q)) {
        std::cout << "NULL" << std::endl;
        return;
    }

    while(q != NULL) {
        std::cout << q->data << " ";
        q = q->next;
    }
    std::cout << std::endl;

}

// add elements to a queue
void add_queue(Queue **q, int x){

    // check if queue is empty
    if(isEmpty(*q)) {
        *q = new Queue(x);
        return;
    }

    // add elements at the final of queue
    Queue *tmp = *q;
    Queue *new_value = new Queue(x);
    while(tmp->next != NULL)
        tmp = tmp->next;
    // adding next element
    tmp->next = new_value;
}

// remove the first element from queue
void pop_queue(Queue **q) {

    // check if queue is empty
    if(isEmpty(*q))
        return;
    
    // remove first element from queue
    Queue *tmp = *q;
    *q = tmp->next;

    delete(tmp);

}

// gets the element that is in front of queue
int queue_top(Queue *q) {

    // check if is empty
    if(isEmpty(q)) {
        std::cout << "empty!\n";    
        return 0;
    }
    return q->data;

}


int main(void) {

    Queue *q = NULL;

    int n;
    std::cout << "Numbers to add at queue: \n";
    std::cin >> n;

    for(int i = 0; i < n; ++i) {
        int aux;
        std::cout << "number " << i+1 << ": \n";
        std::cin >> aux;
        add_queue(&q,aux);
    }

    print_queue(q);
    std::cout << queue_top(q) << std::endl;
    pop_queue(&q);
    print_queue(q);


}

