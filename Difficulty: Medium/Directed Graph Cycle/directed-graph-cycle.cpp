//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool solve(int node,unordered_map<int,vector<int>>&mp,vector<int>&vis,vector<int>&path_vis)
    {
        
        
        bool ans= false;
        for(auto it:mp[node])
        {
            if(vis[it]==1 && path_vis[it]==1) return 1;
            vis[it]= 1;
            path_vis[it] = 1;
            ans = ans || solve(it,mp,vis,path_vis);
            path_vis[it] =0;
        }
        
        return ans;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
    int n = edges.size();
    unordered_map<int,vector<int>>mp;
    
    for(auto it:edges)
    mp[it[0]].push_back(it[1]);
    
    vector<int>vis(V,0);
    vector<int>path_vis(V,0);
   
    for(int i=0;i<V;i++)
    {
        if(vis[i]==0)
        {
            if(solve(i,mp,vis,path_vis)) return 1;
        }
    }
    
    return 0;
    
        
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
        bool ans = obj.isCyclic(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";
    }
    return 0;
}
// } Driver Code Ends