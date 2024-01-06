#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <stack>
#include <queue>

using namespace std;

int main(){

    // VECTOR

    vector<int> arr = {5,4,3,2,1}; 
    arr.push_back(0); // if the capacity is full, will double itself

    //Reserve
    arr.reserve(10); // initializing with 10 elements

    vector<int> arr2(10,0); // initializing with 10 elements, all're 0's

    //Erase
    //arr.erase(arr.begin() + 3); // Erasing the 4th element

    //arr.erase(arr.begin(), arr.begin() + 3); // Erasing elements in a range





    // DEQUE -> now we have push_front(), pop_front()
    deque<int> deq(10);

    /*
    for(int i = 0; i <10; ++i)
        cin >> deq[i];
    */

    // like a doubled linked list
    deq.push_front(100);
    deq.push_back(200);




    // STACK
    stack<string> books;

    books.push("c++");
    books.push("Java");
    books.push("JavaScript");
    books.push("Python");

    while (!books.empty()) {
        cout << books.top() << "\n";
        books.pop();
    }
          


    // QUEUE
    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    while (!q.empty()) {
        cout << q.front() << endl;
        q.pop();
    }


    // PRIORITY QUEUE

    int arr3[] = {10,15,20,13,6,90};
    int n = sizeof(arr3)/sizeof(int);

    priority_queue<int> heap; // this is a maxHeap
    //priority_queue<int, vector<int>, greater<int>> heap; //this is a minHeap

    for (auto x : arr3) {
        heap.push(x);
    }

    while(!heap.empty()) {
        cout << heap.top() << "\n";
        heap.pop();
    }

}