//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
  bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
    map<int,vector<int>> adj;
    for (auto &e : edges) {
        int u = e[0];
        int v = e[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Remove the edge (c, d) and (d, c)
    adj[c].erase(remove(adj[c].begin(), adj[c].end(), d), adj[c].end());
    adj[d].erase(remove(adj[d].begin(), adj[d].end(), c), adj[d].end());

    vector<int> vis(V, 0);
    return !dfs(c, d, adj, vis);  // if d is not reachable from c -> bridge
}

bool dfs(int u, int target, map<int,vector<int>>& adj, vector<int>& vis) {
    if (u == target) return true;
    vis[u] = 1;
    for (int v : adj[u]) {
        if (!vis[v]) {
            if (dfs(v, target, adj, vis)) return true;
        }
    }
    return false;
}

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        vector<vector<int>> edges(E);
        int i = 0;
        while (i++ < E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            edges[i - 1].push_back(u);
            edges[i - 1].push_back(v);
        }

        int c, d;
        cin >> c >> d;

        Solution obj;
        bool l = obj.isBridge(V, edges, c, d);
        if (l)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends