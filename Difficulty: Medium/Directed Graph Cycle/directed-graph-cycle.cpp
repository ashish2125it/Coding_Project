class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
  vector<int>ans;
    unordered_map<int,vector<int>>mp;
    vector<int>indegree(V,0);
    for(int i=0;i<edges.size();i++)
    {
         int u = edges[i][0];
        int v=  edges[i][1];
        mp[u].push_back(v);
        indegree[v]++;
    }
    
    queue<int>q;
    for(int i=0;i<V;i++)
    {
         if(indegree[i]==0)
         q.push(i);
    }
    
    while(q.size())
    {
        int size = q.size();
        for(int i=0;i<size;i++)
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto Ne:mp[node])
            {
                indegree[Ne]--;
                if(indegree[Ne]==0)
                q.push(Ne);
            }
        }
    }
    
    return ans.size()!=V;
        
    }
};