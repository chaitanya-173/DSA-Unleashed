#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Graph {
    public:

    void makeAdjList(vector<vector<int>> &edgesList, unordered_map<int, list<int>> &adj, int edges) {
        for(int i=0; i<edges; i++) {
            
            int u = edgesList[i][0];
            int v = edgesList[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    void bfsTraversal(int vertices, unordered_map<int, list<int> > &adj, vector<int> &bfs) {
        
        unordered_map<int, bool> visited;         
        queue<int> q;                             

        q.push(0);                                
        visited[0] = true;                        

        while(!q.empty()) {
            int front = q.front();                
            q.pop();                             
            bfs.push_back(front);                 

            // Traverse all neighbors of the front node using unordered_map with list<int>
            for(auto i: adj[front]) {
                if(!visited[i]) {                           
                    q.push(i);   
                    visited[i] = true;                   
                }
            }
        }

    }

};

int main() {

    int vertices = 5;
    int edges = 6;

    Graph g;

    //edges list given as an input
    vector<vector<int> > edgesList{
        {0,1},{1,2},{2,3},{1,3},{3,4},{0,4}
    };

    //making a Adjacency list (map) using this edges list
    unordered_map<int, list<int> > adjList;
    g.makeAdjList(edgesList, adjList, edges);

    //Print the adjacency list representation of the graph
    for(auto i: adjList) {
        cout << i.first << "-> ";
        for(auto j: i.second) {
            cout << j << ", ";
        } 
        cout << endl;
    }

    //BFS traversal
    vector<int> bfs;
    g.bfsTraversal(vertices, adjList, bfs);
    cout << endl << "BFS: " << endl;
    for(int i=0; i<bfs.size(); i++) {
        cout << bfs[i] << " ";
    }


}