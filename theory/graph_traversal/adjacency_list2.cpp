#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <unordered_map>

// storing a name in a undirected graph

class Node {

public:

    std::string name;
    std::list<std::string> nbrs;
    
    // constructor
    Node(std::string name) {
        this->name = name;
    }

};

class Graph {

    // Have to contain all nodes
    // Hashmap (string,node)

    std::unordered_map<std::string, Node*> um;

public:

    //  Constructor
    Graph(std::vector<std::string> cities) {
        for(auto city : cities) {
            um[city] = new Node(city);
        }
    }

    // methods
    void addEdge(std::string x, std::string y, bool undir=false) {
        um[x]->nbrs.push_back(y);
        if(undir)
            um[y]->nbrs.push_back(x);
    }

    void printAdjList(){
        for(auto cityPair : um) {
            auto city = cityPair.first;
            Node *node = cityPair.second;

            std::cout << city << ": ";

            for(auto nbr : node->nbrs) {
                std::cout << nbr << ", ";
            }
            std::cout << std::endl;
        }
    }
};


int main(){

    std::vector<std::string> cities = {"Delhi","London","Paris","New York"};
    Graph g(cities);

    g.addEdge("Delhi","London");
    g.addEdge("New York","London");
    g.addEdge("Delhi","Paris");
    g.addEdge("Paris","New York");

    g.printAdjList();

}




