#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e3+10;
vector<vector<int>> graph(MAX);
vector<bool> vis(MAX, false);


// Implementing the most simply possible dfs with recursion
void dfs(int v) {

    vis[v] = true;

    cout << v << " ";

    for(auto x : graph[v]) if(not vis[x]) {
        dfs(x);
    }

}

// Implementing the most simply dfs with stack
void dfs_interactive(int v) {

    stack<int> st;
    st.push(v);

    while(!st.empty()) {
        int w = st.top();
        st.pop();

        if(not vis[w]) {
            vis[w] = true;        
            cout << w << " ";
        }

        for(auto x : graph[w])
            if(not vis[x])
                st.push(x);
    }

}

// Implementando um bfs
void bfs(int v) {

    queue<int> q;
    q.push(v), vis[v] = true;

    while(!q.empty()) {
        int w = q.front(); q.pop();
        cout << w << " ";
        for(auto x: graph[w]) if (not vis[x]) {
            q.push(x), vis[x] = true;
        }
    }

}

int main(){

    int v, e; cin >> v >> e;
    for(int i = 0; i < e; ++i) {
        int v, w; cin >> v >> w;
        graph[v].emplace_back(w);
        graph[w].emplace_back(v);
    }

    bfs(0);

}