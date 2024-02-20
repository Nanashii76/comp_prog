#include <bits/stdc++.h>

typedef long long ll;

int main(void) {

    ll n, aux;
    std::set<ll> s;
    std::cin >> n;

    for(ll i = 0; i < n; ++i) {
        std::cin >> aux;
        s.insert(aux);
    }

    std::cout << s.size() << std::endl;


}