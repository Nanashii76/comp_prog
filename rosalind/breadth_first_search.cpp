#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e3+10;
vector<vector<int>> g(MAX);
vector<bool> vis(MAX);
vector<int> dist(MAX,-1);

void bfs(int s) {

    queue<int> q; q.push(s);
    vis[s] = true;
    dist[s] = 0;

    while(not q.empty()) {
        int v = q.front();
        q.pop();

        for(auto x : g[v]) if(not vis[x]){
            dist[x] = dist[v] + 1;
            q.push(x);
            vis[x] = true;
        }
    }
}


int main(){

    int v,e; cin >> v >> e;
    while(e--) {
        int va,vb; cin >> va >> vb;
        va--,vb--;
        g[va].emplace_back(vb);
    }

    bfs(0);
    for(int i = 0; i < v; ++i)
        cout << dist[i] << " ";
    cout << endl;

    return 0;
}