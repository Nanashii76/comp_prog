#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;
vector<int> indegree(N);
vector<vector<int>> g(N);
vector<int> toposort;

int main() {

    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);    

    int n, m; cin >> n >> m;
    string str; cin >> str;
    while(m--) {
        int u,v; cin >> u >> v;
        --u,--v;
        g[u].emplace_back(v);
        ++indegree[v];
    }

    queue<int> q;
    int count = 0;
    for(int i = 0; i < n; ++i) {
        if(not indegree[i])
            q.push(i);
    }   

    while(not q.empty()) {
        ++count;
        int x = q.front(); q.pop();
        toposort.emplace_back(x);

        for(auto v : g[x]) {
            --indegree[v];
            if(not indegree[v]) {
                q.push(v);
            }
        }
    }
    
    if(count < n)
        cout << "-1" << endl; 

    else {
        
        unordered_map<char,int> mp;
        for(auto x : toposort)
            mp[str[x]]++;
        
        int maxVal = 0;
        for(auto it : mp)
            maxVal = max(maxVal,it.second);

        cout << maxVal << endl;
    
    }

    return 0;
}