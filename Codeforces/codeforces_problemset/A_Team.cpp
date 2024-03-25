#include <bits/stdc++.h>

int solve(int a1, int a2, int a3) {

    int sum = (a1+a2+a3) / 2;
    return sum;
    
}


int main(void) {

    int n; std::cin >> n;
    int cout = 0;
    for(int i = 0; i < n; ++i) {
        int a1,a2,a3; std::cin>> a1 >> a2 >> a3;
        cout += solve(a1,a2,a3);
    }

    std::cout << cout << std::endl;

}