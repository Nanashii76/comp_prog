#include <bits/stdc++.h>
using namespace std;

bool containsDuplicate(vector<int> &nums) {
    set<int> s;
    for(int i = 0; i < (int)nums.size(); ++i) {
        if(s.count(nums[i])) {
            return true;
        } else {
            s.insert(nums[i]);
        }
    }

    return false;

}
