#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(int n, vector<vector<int>>& adj) {
  int vis[n+1] = {0};
  vis[0] = 1;
  queue<int> q;
  q.push(1);
  vector<int> bfs_traversal;

  while(!q.empty()) {
    int node = q.front();
    q.pop();
    bfs_traversal.push_back(node);

    for(auto it: adj[node]) {
      if(!vis[it]) {
        vis[it] = 1;
        q.push(it);
      }
    }
  }

  return bfs_traversal;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n + 1);

  for(int i=0; i<m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int> result = bfs(n, adj);
  for(int i : result) {
    cout << i << " ";
  }
  cout << endl;
}