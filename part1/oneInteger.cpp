#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> nums) {

    deque<int> d;
    int n = nums.size();
    for(int i = 0; i < n; ++i)
        d.emplace_back(nums[i]);
    
    int sum = 0;

    while(d.size() != 1) {
        int m = d.size();
        if(m&1) {
            int front = d.front();
            d.pop_front();
            int back = d.front();
            d.pop_front();

            sum += front+back;
            d.emplace_back(front+back);
        } else {
            int front = d.front();
            int back = d.back();
            d.pop_back();
            d.pop_front();

            sum += front+back;
            d.emplace_back(front+back);
        }
    
    }

    return sum;

}

int main(){

    vector<int> nums = {1,2,3,4,5};
    cout << solve(nums) << endl;

    return 0;
}