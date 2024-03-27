#include <bits/stdc++.h>

typedef long long ll;

int main(void) {

    ll n; std::cin>> n;
    while(n != 1) {
        std::cout << n << " ";
        if(n&1) 
            n=(n*3)+1; 
        else
            n/=2;
    }
    std::cout << n << std::endl;

    return EXIT_SUCCESS;
}
