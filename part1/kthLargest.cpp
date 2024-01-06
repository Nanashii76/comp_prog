#include <bits/stdc++.h>
using namespace std;


// Solution with sorting vector
int kthLargest(vector<int> nums, int k) {

    sort(nums.begin(),nums.end());
    int n = nums.size();

    return nums[n-k];

    // To get the smallest kth element, just return nums[k-1]

}


// Solution with heap
void kthLargestHeap(vector<int> nums, int k) {

    priority_queue<int> pq;

    for(int i = 0; i < nums.size(); ++i)
        pq.push(nums[i]);

    int f = k-1;

    while (f > 0) {
        pq.pop();
        f--;
    }

    cout << pq.top() << endl;

    // The same logic to get the smallets kth element, just do a minHeap

}


int main(void) {

    vector<int> nums;
    nums.reserve(10);
    
    nums.emplace_back(3);
    nums.emplace_back(2);
    nums.emplace_back(3);
    nums.emplace_back(1);
    nums.emplace_back(2);
    nums.emplace_back(4);
    nums.emplace_back(5);
    nums.emplace_back(5);
    nums.emplace_back(6);

    cout << kthLargest(nums, 4) << endl;
    kthLargestHeap(nums, 4);

}