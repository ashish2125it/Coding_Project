class Solution {
  public:
    bool canFinish(int n, vector<vector<int>>& pre) {
    vector<int>topo;
    vector<int>indegree(n,0);
    queue<int>q;
    unordered_map<int,vector<int>>mp;
    for(int i=0;i<pre.size();i++)
    {
       int x = pre[i][0];
       int y = pre[i][1];
       mp[x].push_back(y);
       indegree[y]++;
    }
    
    for(int i=0;i<n;i++)
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
            topo.push_back(node);
            q.pop();
            
            for(auto it:mp[node])
            {
                indegree[it]--;
                if(indegree[it]==0)
                q.push(it);
            }
        }
    }
    
    
    
    if(topo.size()==n) return 1;
    return 0;
        
    }
};