#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> bfsOfGraph(map<int,vector<int>> adjList) {

    vector<int> ans;
    vector<int> visited(adjList.size(), 0);
    queue<int> q;

    q.push(0);
    visited[0] = true;

    while(!q.empty()) {
        int front = q.front();
        q.pop();
        ans.push_back(front);

        for(auto i: adjList[front]) {
            if(!visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }

    return ans;
}

void dfs(int node, map<int,vector<int>> &adj, vector<int> &visited, vector<int> &ans) {
        
    ans.push_back(node);
    visited[node] = true;
    
    for(auto i: adj[node]) {
        if(!visited[i]) {
            dfs(i, adj, visited, ans);
        }
    }
}

vector<int> dfsOfGraph(map<int,vector<int>> &adj) {
    
    vector<int> ans;
    vector<int> visited(adj.size(), 0);
    
    dfs(0, adj, visited, ans);
    return ans;
}

int main() {

    map<int, vector<int> > adjList;
    adjList[0] = {4};
    adjList[1] = {4,5};
    adjList[2] = {3,4};
    adjList[3] = {2,5};
    adjList[4] = {0,1,2};
    adjList[5] = {1,3};

    cout << "Adjacency list: " << endl;
    for(auto i: adjList) {
        cout << i.first << "-> ";
        for(auto j: i.second) {
            cout << j << ", ";
        }
        cout << endl;
    } 

    vector<int> bfs = bfsOfGraph(adjList);

    vector<int> dfs = dfsOfGraph(adjList);


    cout << endl << "BFS traversal: " << endl;
    for(auto i: bfs) {
        cout << i << " ";
    } 

    cout << endl << "DFS traversal: " << endl;
    for(auto i: dfs) {
        cout << i << " ";
    } 


}