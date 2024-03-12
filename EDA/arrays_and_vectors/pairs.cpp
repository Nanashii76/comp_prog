/*
    Given an array containing N integers, and an number S denoting
    a target sum.

    Find two distinct integers that can pair up to form target sum. 
    Let us assume there will be only one such pair

    input
    arra=[10,5,2,3,-6,9,11]
    S = 4

    output
    [10,-6]
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

// solution with approach using sort vector
void solve(std::vector<int> &v, int sum) {

    std::sort(v.begin(),v.end());
    int l = 0, r = v.size()-1;

    while (l <= r) {
        if(v[l]+v[r] == sum) {
            std::cout << "[" << v[l] << "," << v[r] << "]" << std::endl;
            return;
        } if (v[l]+v[r] > sum)
            r--;
        else
            l++;
    }

    std::cout << "Doesn't exist" << std::endl;
    return;

}

// solution using unordered_set
void solve2(std::vector<int> &v, int sum) {

    std::unordered_set<int> us;
    
    for(int i = 0; i < (int)v.size(); ++i) {
        if(us.find(sum-v[i])!=us.end()) {
            std::cout << "[" << v[i] << "," << sum-v[i] << "]" << std::endl;
            return;
        }
        us.emplace(v[i]);
    }


    std::cout << "Doesn't exist" << std::endl;

}


int main(){

    std::vector<int> nums = {10,5,2,3,-6,9,11};
    int sum = 4;

    solve(nums,sum);
    solve2(nums,sum);

}


