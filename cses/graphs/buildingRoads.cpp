#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5+10;
vector<list<int>> g(MAX);
set<int> vis;

int dfs(int s) {

    vis.insert(s);
    stack<int> st;
    int current;
    st.push(s);

    while(not st.empty()) {
        current = st.top();
        st.pop();

        for(auto x : g[current]) if (not vis.count(x)) {
            st.push(x);
            vis.insert(x);
        }
    }

    return current;

}


int main(){

    int n,m; cin >> n >> m;
    while(m--) {
        int a,b; cin >> a >> b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }

    int count = 0;
    vector<int> res;
    for(int i = 1; i <= n; ++i) {
        if(not vis.count(i)) {
            res.emplace_back(dfs(i));
            count++;
        }
    }

    if(count-1) {
        cout << count-1 << endl;
        for(int i = 1; i < (int)res.size(); ++i)
            cout << res[0] << " " << res[i] << endl;
    } else
        cout << 0 << endl;

    return 0;

}
