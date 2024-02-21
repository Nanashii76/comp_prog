#include <bits/stdc++.h>
using namespace std;

// Pairs
void explainPair(){

    pair<int,int> p = {1,3};

    cout << p.first << " " << p.second << endl;

    pair<int, pair<int, int>> p2 = {1, {3,4}};

    cout << p2.first << " " << p2.second.first << " " << p2.second.second << endl;

    pair<int, int> arr[] = {{1,2}, {2,5}, {5,1}};

    cout << arr[1].first << endl;

}

// Vectors
void explainVector(){

    vector<int> v;

    v.push_back(1);
    v.emplace_back(2);

    vector<pair<int,int>> vec;

    // Different in sintax, and emplace creates dinamically
    vec.push_back({1,2});
    vec.emplace_back(1,2);

    // Creates a container with 5 spaces, and all've 100 value
    vector<int> v2(5,100);

    // Creates a container with 5 spaces, all're 0
    vector<int> v3(5);
    
    // Copy v2 to v4
    vector<int> v4(v2);


    // interator is a pointer
    vector<int>::iterator it = v2.begin();
    cout << *(it) << " ";

    for(vector<int>::iterator it = v2.begin(); it != v2.end(); ++it)
        cout << *(it) << endl;
    
    for(auto it = v4.begin(); it != v4.end(); ++it)
        cout << *(it) << endl;

    // For each loop
    for(auto x : v4)
        cout << x << endl;

    // Delete a determinate element
    v.erase(v.begin()+1);

    // Deleting a range of elements
    v.erase(v.begin() + 1, v.begin() + 4);


    // Insert Function
    vector<int> vp(5,100); // {100, 100, 100, 100, 100}
    vp.insert(v.begin(), 300); // {300, 100, 100, 100, 100, 100}
    vp.insert(v.begin()+1, 2, 10); // {300, 10, 10, 100, 100...}

    // Getting the size of vector
    vp.size();

    // Deleting the last element
    vp.pop_back();

    // Change the values of two vectors
    vp.swap(v);

}

// Lists
void explainList(){

    list<int> ls;

    ls.push_back(2);
    ls.emplace_back(4);

    ls.push_front(5);
    ls.emplace_front();

    // Same functions as vector
    // We can put elements in front of list

}


// Deque
void explainDeque(){

    deque<int> dq;
    dq.push_back(1);
    dq.emplace_back(2);
    dq.push_front(4);
    dq.emplace_front(3);

    dq.pop_back();
    dq.pop_front();

    cout << dq.back() << endl;
    dq.back();
    cout << dq.front() << endl;
    dq.front();


    // Same funcitons as vector
    // This strcutre allows us to put elements in front of it
    // and remove elements in front, like a double linked list

}

// Priority Queue
void explainPQ(){

    // The maximum value is in the top of heap
    priority_queue<int> pq;

    pq.push(5); // {5}
    pq.push(2); // {5,2}
    pq.push(3); // {5,3,2}
    pq.push(10); // {10,5,3,2}

    cout << pq.top() << endl; // prints{10};
    pq.pop(); // {5,3,2} -> Remove the element in first index

    // Minimum heap
    priority_queue<int, vector<int>, greater<int>> ppq;
    
    ppq.push(5); // {5}
    ppq.push(2); // {2,5}
    ppq.push(3); // {2,3,5}
    ppq.push(10); // {2,3,5,10}

}
