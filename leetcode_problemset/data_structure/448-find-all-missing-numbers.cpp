#include <bits/stdc++.h>
using namespace std;

vector<int> findDisappearedNumbers(vector<int> & nums) {
    int n = nums.size();
    vector<int> ans;
    vector<int> vis(n, 0);

    for(int i = 0; i < n; ++i)
        if(not vis[nums[i]-1])
            vis[nums[i]-1] = 1;
    
    for(int i = 0; i < n; ++i)
        if(not vis[i])
            ans.emplace_back(i+1);

    return ans;

}