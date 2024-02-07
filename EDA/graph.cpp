#include <iostream>
#include<vector>


/*

    Graphs

    1. Adjacency Matrix
    2. Adjacency List
    3. Compact Lits

    Directed Graphs
    
    1. Adjacency Matrix
    2. Adjacency List

*/

// Implementing BFS (Breadth First Search)


int main(void) {

    /*

    // Storing a Graph with adjacency matrix
    int n, m;
    std::cin >> n >> m;

    int adj[n+1][n+1] = {0};
    for(int i = 0; i < m; ++i) {
        int u,v;
        std::cin >> u >> v;
        adj[u][v]++;
        adj[v][u]++;
    }

    */

    // Storgin a Graph with adjacency list
    int n, m;
    std::cin >> n >> m;
    std::vector<int> adj2[n+1];
    for(int i = 0; i < m; ++i){
        int u, v;
        std::cin >> u >> v;
        adj2[u].push_back(v);
        adj2[v].push_back(u);
    }
    

}


