#include <bits/stdc++.h>

typedef long long ll;

int main(void) {

    ll n, x;
    std::vector<std::pair<ll,ll>> v;
    
    std::cin >> n >> x;
    // Needs resize, also it's going exced the limit (TLE)
    v.resize(n);
    for(int i = 0; i < n; ++i) {
        std::cin >> v[i].first;
        v[i].second = i+1;
    }

    std::sort(v.begin(), v.end());

    int i = 0, j = n-1;
    while(i < j) {
        ll sum = 0;
        sum = v[i].first + v[j].first;
        if(sum == x) {
            std::cout << v[j].second << " " << v[i].second;
            return 0;
        } else if (sum < x)
            i++;
        else
            j--;
    }

    std::cout << "IMPOSSIBLE" << std::endl;

}