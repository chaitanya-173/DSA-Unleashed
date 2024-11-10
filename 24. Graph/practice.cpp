#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Graph {
    public:

    unordered_map<int, list<int> > makeAdjList(vector<vector<int>> edges) {
        unordered_map<int, list<int> > adj;
        for(int i=0; i<edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return adj;
    }

    vector<int> bfsTraversal(unordered_map<int, list<int> > adj) {
        vector<int> ans;
        unordered_map<int, bool> visited;
        queue<int> q;
        q.push(0);
        visited[0] = true;

        while(!q.empty()) {
            int front = q.front();
            q.pop();
            ans.push_back(front);

            for(auto i: adj[front]) {
                if(!visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }

        }
        return ans;
    }

};

int main() {

    Graph g;

    vector<vector<int>> edges{ {0,1},{1,2},{1,3},{2,3},{3,4},{0,4} };

    unordered_map<int, list<int> > adj = g.makeAdjList(edges);

    cout << endl << "Printing adj list: " << endl;
    for(auto i: adj) {
        cout << i.first << "-> ";
        for(auto j: i.second) {
            cout << j << ", ";
        }
        cout << endl;
    }

    vector<int> bfs = g.bfsTraversal(adj);
    cout << endl << "Printing bfs Traversal: " << endl;
    for(auto i: bfs) {
        cout << i << " ";
    }




}