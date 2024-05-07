#include <bits/stdc++.h>
using namespace std;

int main(){

    int v, e; cin >> v >> e;
    vector<vector<int>> g(v);
    while(e--) {
        int va,vb; cin >> va >> vb;
        va--,vb--;
        g[va].emplace_back(vb);
        g[vb].emplace_back(va);
    }

    
    for(auto elements : g) {
        int count = 0;        
        for(auto x : elements)
            count += (int)g[x].size(); 
        cout << count << " ";
    }
    cout << endl;

    return 0;
}