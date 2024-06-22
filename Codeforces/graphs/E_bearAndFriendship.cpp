#include <bits/stdc++.h>
using namespace std;

// Implementing and learning a DSU

const int N = 1e5;
vector<vector<int>> g(N);
vector<int> label(N); // current component of each vertex
vector<int> size(N); // size of components
vector<int> nedges(N); // number of edges in each component

void relabel(int v, int target) { // relabel vertex v and neighbors to targert

    if(label[v] == target) return;
    label[v] = target;

    for(auto x : g[v])
        relabel(x,target);

}

void merge(int u, int v) {

    g[u].emplace_back(v);
    g[v].emplace_back(u);

    int compu = label[u], compv = label[v];
    ++nedges[compu];

    if(compv == compu) return;

    if(size[compu] > size[compv]) {
        swap(u,v);
        swap(compu,compv);
    } 
    // assume size[compu] <= size[compv]
    relabel(u,compv);
    size[compv] += size[compu];
    nedges[compv] += nedges[compu];

}

int main(){

    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);    

    int n,m; cin >> n >> m;

    for(int i = 0; i < n; ++i) {
        size[i] = 1;
        label[i] = i;
    }

    while(m--) {
        int v,u; cin >> v >> u;
        --v,--u;
        g[v].emplace_back(u);
        g[u].emplace_back(v);   

        merge(u, v);
    }

    bool possible = 1;
    for(int i = 0; i < n; ++i)
        if(nedges[label[i]] != size[label[i]] * (size[label[i]] - 1) / 2 )
            possible = 0;

    cout << (possible ? "YES" : "NO") << endl;

    return 0;
}