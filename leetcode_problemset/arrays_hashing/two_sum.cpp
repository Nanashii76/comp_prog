#include <bits/stdc++.h>
using namespace std;

// Brute force approach
vector<int> twoSum(vector<int> &nums, int target) {

    int sum = 0;
    vector<int> res;
    for(int i = 0; i < (int)nums.size(); ++i) {
        for(int j = i+1; j < (int)nums.size(); ++j) {
            sum = nums[i] + nums[j];
            if(sum == target) {
                res.push_back(i);
                res.push_back(j);
                return res;
            }
        }
    }

}


// one pass approach
vector<int> twoSum_hash(vector<int> &nums, int target) {

    int remind = 0;
    vector<int> res;
    unordered_map<int,int> map;
    for(int i = 0; i < (int)nums.size(); ++i) {
        remind = target - nums[i];
        if(map.count(remind)) {
            res.push_back(i);
            res.push_back(map[remind]);
            return res;
        }  else {
            map[nums[i]] = i;
        }
    }

    return res;

}
