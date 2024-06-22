#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
static const int N = 1e5+10;
vector<vector<int>> g(N);
vector<int> vis(N);


ll dfs(vector<int> &c, int start) {

    ll minCoast = c[start];
    vis[start] = 1;

    for(auto x : g[start]) if (not vis[x])
        minCoast = min(minCoast, dfs(c, x));

    return minCoast;
    
}

int main(){

    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);    

    int n, m; cin >> n >> m;
    vector<int> coast(n);
    for(int i = 0; i < n; ++i) cin >> coast[i];
    for(int i = 0; i < m; ++i) {
        int a,b; cin >> a >> b;
        --a,--b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }

    ll count = 0;
    for(int i = 0; i < n; ++i) {
        if(not vis[i]) {
            count += dfs(coast, i);
        }
    }

    cout << count << endl;
    return 0;
}