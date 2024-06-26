#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> printGraph(int V, vector<pair<int,int>>edges) {
    vector<vector<int>> ans(V);

    for(auto it : edges) {
        ans[it.first].emplace_back(it.second);
        ans[it.second].emplace_back(it.first);
    }

    return ans;
}