#include <bits/stdc++.h>
#define ll long long

int main(void){

    ll n, ans = 0;
    std::cin >> n;

    ll a[n];
    // Don't need use a sort algorithm because of map
    std::map<ll, ll> m;
    for(int i = 0; i < n; ++i) {
        std::cin >> a[i];
        m[a[i]]++;
    }

    for(int i = 0; i < n; ++i)
        ans+=n-i-1-(--m[a[i]]);

    std::cout << ans << std::endl;
    

}