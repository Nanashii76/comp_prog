#include <bits/stdc++.h>
using namespace std;

vector<int> plusOne(vector<int> &digits) {

    vector<int> ans;
    reverse(digits.begin(),digits.end());

    int sum = (digits[0] + 1);
    int carry = sum/10;

    ans.emplace_back(sum%10);

    for(int i = 1; i < (int)digits.size(); ++i) {
         sum = ((digits[i])+carry);
         carry = sum/10;
         ans.emplace_back(sum%10);
    }

    if(carry) ans.emplace_back(carry);

    reverse(ans.begin(),ans.end());
    return ans;

}

int main(){

    vector<int> test = {9};
    vector<int> res = plusOne(test);

    for(auto x : res)
        cout << x << " ";
    cout << endl;
    
    return 0;
}