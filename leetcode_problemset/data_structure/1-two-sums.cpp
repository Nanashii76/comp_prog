#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int,int> vals;
    vector<int> ans;

    for(int i = 0; i < (int)nums.size(); ++i) {
        int complement = target - nums[i];

        if(vals.find(complement) != vals.end()) {
            ans.emplace_back(vals[complement]);
            ans.emplace_back(i);
        }

        vals[nums[i]] = i;

    }

    return ans;

}