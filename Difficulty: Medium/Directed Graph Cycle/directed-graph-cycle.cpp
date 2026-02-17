class Solution {
  public:
   
    bool solve(int src,vector<int>&vis,vector<int>&path_vis,unordered_map<int,vector<int>>&mp)
    {
        vis[src] = 1;
        path_vis[src] = 1 ;
        
        for(auto child:mp[src])
        {
            
            if(vis[child] && path_vis[child])
            return true;
            
            if(solve(child,vis,path_vis,mp)) return true;
            
            
        }
        
        path_vis[src] = 0;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
    vector<int>vis(V,0);
    vector<int>path_vis(V,0);
    int n = edges.size();
    unordered_map<int,vector<int>>mp;
    for(int i=0;i<n;i++)
    {
        int u  = edges[i][0];
        int v = edges[i][1];
        mp[u].push_back(v);
    }
    
    for(int i=0;i<V;i++)
    {
        if(vis[i]==0)
        {
            if(solve(i,vis,path_vis,mp)) return true;
        }
    }
    return false;
        
    }
};