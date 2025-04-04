//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    
    bool solve(int node,vector<int>& vis,unordered_map<int,vector<int>>&mp,int par)
    {
        
        vis[node] = 1;
        bool ans = true;
        
        for(auto it:mp[node])
        {
             if(vis[it]==1 && it==par) 
             {
                 ans = false;
                 return ans;
             }
             ans = ans || solve(it,vis,mp,node);
        }
        return ans;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
    int n = edges.size();
    unordered_map<int,vector<int>>adj;
    
    for(int i=0;i<n;i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    
    vector<int>vis(V,0);
    
    return solve(0,vis,adj,-1);
    
    
        
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V, E;
        cin >> V >> E;
        cin.ignore();
        vector<vector<int>> edges;
        for (int i = 1; i <= E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }

        Solution obj;
        bool ans = obj.isCycle(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends