#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> g, vector<int> &vis, int s) {

    stack<int> st;
    st.push(s);
    vis[s] = 1;

    while(not st.empty()) {
        int v = st.top();
        st.pop();

        for(auto x : g[v]) if(not vis[x]){
            st.push(x);
            vis[x] = 1;
        }
    }

}

int main(){

    int v,e; cin >> v >> e;
    vector<vector<int>> g(v);
    vector<int> vis(v,0);
    while(e--) {
        int va,vb; cin >> va >> vb;
        va--,vb--;
        g[va].emplace_back(vb);
        g[vb].emplace_back(va);
    }

    int count = 0;
    for(int i = 0; i < v; ++i) {
        if(not vis[i]) {
            dfs(g,vis,i);
            count++;
        }
    }

    cout << count << endl;

    return 0;
}