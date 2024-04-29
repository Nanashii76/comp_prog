#include <bits/stdc++.h>
using namespace std;

// some of variables to store a graph
static int MAX = 1e3+10;
vector<list<int>> g(MAX);
vector<bool> vis(MAX);

// Implementing my version of a pathfinder
void pathfinderDFS(int s, int e, vector<int> &ans) {

}


int main(){

    // Reading a graph
    int v,e; cin >> v >> e;

    while(e--) {
        int x,y; cin >> x >> y;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }


    return 0;

}

