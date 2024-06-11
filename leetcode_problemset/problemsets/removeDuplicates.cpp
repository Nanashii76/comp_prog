#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &nums) {
    set<int> s;
    int size = nums.size();
    for(int i = 0; i < size; ++i)
        s.insert(nums[i]);

    int i = 0;
    for(auto x : s)
        nums[i++] = x;
    
    return s.size();
}