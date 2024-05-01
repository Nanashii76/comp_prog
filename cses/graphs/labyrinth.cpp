#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> g;
set<pair<int, int>> vis;

bool isValid(int x, int y) {
    return (x >= 0 and y >= 0 and x < (int)g.size() and y < (int)g[0].size() and g[x][y] == '.' and (not vis.count({x, y})));
}

bool findPath(int r, int c, int endi, int endj) {

    queue<pair<int, int>> q;
    bool found = false;
    q.push({r, c});

    while (not q.empty()) {

        int i = q.front().first;
        int j = q.front().second;
        vis.insert({i, j});
        q.pop();

        //cout << i << "," << j << "--> " << g[i][j] <<endl;

        if(i == endi and j == endj)
            return true;

        // left, right, up, down
        if (isValid(i, j - 1)) {
            q.push({i, j - 1});
            g[i][j - 1] = 'L';
            //found = true;
        }
        if (isValid(i, j + 1)) {
            q.push({i, j + 1});
            g[i][j + 1] = 'R';
            //found = true;
        }
        if (isValid(i - 1, j)) {
            q.push({i - 1, j});
            g[i - 1][j] = 'U';
        }
        if (isValid(i + 1, j)) {
            q.push({i + 1, j});
            g[i + 1][j] = 'D';
            //found = true;
        }
    }

    return found;
}

int main() {
    
    int n, m; cin >> n >> m;
    g.assign(n, vector<char>(m));
    pair<int, int> start, end;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> g[i][j];
            if (g[i][j] == 'A') start = {i, j};
            if (g[i][j] == 'B') end = {i, j};
        }
    }

    g[end.first][end.second] = '.';

    if (findPath(start.first, start.second,end.first,end.second)) {
        string ans = "";
        int curri = end.first, currj = end.second;

        while (not (curri == start.first and currj == start.second)) {
            ans += g[curri][currj];
            switch (g[curri][currj]) {
                case 'D':
                    curri--;
                    break;
                case 'U':
                    curri++;
                    break;
                case 'R':
                    currj--;
                    break;
                case 'L':
                    currj++;
                    break;
            }
        }

        reverse(ans.begin(), ans.end());
        cout << "YES" << endl;
        cout << ans.size() << endl;
        cout << ans << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
