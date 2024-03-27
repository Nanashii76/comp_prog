#include <bits/stdc++.h>

void solve(std::vector<int> v) {

    if(v.size() > 1 && v.size() < 4) {
        std::cout << "NO SOLUTION" << std::endl;
        return;
    }

    for(int i = 0; i < (int)v.size(); ++i) {
        if((v[i]&1) != 1)
            std::cout << v[i] << " ";
    }

    for(int i = 0; i < (int)v.size(); ++i) {
        if(v[i]&1)
            std::cout << v[i] << " ";
    }
    
    std::cout << std::endl;

}


int main(void) {

    int n; std::cin >> n;
    std::vector<int> vec;
    for(int i = 1; i<=n; ++i)
        vec.push_back(i);

    solve(vec);

}