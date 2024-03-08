#include <iostream>
#include <list>
#include <vector>

class Graph{
    int V;
    std::list<int> *l;

public:
    // constructor
    Graph(int v) {
        V = v;
        l = new std::list<int>[V];
    }

    // methods
    void addEdge(int i, int j, bool undir=true) {
        l[i].push_back(j);
        if(undir)
            l[j].push_back(i); // checking if is an undirect graph
    }

    void printAdjList(){
        // Iterate over all the rows
        for(int i=0; i < V; ++i) {
            std::cout << i << ": ";
            // every element of ith linked list
            for(auto node: l[i]) {
                std::cout << node << " ";
            }
            std::cout << std::endl;
        }
    }

};


int main(){

    Graph g(6);
    g.addEdge(0,1);
    g.addEdge(0,4);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(3,5);
    g.addEdge(4,5);

    g.printAdjList();


}
