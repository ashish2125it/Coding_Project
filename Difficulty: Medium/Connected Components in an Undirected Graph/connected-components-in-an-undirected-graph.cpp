class Solution {
  public:
   void solve(int src,vector<int>&vis,unordered_map<int,vector<int>>&mp,vector<int>&ans)
    {
          vis[src] = 1;
          ans.push_back(src);
          
          vector<int>ne = mp[src];
          for(int j=0;j<ne.size();j++)
          {
              if(vis[ne[j]]==0)
              {
                  solve(ne[j],vis,mp,ans);
              }
          }
          
    }
    
    
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
     vector<vector<int>>ans;
     
     vector<int>vis(V,0);
     
     unordered_map<int,vector<int>>mp;
     for(int i=0;i<edges.size();i++)
     {
         int src = edges[i][0];
         int dest = edges[i][1];
         
         mp[src].push_back(dest);
          mp[dest].push_back(src);
         
     }
     for(int i=0;i<V;i++)
     {
         if(vis[i]==0)
         {
             vector<int>temp;
             solve(i,vis,mp,temp);
             ans.push_back(temp);
         }
     }
     return ans;
     
        
    }
};
