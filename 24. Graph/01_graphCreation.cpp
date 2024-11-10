#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

template <typename T>

class Graph {
    public:
    unordered_map<T, list<T> > adj;

    void addEdge(T u, T v, bool direction) {
        //direction = 0 => undirected graph
        //direction = 1 => directed graph

        //Add an edge from u to v
        adj[u].push_back(v);
        if(direction == 0) {   //If undirected, also add edge from v to u
            adj[v].push_back(u);
        }
    }

    //Print the adjacency list representation of the graph
    void printAdjlist() {
        for(auto i: adj) {
            cout << i.first << "-> ";
            for(auto j: i.second) {
                cout << j << ", ";
            }
            cout << endl;
        }
    }

};

// T.C - > O(N+E) where N -> time taken to visiting nodes, E -> for travelling through adj nodes
// S.C -> O(N+E)

int main() {

    int vertex;
    cout << "Enter the number of nodes: ";
    cin >> vertex;

    int edge;
    cout << "Enter the number of edges: ";
    cin >> edge;

    Graph<int> g;

    //Read in edges
    for(int i=0; i<edge; i++) {
        int u, v;
        cin >> u >> v;
        //creating an undirected graph
        g.addEdge(u,v, 0);
    }

    //printing graph's adjacency list
    g.printAdjlist();

}
