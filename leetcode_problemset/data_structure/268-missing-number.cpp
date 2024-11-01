#include <bits/stdc++.h>
using namespace std;

int missingNumber(vector<int> &nums) {
    sort(nums.begin(), nums.end());

    for(int i = 0; i < (int)nums.size(); ++i)
        if(i != nums[i])
            return i;
}