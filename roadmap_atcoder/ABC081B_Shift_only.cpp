#include <bits/stdc++.h>

typedef long long ll;

bool check_even(std::vector<ll> v) {

    for(int i = 0; i < static_cast<int>(v.size()); ++i) {
        if(v[i]%2 != 0)
            return false;
    }

    return true;

}


int main(void) {

    int n, sum = 0, aux = 0;
    std::vector<ll> v;
    std::cin >> n; 
    v.resize(n);

    for(int i = 0; i < n; ++i)
        std::cin >> v[i];

    int i = 0;

    while(check_even(v)) {
        aux = 1;
        v[i] /= 2;
        i++;
        if(i == static_cast<int>(v.size())) {
            sum++;
            i = 0;
        }
    }

    if(aux != 0)
        std::cout << sum+1 << std::endl;
    else
        std::cout << sum << std::endl;


}