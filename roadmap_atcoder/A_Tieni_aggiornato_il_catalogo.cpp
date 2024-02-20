#include <bits/stdc++.h>

typedef unsigned long long ull;

int main(void) {

    int n;
    ull aux;
    char s;
    std::unordered_map<ull, ull> mp;
    std::cin >> n;

    for(int i = 0; i < n; ++i) {
        std::cin >> s >> aux;

        if(s == 'a')
            mp[aux]++;
        else if(s == 'c')
            std::cout << mp[aux] << std::endl;
        else
            mp[aux]--;
    }


}