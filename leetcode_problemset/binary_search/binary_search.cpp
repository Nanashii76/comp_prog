#include <bits/stdc++.h>
using namespace std;

int search(vector<int> &nums, int target){

    int l = 0, r = (int)nums.size()-1;

    while(l <= r) {
        int mid = (l+r)/2;
        if(target < nums[mid])
            r = mid-1;
        else if(target > nums[mid])
            l = mid+1;
        else
            return mid;
    }

    return -1;

}


int main() {

    vector<int> nums = {-1,0,3,5,9,12};
    int ans = search(nums,9);

    cout << ans << endl;
    return 0;

}