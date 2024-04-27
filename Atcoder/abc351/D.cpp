#include <bits/stdc++.h>

using namespace std;
#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e3 + 10;
vector<vector<int>> g(MAX);
vector<bool> visited(MAX);
int pathCount = 0;

void dfs(int v) {
    visited[v] = true;

    if (g[v].empty()) {
        pathCount++;
    } else {
        for (int u : g[v]) {
            if (!visited[u]) {
                dfs(u);
            }
        }
    }

    visited[v] = false;
}

int main() {
    
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j) {
            char x;
            cin >> x;
            if(x == '.') {
                g[i].emplace_back(j);
            }
        }

    for (int i = 0; i < n; ++i) {
        dfs(i);
    }

    cout << pathCount << endl;

    return 0;
}