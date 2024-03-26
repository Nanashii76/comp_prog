#include <bits/stdc++.h>

void solve(int n) {

    std::vector<int> vec;
    for(int i = n; i >= 1; --i)
        vec.push_back(i);

    for(int i = 0; i < n; ++i)
        std::cout << vec[i] << " ";

    std::cout << std::endl;

}

int main(void) {
    
    int n; std::cin>>n;

    if(n&1)
        std::cout << "-1" << std::endl;
    else
        solve(n); 

   
}
