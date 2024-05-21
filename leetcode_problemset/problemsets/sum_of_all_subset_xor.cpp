#include <bits/stdc++.h>
using namespace std;

int getAllSubsets(vector<int> &arr, vector<int> &ans, int i, int n) {

    if(i >= n) {
        int xor_cal = 0;
        for(int k = 0; k < (int)ans.size(); ++k) {
            xor_cal ^= ans[k];
        }
        return xor_cal;
    }

    // not pick
    int not_pick = getAllSubsets(arr,ans,i+1,n);

    // pick
    ans.emplace_back(arr[i]);
    int pick = getAllSubsets(arr,ans,i+1,n);
    ans.pop_back();

    return not_pick + pick;
}

int subsetXORSum(vector<int> &nums){

    vector<int> ans;
    return getAllSubsets(nums,ans,0,nums.size());

}