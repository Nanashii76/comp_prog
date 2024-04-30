#include <bits/stdc++.h>
using namespace std;

// Implementing a graph with unordered map (adjacency list)
unordered_map<char,list<char>> g;
set<char> vis;

int shortestPath(char start, char end) {

    queue<pair<char,int>> q;
    vis.insert(start);
    q.push(make_pair(start,0));

    while(not q.empty()) {
        char current = q.front().first;
        int dist = q.front().second;
        q.pop();

        if(current == end)
            return dist;
    
        if(current != end) {
            for(auto x : g[current]) if (not vis.count(x)) {
                vis.insert(x);
                q.push(make_pair(x,dist+1));
            }
        }

    }    

    return -1;
}


int main(){

    // the graph is given as a vector of connected pairs
    list<pair<char,char>> edges {
        {'w','x'},
        {'x','y'},
        {'z','y'},
        {'z','v'},
        {'w','v'},
    };
    for(const auto& edge : edges) {
        g[edge.first].emplace_back(edge.second);
        g[edge.second].emplace_back(edge.first);
    }

    cout << shortestPath('w','z') << endl;
    return 0;
        
}