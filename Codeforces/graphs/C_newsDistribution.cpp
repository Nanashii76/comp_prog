#include <bits/stdc++.h>
using namespace std;

static const int N = 1e6;
vector<vector<int>> g(N);
vector<int> vis(N);
vector<int> connections(N);

void dfs(int start) {

    vector<int> values;
    vis[start] = 1;
    stack<int> st; st.emplace(start);
    while(not st.empty()) {
        int top = st.top(); st.pop();
        values.emplace_back(top);
        for(auto v : g[top]) if (not vis[v]) {
            vis[v] = 1;
            st.emplace(v);
        }
    }

    int n = values.size();
    for(auto x : values)
        connections[x] = n;

}

int main(){

    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);    

    int n, m; cin >> n >> m;
    while(m--) {
        int k, oldValue = -1; cin >> k;
        for(int i = 0; i < k; ++i) {
            int newValue; cin >> newValue;
            if(oldValue != -1) {
                g[newValue].emplace_back(oldValue);
                g[oldValue].emplace_back(newValue);
            }
            oldValue = newValue;
        } 
    }

    for(int i = 1; i <= n; ++i)
        if(not vis[i])
            dfs(i);
        
    for (int i = 1; i <= n; ++i) {
        cout << connections[i] << " ";
    }

    cout << endl; 
    return 0;
}