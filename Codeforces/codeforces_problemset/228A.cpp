#include <bits/stdc++.h>

typedef long long ll;

int main(void) {

    std::set<int> s;
    ll aux;
    for(int i = 0; i < 4; ++i) {
        std::cin>>aux;
        s.emplace(aux);
    }

    std::cout << 4-s.size() << std::endl;

}
