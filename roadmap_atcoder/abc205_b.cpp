#include <bits/stdc++.h>


bool compare(std::vector<int> v, int n) {

    std::vector<int> s;
    for(int i = 1; i <= n; ++i)
        s.emplace_back(i);

    for(int i = 0; i < n; ++i)
        if(s[i] != v[i])
            return false;

    return true;

}



int main() {

    int n, aux;
    std::cin >> n;

    std::vector<int> v;
    for(int i = 0; i < n; ++i) {
        std::cin >> aux;
        v.emplace_back(aux);
    }

    std::sort(v.begin(),v.end());

    if (compare(v,n))
        std::cout << "Yes" << std::endl;
    else
        std::cout << "No" << std::endl;

}