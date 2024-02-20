#include <bits/stdc++.h>

typedef long long int lli;

int main() {

    lli n, k, sum = 0, aux;
    std::cin >> n;

    std::vector<lli> v(n);
    for(lli i = 0; i < n; ++i) {
        std::cin >> aux;
        v.emplace_back(aux);
    }
        
    std::cin >> k;

    for(lli i = 0; i < k; ++i) {
        sum += v[i%n];
        if(sum > k) {
            std::cout << aux+1 << std::endl;
            return 0;
        }
    } 


}