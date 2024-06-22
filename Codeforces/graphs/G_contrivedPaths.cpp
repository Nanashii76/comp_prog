#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = LLONG_MAX;

void dijkstra(ll source, ll n, vector<vector<pair<ll, ll>>>& g, vector<ll>& dists) {
    vector<ll> vis(n, 0);
    fill(dists.begin(), dists.end(), INF);

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    dists[source] = 0;

    pq.push({0, source});

    while (!pq.empty()) {
        pair<ll, ll> v = pq.top(); pq.pop();
        ll dist = v.first, target = v.second;
        if (vis[target]) continue;
        vis[target] = 1;

        for (auto x : g[target]) {
            if (!vis[x.first]) {
                ll ndist = dist + x.second;
                if (ndist < dists[x.first]) {
                    dists[x.first] = ndist;
                    pq.push({dists[x.first], x.first});
                }
            }
        }
    }
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m, k; cin >> n >> m >> k;

    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<vector<pair<ll, ll>>> g(n + 1);  

    for (ll i = 0; i < m; ++i) {
        ll u, v, w;
        cin >> u >> v >> w;
        --u; --v; 
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }

    for (ll i = 0; i < n; ++i) {
        g[i].emplace_back(n, a[i]);
        g[n].emplace_back(i, a[i]);
    }
    ++n;  

    vector<ll> dists(n);
    for (ll i = 0; i < k; ++i) {
        ll x;
        cin >> x;
        --x;
        dijkstra(x, n, g, dists);
        for (ll j = 0; j < n - 1; ++j) {
            cout << dists[j] << " ";
        }
        cout << endl;
    }

    return 0;
}
