#include <bits/stdc++.h>
using namespace std;

// version with o(n^2)
vector<int> product(vector<int> &nums) {

    vector<int> res;
    for(int i = 0; i < (int)nums.size(); ++i) {
        int prod = 1;
        for(int j = 0; j < (int)nums.size(); ++j) {
            if(i == j)
                continue;
            prod *= nums[j];
        }
        res.push_back(prod);
    }

    return res;

}

// getting postfix and prefix product

vector<int> produtc2(vector<int> &nums) {

    vector<int> res;
    vector<int> prefix;
    vector<int> postfix;

    // aux produt
    int prod = 1;

    // getting prefix
    for(int i = 0; i < (int)nums.size(); ++i) {
        prefix.push_back(prod*nums[i]);
        prod *= nums[i];
    }

    // reseting prod
    prod = 1;

    // geting postfix
    for(int i = (int)nums.size()-1; i >= 0; --i) {
        postfix.push_back(prod*nums[i]);
        prod *= nums[i];
    }

    reverse(postfix.rbegin(),postfix.rend());

    // cout << "prefix: ";
    // for(const auto& element: prefix)
    //     cout << element << " ";
    // cout << endl;

    // cout << "postfix: ";
    // for(const auto& element: postfix)
    //     cout << element << " ";
    // cout << endl;

    for(int i = 0; i < (int)nums.size(); ++i) {

        if(i == 0)
            res.push_back(postfix[i+1]);
        else if (i == (int)nums.size()-1)
            res.push_back(prefix[i-1]);
        else {
            res.push_back(prefix[i-1]*postfix[i+1]);
        }

    }

    return res;

}

int main(){

    vector<int> nums = {-1,1,0,-3,3};
    vector<int> ans = produtc2(nums);

    for(const auto& element : ans)
        cout << element << " ";
    cout << endl;

    return 0;

}