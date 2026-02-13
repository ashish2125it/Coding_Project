class Solution {
  public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<pair<int, int>>&e )
    {
    vector<vector<int>>ans(V);
    
    for(int i=0;i<e.size();i++)
    {
        int src = e[i].first;
        int dest = e[i].second;
        ans[src].push_back(dest);
        ans[dest].push_back(src);
    }
    return ans;
    
        
    }
};