#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> arr) {

    for (auto i : arr) {
        if(count(arr.begin(), arr.end(), i) == 1)
            return i;
    }

    return 0;

}

int main(){

    int n,a,b,c;

    cin >> n;

    vector<int> arr;

    for(int i = 0; i < n; ++i) {
        cin >> a >> b >> c;
        arr.emplace_back(a);
        arr.emplace_back(b);
        arr.emplace_back(c);
        cout << solve(arr) << endl;
        arr.clear();
    }

}