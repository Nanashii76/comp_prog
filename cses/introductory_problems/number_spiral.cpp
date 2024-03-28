#include <bits/stdc++.h>

typedef long long ll;

void solve(ll r, ll c) {

    ll result = 0;

    // finding the diagonal
    if(r == c)
        result = (r*c) - (r-1);
    
    if(r > c) {
        if(r&1) {
            result = ((r*r)-(r-1)) - (r-c);
        } else {
            result = ((r*r)-(r-1)) + (r-c);
        }
    }

    if(c > r) {
        if(c&1) {
            result = ((c*c)-(c-1)) + (c-r);
        } else {
            result = ((c*c)-(c-1)) - (c-r);
        }
    }

    std::cout << result << std::endl;

}

int main(void) {

    int t; std::cin >> t;
    ll r,c;
    for(int i = 0; i < t; ++i) {
        std::cin >> r >> c;
        solve(r,c);
    }

    return EXIT_SUCCESS;
    
}