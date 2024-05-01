#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5+10;
vector<list<int>> g(MAX);
vector<int> past(MAX);
set<int> vis;

vector<int> path(int v) {
    vector<int> res;
    if(not vis.count(v)) return res;

    res.emplace_back(v);
    while(past[v] != v) {
        v = past[v];
        res.emplace_back(v);
    }
    
    reverse(res.begin(),res.end());
    return res;

}

void bfs(int s) {

    queue<int> q;
    q.push(s); vis.insert(s);

    past[s] = s;
    while(not q.empty()) {
        int v = q.front(); q.pop();

        for(auto x : g[v]) if (not vis.count(x)) {
            q.push(x); vis.insert(x);
            past[x] = v;
        }
    }
}


int main(){

    int v, e; cin >> v >> e;
    while(e--) {
        int x,y; cin >> x >> y;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }

    bfs(1);
    vector<int> ans = path(v);
    if(ans.size()) {
        cout << ans.size() << endl;
        for(auto x : ans)
            cout << x << " ";
        cout << endl;
    } else
        cout << "IMPOSSIBLE" << endl;

    return 0;
}