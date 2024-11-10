#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <vector>

using namespace std;

class Graph {
private:
    unordered_map<int, list<int>> adjList;

public:
    // Function to add an edge to the graph
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u); // Since the graph is undirected
    }

    // BFS Traversal
    void bfs(int start) {
        unordered_map<int, bool> visited;
        queue<int> q;

        // Mark the start node as visited and enqueue it
        visited[start] = true;
        q.push(start);

        cout << "BFS Traversal starting from node " << start << ": ";
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";

            // Enqueue all unvisited adjacent nodes
            for (int neighbor : adjList[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }

    // Helper function for DFS
    void dfsHelper(int node, unordered_map<int, bool>& visited) {
        visited[node] = true;
        cout << node << " ";

        // Visit all unvisited neighbors
        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                dfsHelper(neighbor, visited);
            }
        }
    }

    // DFS Traversal
    void dfs(int start) {
        unordered_map<int, bool> visited;
        cout << "DFS Traversal starting from node " << start << ": ";
        dfsHelper(start, visited);
        cout << endl;
    }
};

int main() {
    Graph g;

    // Add edges to the graph
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);

    // Perform BFS and DFS traversals
    g.bfs(0);
    g.dfs(0);

    return 0;
}

    /*
    
    0
   / \
  1   2
   \ / 
    3
    |
    4
    |
    5

    The adjacency list for this graph looks like this:

    0 -> 1, 2
    1 -> 0, 3
    2 -> 0, 3
    3 -> 1, 2, 4
    4 -> 3, 5
    5 -> 4

    */
