class Solution {
  public:
    void solve(int src,vector<int>&vis,vector<vector<int>>&adj,vector<int>&ans)
    {
          vis[src] = 1;
          ans.push_back(src);
          
          vector<int>ne = adj[src];
          for(int j=0;j<ne.size();j++)
          {
              if(vis[ne[j]]==0)
              {
                  solve(ne[j],vis,adj,ans);
              }
          }
          
    }
    vector<int> dfs(vector<vector<int>>& adj) {
    
    unordered_map<int,vector<int>>mp;
    // for(int i=0;i<adj.size();i++)
    // {
    //     for(int j=0;j<adj[i].size();j++)
    //     {
    //         int src = i;
    //         int dest = adj[i][j];
    //         mp[src].push_back(dest);
    //         mp[dest].push_back(src);
            
    //     }
        vector<int>vis(adj.size());
        vector<int>ans;
        solve(0,vis,adj,ans);
        return ans;
    
        
    }
};