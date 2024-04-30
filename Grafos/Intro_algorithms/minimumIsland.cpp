#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> g {
    {'w','d','w','w','d','w'},
    {'d','d','w','w','d','w'},
    {'w','d','w','w','w','w'},
    {'w','w','w','d','d','w'},
    {'w','w','w','d','d','w'},
    {'w','w','w','d','w','w'},
};
set<pair<int,int>> vis;

int countingIslands(int r, int c) {

    if(vis.count({r,c}))
        return 0;
    
    vis.insert({r,c});
    int count = 1;
    // to go left
    if(c > 0 and g[r][c-1] == 'd')
        count += countingIslands(r,c-1);

    // to go up
    if(r > 0 and g[r-1][c] == 'd')
        count += countingIslands(r-1,c);

    // to go right
    if(c < (int)g[0].size()-1 and g[r][c+1] == 'd')
        count += countingIslands(r,c+1);

    // to go down
    if(r < (int)g.size()-1 and g[r+1][c] == 'd')
        count += countingIslands(r+1,c);

    return count;
}

int main(){

    int minIsland = numeric_limits<int>::max();
    for(int i = 0; i < (int)g.size(); ++i) {
        for(int j = 0; j < (int)g[0].size(); ++j) {
            if(g[i][j] == 'd' and (not vis.count({i,j}))) {
                int island = countingIslands(i,j);
                minIsland = min(minIsland,island);
            }
        }
    }

    cout << minIsland << endl;

    return 0;
}


