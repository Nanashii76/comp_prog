#include <bits/stdc++.h>

int main(){

    int n;
    // letter and your position
    std::vector<std::pair<char,int>> v;
    std::cin >> n;
    v.resize(n);

    for(int i = 0; i < n; ++i) {
        std::cin >> v[i].first;
        v[i].second = i;
    }

    // Getting the first vector element, and your second to compare
    int i = 0, j = i+1;

    // When the values returns to same, or if is less, so the pattern has solved
    while(v[i].first < v[j].first)
        j++;

    std::cout << j << std::endl;

}