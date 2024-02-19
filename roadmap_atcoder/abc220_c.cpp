#include <bits/stdc++.h>

typedef long long ll;

int main() {

    ll n, k, sum = 0, aux;
    std::cin >> n;

    std::vector<ll> v;
    for(ll i = 0; i < n; ++i) {
        std::cin >> aux;
        v.emplace_back(aux);
    }
        
    std::cin >> k;

    for(ll i = 0; i < k; ++i) {
        sum += v[i%n];
        if(sum > k) {
            aux = i;
            break;
        }
    } 

    std::cout << aux+1 << std::endl;

}