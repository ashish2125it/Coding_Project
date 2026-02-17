class Solution {
  public:
  bool solve(int src,int par,unordered_map<int,vector<int>>&mp,vector<int>&vis)
{
     vis[src] = 1;
     
     for(auto child:mp[src])
     {
         if(!vis[child])
         {
             if(solve(child,src,mp,vis)==true) return true;
         }
         else if(child!=par) return true;
     }
     
     return false;
}
    bool isCycle(int V, vector<vector<int>>& edges) {
     unordered_map<int,vector<int>>mp;
     for(int i=0;i<edges.size();i++)
     {
         int u = edges[i][0];
         int v = edges[i][1];
         mp[u].push_back(v);
         mp[v].push_back(u);
     }
     
     vector<int>vis(V,0);
     bool ans =  false;
     for(int i=0;i<V;i++)
     {
          if(vis[i]==0)
          {
              if(solve(i,-1,mp,vis))return true;
          }
     }
     return false;
     
        
    }
};