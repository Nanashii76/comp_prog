#include <bits/stdc++.h>
using namespace std;

vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    vector<int> vis(V,0), ans;
    vis[0] = 1;
    queue<int> q;
    q.push(0);

    while(not q.empty()) {
        int vertice = q.front();
        q.pop();

        ans.emplace_back(vertice);
        for(auto x : adj[vertice]) if (not vis[x]) {
            vis[x] = 1;
            q.push(x);
        }
    }
    return ans;
}