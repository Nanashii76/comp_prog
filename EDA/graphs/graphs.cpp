#include <iostream>
#include <vector>
#include <list>
#include <queue>

/*
    Implementing data structure graph 

    forms to store a graph
    1. edje list
    2. adjacency matrix
    3. adjacency list

*/

// Implementing a Graph with adjacency list

class Graph {

    int V;
    std::list<int> *l; // creating a pointer to an array of list

public:
    // constructor graph;
    Graph(int v) {
        V = v;
        l = new std::list<int>[V];
    }

    // methods of the graph
    void addEdge(int i, int j, bool undir=true){
        l[i].emplace_back(j);
        if(undir)
            l[j].emplace_back(i);
    }

    void printElements(){
        // Iterate over all the rows
        for(int i = 0; i<V; ++i) {
            std::cout << i << "--> "; // printing actual row
            // every element of ith linked list
            for(auto node : l[i]) {
                std::cout << node << " "; 
            }
            std::cout << std::endl;
        }
    }

    // Breadth first search Traversal (BFS)
    /*
        BFS: Printing elements acording to the level
    */
    void bfs(int start) {
        std::queue<int> q; // creating a queue to store neighbors of vertices
        bool *visited = new bool[V]{0}; // creating a bool vector of size V to store visited vertices

        q.push(start); // inicializing value to search
        visited[start] = true;

        while(!q.empty()) {
            // Do some work for every node
            int f = q.front();
            std::cout << f << " ";
            q.pop();

            // push the neighboors of the current node inside q if they're not visited
            for(auto nbr : l[f]) {
                if(!visited[nbr]) {
                    q.push(nbr);
                    visited[nbr] = true; // mark element as visited
                }
            }
        }
    }
};



int main(void) {

    // reading a undirected Graph
    // int v, e;
    // std::cin >> v >> e;

    // Allocating a graph an his elements dinamically
    /*
    Graph g(v);
    for(int i = 0; i < e; ++i) {
        int a,b;
        std::cin >> a >> b;
        g.addEdge(a,b);
    }
    */

   // Aloccating a graph Statically
   Graph g(7);
   g.addEdge(0,1);
   g.addEdge(1,2);
   g.addEdge(2,3);
   g.addEdge(3,5);   
   g.addEdge(5,6);
   g.addEdge(4,5);
   g.addEdge(0,4);
   g.addEdge(3,4);

   g.printElements();

   g.bfs(1);

}

