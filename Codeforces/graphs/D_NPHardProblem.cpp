#include <bits/stdc++.h>
using namespace std;

static int N = 1e6+10;
vector<vector<int>> g(N);
vector<int> vis(N);
vector<int> color(N);

bool possible = 1;

void dfs(int start, bool c) {

    if(vis[start]) return;
    vis[start] = 1;

    color[start] = c;

    for(auto v : g[start]) if (not vis[v]) {
        dfs(v,c^1); //getting the oposit color with xor
    } else {
        if(c == color[v])
            possible = 0;
    }

}

int main(){

    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);    

    int n, m; cin >> n >> m;
    while(m--) {
        int u,v; cin >> u >> v;
        --u,--v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    for(int i = 0; i < n; ++i)
        if(not vis[i])
            dfs(i,0);

    if(possible) {
        vector<int> count(2,0);
        for(int i = 0; i < n; ++i) ++count[color[i]];

        cout << count[0] << endl;
        for(int i = 0; i < n; ++i)
            if(color[i] == 0)
                cout << i+1 << " ";
        cout << endl;
    
        cout << count[1] << endl;
        for(int i = 0; i < n; ++i)
            if(color[i] == 1)
                cout << i+1 << " ";
        cout << endl;
    } else
        cout << "-1" << endl;
    
    return 0;

}