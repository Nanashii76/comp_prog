#include <bits/stdc++.h>

typedef unsigned long long ull;

// Optimize function, it's causing TLE -> maybe using PA
ull ban(ull k, ull x) {

    ull msg = 0, soma = 0;

    for(ull i = 0; soma < x || soma == 2*k-1; ++i) {
        if(i <= k) {
            soma += 1+i;
            msg++;
        } else {
            soma += (--i);
            msg++;
        }
    }

    return msg;

}


int main(void) {

    int t;
    std::cin >> t;

    for(int i = 0; i < t; ++i) {
        ull a, b;
        std::cin >> a >> b;
        std::cout << ban(a,b) << std::endl;
    }

}

