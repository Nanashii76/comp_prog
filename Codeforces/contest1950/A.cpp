#include <bits/stdc++.h>

typedef long long ll;

void solve(int a, int b, int c) {

    if(a < b and b < c)
        std::cout << "STAIR" << std::endl;
    else if (a < b and b > c)
        std::cout << "PEAK" << std::endl;
    else
        std::cout << "NONE" << std::endl;


}

int main(void) {

    int n; std::cin >> n;
    for(int i = 0; i < n; ++i) {
        int a,b,c; std::cin>> a >> b >> c;
        solve(a,b,c);
    }

    return EXIT_SUCCESS;

}