class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
   unordered_map<int,vector<int>>gr;
    vector<int>degree(V,0);
    for(int i=0;i<edges.size();i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        degree[v]++;
        gr[edges[i][0]].push_back(edges[i][1]);
    }
    
    
    queue<int>q;
    for(int i=0;i<V;i++)
    {
        if(degree[i]==0)
        q.push(i);
    }
    
    vector<int>ans;
    while(q.size())
    {
        int size = q.size();
        for(int i=0;i<size;i++)
        {
            int node = q.front();
            ans.push_back(node);
            q.pop();
            for(auto ne:gr[node])
            {
                degree[ne]--;
                if(degree[ne]==0)
                q.push(ne);
            }
        }
    }
    
    return ans.size()!=V;
    
        
    }
};