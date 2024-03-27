#include <bits/stdc++.h>

typedef long long ll;

void solve(std::vector<ll> vec){

    for(ll i= 1;  i< (ll)vec.size(); ++i)
        if(!vec[i]) {
            std::cout << i << std::endl;
            return;
        }
}

int main(void) {

    ll n; std::cin >> n;
    std::vector<ll> vec(n);
    for(ll i = 0; i < n-1; ++i) {
        ll aux; std::cin>> aux;
        vec.push_back(aux);
    }

    std::sort(vec.begin(),vec.end());
    std::vector<ll> vec2((n+1),0);
    for(ll i = 0; i < (ll)vec.size(); ++i)
        vec2[vec[i]] = vec[i];

    solve(vec2);
}