#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


int solve(vector<ll> arr) {

    // count the numbers that repeat
    set<ll> s;

    for(int i = 1; i <= arr.size()-1; ++i)
        s.insert(arr[i]);

    int ans = s.size();
    return ans;

}

int main(){

    int n, t;
    cin >> n >> t;
    vector<ll> v(n+1,0);

    for(int i = 1; i <= t; ++i) {
        ll a,b;
        cin >> a >> b;
        v[a]+=b;
        cout << solve(v) << endl;
    }

}