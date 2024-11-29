// 1514. Path with Maximum Probability
#include <bits/stdc++.h>
using namespace std;

double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start_node, int end_node) {
    
    vector<vector<pair<int,double>>> graph(n);
    for(int i = 0; i < (int)edges.size(); ++i) {
        int v = edges[i][0], u = edges[i][1];
        double prob = succProb[i];
        graph[v].emplace_back(make_pair(u,prob));
        graph[u].emplace_back(make_pair(v,prob));
    }

    vector<double> dist(n, 0.0);
    dist[start_node] = 1.0;
    priority_queue<pair<double,int>> pq;
    pq.push(make_pair(1.0, start_node));

    while(not pq.empty()) {
        pair<double, int> v = pq.top();
        pq.pop();

        for(pair<int, double> w : graph[v.second]) {
            double newProb = v.first * w.second;
            if(newProb > dist[w.first]) {
                dist[w.first] = newProb;
                pq.push(make_pair(newProb, w.first));
            }
        }

    }

    return dist[end_node];

}

/*
int main() {
    int n = 3;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {0, 2}};
    vector<double> succProb = {0.5, 0.5, 0.2};
    int start = 0, end = 2;

    cout << fixed << setprecision(5) << maxProbability(n, edges, succProb, start, end) << endl;
    return 0;
}
*/
