#include <iostream>

#define int long long int

// Constant isn't necessary
const int mod = 1e9 + 7;

int binaryExponentation(int a, int b) {

    if (a == 0)
        return 0;
    
    int ans = 1;
    while(b) {
        if(b&1)
            ans *= a, ans %= mod;
        a*=a;
        a %= mod;
        b = b>>1;
    }

    return ans;

}

int32_t main ( void ){

    std::cout << binaryExponentation(10,20) << std::endl;

}


