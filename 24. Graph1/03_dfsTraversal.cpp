#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void dfs(int node, unordered_map<int, bool> &visited, 
        unordered_map<int, list<int>> &adj, vector<int> &component) {

    component.push_back(node);     //ans store
    visited[node] = true;          //mark visited

    //har connected node ke liye recursive call
    for(auto i: adj[node]) {
        if(!visited[i]) {
            dfs(i, visited, adj, component);
        }
    } 
}

void createAdjList(vector<vector<int>> edges, unordered_map<int, list<int> > &adj) {
    for(int i=0; i<edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
} 

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges, 
                                    unordered_map<int, list<int>> adj, vector<vector<int>> &ans) {
    unordered_map<int, bool> visited;

    //for all nodes, call dfs if not visited
    for(int i=0; i<V; i++) {
        if(!visited[i]) {
            vector<int> component;
            dfs(i, visited, adj, component);
            ans.push_back(component);
        }
    }

    return ans;
}
/*
Why the answer ds is 2d ??
Ans -> Taaki agar  hamara graph disconnected ho toh har ek component ke liye ek ek vector separate ho
aur un separate vectors ko store karne ke liye ek vector<vector<int>>  liya gya hai
*/
int main() {

    int vertices = 5;
    int edges = 5;

    vector<vector<int> > edgesList{
        {0,1},{1,2},{1,3},{2,3},{3,4},{0,4}
    };

    unordered_map<int, list<int> > adj;
    createAdjList(edgesList, adj);


    vector<vector<int>> dfs = depthFirstSearch(vertices, edges, edgesList, adj, dfs);

    for(int i=0; i<dfs.size(); i++) {
        for(int j=0; j<dfs[0].size(); j++) {
            cout << dfs[i][j] << " ";
        }
    }

}