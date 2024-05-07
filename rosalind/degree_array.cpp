#include <bits/stdc++.h>
using namespace std;

int main() {

    int v,e; cin >> v >> e;
    vector<vector<int>> g(v);
    while(e--) {
        int va,vb; cin >> va >> vb;
        va--,vb--;
        g[va].emplace_back(vb);
        g[vb].emplace_back(va);
    }

    for(auto v : g) {
        cout << v.size() << " ";
    }
    cout << endl;

    return 0;
}