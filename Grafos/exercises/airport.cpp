#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e4+10;

int main(){

    int v, a; cin >> v >> a;
    int count = 1;
    while(v) {
        vector<list<int>> g(MAX);
        while(a--) {
            int i,j; cin >> i >> j;
            g[i].emplace_back(j);
            g[j].emplace_back(i);
        }
        int maxVertice = 0; vector<int> idx;
        for(int i = 1; i <= v; ++i) {
            maxVertice = max(maxVertice,(int)g[i].size());
        }

        for(int i = 1; i <= v; ++i) {
            if((int)g[i].size() >= maxVertice) {
                maxVertice = g[i].size();
                idx.emplace_back(i);
            }
        }
            
        cout << "Teste " << count << endl;
        for(auto x : idx) 
            cout << x << " ";
        cout << endl;
        count++;
        cin >> v >> a;
    }

    return 0;
}