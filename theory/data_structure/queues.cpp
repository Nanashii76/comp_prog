#include <iostream>
#include <vector>
#include <deque>
#include <queue>

/*
   # Queues, Deques and Priority Queues

-> Queues, data structure based in fifo "first in, first out", 
   we've a STL implementation in C++.
*/


int main(){

    // Deques (like a double-linked-list)
    std::deque<int> deq;
    deq.push_back(1); // {1}
    deq.push_front(2); // {2,1}
    deq.push_back(3); // {2,1,3}

    std::cout << deq.front() << "\n"; // {2}
    deq.back(); // get's the element in last position
    deq.front(); // get's the element in firts position

    // Priority queues
    std::priority_queue<int> pq;
    pq.push(1); // O(log n)
    pq.push(2);
    pq.push(3);
    // pq = {1,2,3}
    pq.top(); // {3}


}