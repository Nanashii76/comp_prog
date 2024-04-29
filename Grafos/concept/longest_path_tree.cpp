#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e4+10;
vector<vector<int>> graph(MAX);
int dist[MAX]; // guardar a distânia de cada vértice como -1, memset não funciona em vector

void dfs(int v) {

    for(auto x : graph[v]) if (dist[x] == -1) {
        dist[x] = dist[v] + 1;
        dfs(x);
    }

}

int main(){

    int n; cin >> n;
    for(int i = 0; i < n-1; ++i) {
        int x,y; cin >> x >> y;
        graph[x].emplace_back(y);
        graph[y].emplace_back(x);
    }

    // para todas as posições de dist, seta ela como -1
    memset(dist,-1,sizeof dist);

    dist[0] = 0;
    dfs(0);

    int pos = -1, distmax = -1;
    for(int i = 0; i < n; ++i) {
        if(dist[i] > distmax) {
            distmax = dist[i];
            pos = i;
        }
    }

    memset(dist,-1,sizeof dist);
    dist[pos] = 0;
    dfs(pos);

    int diameter = 0;
    for(int i = 0; i < n; ++i) diameter = max(diameter,dist[i]);

    cout << diameter << endl; 
    
    return 0;
}