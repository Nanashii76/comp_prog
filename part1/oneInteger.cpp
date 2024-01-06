#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> nums) {

    int sum = 0, aux, n = nums.size();

    for(int i = 0; i < n; i+=2) {
        aux = nums[i] + nums[i+1];
        sum += aux;
        nums[i] = 0;
        nums[i+1] = 0;
        nums.emplace_back(aux);
        cout << sum << endl;
    }

    return sum;

}

int main(void) {

    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(5);

    cout << solve(arr) << endl;

}