#include <bits/stdc++.h>
using namespace std;

vector<int> findMinSum(vector<int> vals, int n) {

    vector<int> res(n,0);

    for(int i = 0; i < n; ++i) {
        
        int ans = vals[i];
        int minEnding = vals[i];
        for(int j = i+1; j < n; ++j) {
            minEnding = min(minEnding + vals[j], vals[j]);
            ans = min(ans, minEnding);
        }

        res[i] = ans;

    }

    return res;

}

int main(){

    int t; cin >>t;
    while(t--) {
        int n; cin >> n;
        vector<int> vals(n,0);
        for(int i = 0; i < n; ++i)
            cin >> vals[i];
        vector<int> minSums = findMinSum(vals, n);
        for(auto x : minSums)
            cout << x << " ";
        cout << endl;
    }

}