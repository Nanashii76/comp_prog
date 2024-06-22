#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;
vector<int> indegree(N);
vector<vector<int>> g(N);
vector<int> toposort;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);    

    int n, m; 
    cin >> n >> m;
    string str; 
    cin >> str;

    vector<vector<int>> freq(n, vector<int>(26, 0)); 

    while(m--) {
        int u, v; 
        cin >> u >> v;
        --u, --v;
        g[u].emplace_back(v);
        ++indegree[v];
    }

    queue<int> q;
    for(int i = 0; i < n; ++i) {
        if(not indegree[i]) {
            q.push(i);
            freq[i][str[i] - 'a'] = 1; 
        }
    }   

    int count = 0;
    int maxVal = 0;

    while(not q.empty()) {
        int x = q.front(); 
        q.pop();
        ++count;
        toposort.emplace_back(x);

        for(auto v : g[x]) {
            --indegree[v];
            if(not indegree[v]) {
                q.push(v);
            }
            for (int c = 0; c < 26; ++c) {
                freq[v][c] = max(freq[v][c], freq[x][c] + (str[v] - 'a' == c ? 1 : 0));
                maxVal = max(maxVal, freq[v][c]);
            }
        }
    }

    if(count < n) {
        cout << "-1" << endl; 
    } else {
        cout << maxVal << endl;
    }

    return 0;
}
