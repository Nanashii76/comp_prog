#include <bits/stdc++.h>
using namespace std;

// Importanting variables to store a graph
const int MAX = 1e3+10;
vector<list<int>> g(MAX);
vector<bool> vis(MAX);

// Implementing a dfs with recursind and stack
void dfs_recursive(int v) {

    vis[v] = true;
    cout << v << " ";
    for(auto x : g[v]) if (not vis[x]) {
        dfs_recursive(x);
    }

}

void dfs_iterative(int v){

    vis[v] = true;
    stack<int> st;
    st.push(v);
    while(not st.empty()) {
        int w = st.top();
        st.pop();

        cout << w << " ";

        for(auto x : g[w]) if (not vis[x]) {
            vis[x] = true;
            st.push(x);
        }
    }
}

// Implementing a bfs with queue
void bfs(int v){

    vis[v] = true;
    queue<int> q;
    q.push(v);

    while(not q.empty()) {
        int w = q.front();
        q.pop();

        cout << w << " ";

        for(auto x : g[w]) if (not vis[x]) {
            vis[x] = true;
            q.push(x);
        }
    }
}


int main() {

    // Storing a example graph
    int v, e; cin >> v >> e;
    while(e--) {
        int x,y; cin >> x >> y;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }

    bfs(0); // replace the code here    

    return 0;
}