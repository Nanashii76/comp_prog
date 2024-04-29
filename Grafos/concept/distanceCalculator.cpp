#include <bits/stdc++.h>
using namespace std;


const int MAX = 1e3+10;
vector<vector<int>> g(MAX);
vector<int> vis(MAX);
vector<int> dist(MAX, -1);
vector<int> past(MAX);


// Implementing a bfs to get the distance between vertices
void get_distance(int v) {

    queue<int> q;
    q.push(v);
    vis[v] = true;
    dist[v] = 0;
    while(!q.empty()) {
        int w = q.front(); q.pop();
        for(auto x : g[w]) if (!vis[w]) {
            dist[x] = dist[v]+1;
            q.push(x);
        }
    }

}

// How to store past vertices 
vector<int> pastVertices(int v) {

    vector<int> ans;
    if(!vis[v]) return ans;

    ans.emplace_back(v);
    while(past[v] != v){
        v = past[v];
        ans.emplace_back(v);
    }

    reverse(ans.begin(),ans.end());
    return ans;

}

void returningPastPath(int v) {

    queue<int> q;
    q.push(v), vis[v] = true;

    past[v] = v;

    while(!q.empty()) {
        int w = q.front(); q.pop();

        for(auto x : g[w]) if (not vis[x]) {
            q.push(x); vis[x] = true;
            past[x] = w;
        }
    }
}
