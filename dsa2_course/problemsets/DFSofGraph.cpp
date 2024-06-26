#include <bits/stdc++.h>
using namespace std;

void dfs(int v, vector<int> adj[], vector<int>& vis, vector<int>& ans) {
    vis[v] = 1;
    ans.push_back(v);
    for (int u : adj[v]) {
        if (!vis[u]) {
            dfs(u, adj, vis, ans);
        }
    }
}

vector<int> dfsOfGraph(int V, vector<int> adj[]) {
    vector<int> vis(V, 0), ans;
    dfs(0, adj, vis, ans);
    return ans;
}