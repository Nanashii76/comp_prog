#include <bits/stdc++.h>
using namespace std;

/*
    Problem stetmant: Given an matrix with islands on the ocena, discover how
    many islands have;

    note: the island is the set of pieces of dirt
*/


// For this implementation, I'll use matrix
vector<vector<char>> g {
    {'w','d','w','w','d','w'},
    {'d','d','w','w','d','w'},
    {'w','d','w','w','w','w'},
    {'w','w','w','d','d','w'},
    {'w','d','w','d','d','w'},
    {'w','w','w','w','w','w'},
};
set<pair<int,int>> vis;

void dfs_mat(int r, int c) {

    vis.insert({r,c});

    // to go left
    if(c > 0 and (not vis.count({r,c-1})) and g[r][c-1] == 'd')
        dfs_mat(r,c-1);
    // to go up
    if(r > 0 and (not vis.count({r-1,c})) and g[r-1][c] == 'd')
        dfs_mat(r-1,c);
    // to go right
    if(c < (int)g[0].size() and (not vis.count({r,c+1})) and g[r][c+1] == 'd')
        dfs_mat(r,c+1);
    // to go  down
    if(r < (int)g.size() and (not vis.count({r+1,c})) and g[r+1][c] == 'd')
        dfs_mat(r+1,c);

}

int main(){

    int count = 0;
    for(int i = 0; i < (int)g.size(); ++i)
        for(int j = 0; j < (int)g[0].size(); ++j) {
            if(not vis.count({i,j}) and g[i][j] == 'd') {
                dfs_mat(i,j);
                count++;
            }
        }

    cout << count << endl;

    return 0;
}
