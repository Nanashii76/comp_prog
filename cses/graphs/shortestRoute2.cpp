#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> dijkstra(vector<vector<pair<ll,ll>>> g, ll v, ll s) {

    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    vector<ll> dist(v,LLONG_MAX);
    dist[s] = 0;
    pq.push({0,s});

    while(not pq.empty()) {
        ll dis = pq.top().first;
        ll node = pq.top().second;
        pq.pop();

        if(dis != dist[node]) continue;

        for(auto it : g[node]) {
            ll ajdNode = it.first;
            ll adjEdge = it.second;

            if( dis + adjEdge < dist[ajdNode]) {
                dist[ajdNode] = dis + adjEdge;
                pq.push({dist[ajdNode], ajdNode});
            }
        }

    }

    return dist;

}


int main(){

    ll v,e,q; cin >> v >> e >> q;
    vector<vector<pair<ll,ll>>> g(v);
    while(e--) {
        ll va,vb,coast; cin >> va >> vb >> coast;
        va--,vb--;
        g[va].emplace_back(make_pair(vb,coast));
        g[vb].emplace_back(make_pair(va,coast));
    }

    while(q--) {
        ll s,e; cin >> s >> e;
        s--,e--;
        vector<ll> ans = dijkstra(g,v,s);
        cout << (ans[e]==LLONG_MAX?-1:ans[e]) << endl;
    }

    return 0;

}