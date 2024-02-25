#include <iostream>

typedef long long ll;

const int mod = 1e9+7;

ll mfac(int i) {
    
    int m = i+2;
    int ans = 1;
    
    for(int i = 0; i < 3; ++i) {
        m %= mod;
        ans *= m-i;
        ans %= mod;
    }
    
    return ans;
    
}

ll solve(int n) {
    
    int ans = 0;
    
    while(n > 0) {
        ans += mfac(n);
        n--;
    }
    
    return ans;
}


int32_t main(void) {
    
    int n;
    std::cin >> n;
    std::cout << solve(n) << std::endl;
    
    
}


