#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){

    ll n; cin >> n;
    vector<ll> A(n), C(n);
    unordered_map<ll,ll> mp;
    for(ll i = 0; i < n; ++i) {
        cin >> A[i] >> C[i];
        if(mp.count(C[i]))
            mp[C[i]] = min(mp[C[i]],A[i]);
        else
            mp[C[i]] = A[i];
    }

    ll ans = 0;
    for(ll i = 0; i < n; ++i) {
        ans = max(ans,mp[C[i]]);
    }

    cout << ans << endl;

}