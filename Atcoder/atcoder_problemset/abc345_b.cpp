#include <bits/stdc++.h>

typedef long long ll;

int main(void) {

    // Can't use function ceil, because has decimal errors

    ll n; std::cin >> n;
    if((n+9) < 0 && ((n+9) % 10 != 0)) 
        std::cout << (n+9) / 10-1 << std::endl;
    else {
        std::cout << (n+9) / 10 << std::endl;
    } 

}