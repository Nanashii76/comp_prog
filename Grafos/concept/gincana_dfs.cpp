#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e3+10;

vector<vector<int>> graph(MAX);
vector<bool> vis(MAX);

void dfs(int v) {

    vis[v] = true;
    for(const auto x : graph[v]) if (!vis[x]) 
        dfs(x);

}

int main(){

    int n, m; cin >> n >> m;
    for(int k = 0; k < m; ++k) {
        int i, j; cin >> i >> j;
        --i, --j;

        graph[i].emplace_back(j);
        graph[j].emplace_back(i);
    }

    int times = 0;
    for(int i = 0; i < n; ++i) if(!vis[i]) {
        dfs(i);
        times++;
    }

    cout << times << endl;

    return 0;
}