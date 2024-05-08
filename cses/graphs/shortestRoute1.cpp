#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> disjktra(vector<vector<pair<int,ll>>> g, int v, int s) {

    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    vector<ll> dist(v,LLONG_MAX);
    dist[s] = 0;
    pq.push({0,s}); // distance and node

    while(!pq.empty()) {
        ll dis = pq.top().first, node = pq.top().second;
        pq.pop();

        if(dis != dist[node]) continue;

        for(auto it : g[node]) {
            int adjNode = it.first;
            ll adjEdge = it.second;

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
    vector<vector<pair<int,ll>>> g(v);
    while(e--) {
        int va,vb,coast; cin >> va >> vb >> coast;
        va--,vb--;
        g[va].emplace_back(make_pair(vb,coast));
    }

    vector<ll> ans = disjktra(g,v,0);
    for(auto x : ans)
        cout << x << " ";
    cout << endl;

    return 0;
}