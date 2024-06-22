#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+10;
vector<vector<int>> g(N);
vector<int> vis(N);
vector<int> sz(N);

void bfs(int start) {

    vis[start] = 1;
    vector<int> values;
    queue<int> q; q.push(start);
    while(not q.empty()) {
        int front = q.front();
        q.pop();
        
        values.emplace_back(front);

        for(auto v : g[front]) if (not vis[v]){
            vis[v] = 1;
            q.emplace(v);
        }

    }

    int n = values.size();
    for(auto x : values)
        sz[x] = n;
    
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
            bfs(i);

    bool possible = 0;
    for(int i = 0; i < n; ++i)
        if(sz[i] != n)
            possible = 1;

    cout << (possible ? "YES" : "NO") << endl;
    return 0;
}