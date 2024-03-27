#include <bits/stdc++.h>

typedef long long ll;

void solve(std::vector<ll> v){

    ll count = 0;
    for(int i = 0; i < (int)v.size()-1; ++i) {
        if(v[i] > v[i+1]) {
            count += (v[i]-v[i+1]);
            v[i+1] += (v[i]-v[i+1]);
        }
        //std::cout << count << std::endl;
    } 
    
    std::cout << count << std::endl;

}

int main(void) {

    int n; std::cin>>n;
    std::vector<ll> vec;
    for(int i = 0; i < n; ++i) {
        ll aux; std::cin>>aux;
        vec.push_back(aux);
    }

    solve(vec);

}