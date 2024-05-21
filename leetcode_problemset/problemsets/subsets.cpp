#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> getAllSubsets(vector<int> &arr, vector<int> &out, int i, int n) {
    
    vector<vector<int>> ans;

    if (i >= n) {
        ans.emplace_back(out);
        return ans;
    }

    // not pick
    vector<vector<int>> not_pick = getAllSubsets(arr, out, i + 1, n);
    ans.insert(ans.end(), not_pick.begin(), not_pick.end());

    // pick
    out.emplace_back(arr[i]);
    vector<vector<int>> pick = getAllSubsets(arr, out, i + 1, n);
    ans.insert(ans.end(), pick.begin(), pick.end());
    out.pop_back();

    return ans;
}

vector<vector<int>> subsets(vector<int>& nums) {   
    vector<int> out;
    vector<vector<int>> res = getAllSubsets(nums, out, 0, nums.size());
    return res;
}
