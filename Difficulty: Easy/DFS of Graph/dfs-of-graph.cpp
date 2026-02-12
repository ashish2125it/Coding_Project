class Solution {
  public: 
    void dfs(int src,vector<int>&vis,unordered_map<int,vector<int>>&mp,vector<int>&ans)
    {
        vis[src] = 1;
        ans.push_back(src);
        for(auto it:mp[src])
        {
            if(vis[it]==0)
            dfs(it,vis,mp,ans);
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
    vector<int>ans;
    unordered_map<int,vector<int>>mp;
    for(int i=0;i<adj.size();i++)
    {
        for(int j=0;j<adj[i].size();j++)
        {
            mp[i].push_back(adj[i][j]);
            mp[adj[i][j]].push_back(i);
        }
    }
    vector<int>vis(adj.size()+1,0);
    dfs(0,vis,mp,ans);
    return ans;
    }
};