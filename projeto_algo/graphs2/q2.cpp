// 2290. Minimum Obstacle Removal to Reach Corner
#include <bits/stdc++.h>
using namespace std;

int minObstaclesToRemove(vector<vector<int>>& grid) {
    
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> dist(m, vector<int>(n, INT_MAX));  
    dist[0][0] = 0;

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    pq.push({0, {0, 0}});  

    vector<int> dx = {0, 0, 1, -1};  
    vector<int> dy = {1, -1, 0, 0};

    while (not pq.empty()) {
        pair<int, pair<int,int>> pos = pq.top();
        pq.pop();
        int x = pos.second.first, y = pos.second.second;

        if (x == m - 1 and y == n - 1) return pos.first;  

        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx >= 0 and ny >= 0 and nx < m and ny < n) {
                int newCost = pos.first + grid[nx][ny];  
                if (newCost < dist[nx][ny]) {
                    dist[nx][ny] = newCost;
                    pq.push({newCost, {nx, ny}});
                }
            }
        }
    }
    return -1;  
}