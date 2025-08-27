#include <bits/stdc++.h>
using namespace std;

void dfs(int node, const vector<vector<int>>& adj, vector<bool>& visited, vector<int>& traversal) {
    visited[node] = true;
    traversal.push_back(node);

    for(auto it: adj[node]) {
        if(!visited[it]) {
            dfs(it, adj, visited, traversal);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(n + 1, false);
    int start = 0;
    vector<int> dfs_traversal;
    dfs(start, adj, visited, dfs_traversal);

    for(auto it: dfs_traversal) {
        cout << it << " ";
    }
}