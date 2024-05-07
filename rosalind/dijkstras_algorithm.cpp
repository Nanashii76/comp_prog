#include <bits/stdc++.h>
using namespace std;

vector<int> dijktras(vector<vector<pair<int,int>>> g, int V, int s) {

    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> dist(V,INT_MAX);
    dist[s] = 0;
    pq.push({0,s}); // distance and node;

    while(not pq.empty()) {
        int dis = pq.top().first, node = pq.top().second;
        pq.pop();

        if(dis != dist[node]) continue;

        for(auto it : g[node]) {
            int adjNode = it.first;
            int adjEdge = it.second;

            if(dis + adjEdge < dist[adjNode]) {
                dist[adjNode] = dis + adjEdge;
                pq.push({dist[adjNode],adjNode});
            }
        }
    }

    return dist;

}


int main(){

    int v,e; cin >> v >> e;
    vector<vector<pair<int,int>>> g(v);
    while(e--) {
        int va,vb,coast; cin  >> va >> vb >> coast;
        va--,vb--;
        g[va].emplace_back(make_pair(vb,coast));
    }

    vector<int> ans = dijktras(g,v,0);
    for(auto x : ans)
        cout << (x!=INT_MAX?x:-1) << " ";
    cout << endl;

    return 0;
}