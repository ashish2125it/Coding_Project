class Solution {
public:
    void dfs(int src, vector<int>& vis, vector<int>& temp,
             unordered_map<int, vector<int>>& mp)
    {
        vis[src] = 1;
        temp.push_back(src);

        for (auto it : mp[src])
        {
            if (vis[it] == 0)
                dfs(it, vis, temp, mp);
        }
    }

    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) 
    {
        vector<vector<int>> ans;
        unordered_map<int, vector<int>> mp;

        // Build adjacency list
        for (int i = 0; i < edges.size(); i++)
        {
            mp[edges[i][0]].push_back(edges[i][1]);
            mp[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int> vis(V, 0);

        for (int i = 0; i < V; i++)
        {
            if (vis[i] == 0)
            {
                vector<int> temp;
                dfs(i, vis, temp, mp);

                sort(temp.begin(), temp.end());   // 🔥 sort component
                ans.push_back(temp);
            }
        }

        sort(ans.begin(), ans.end());   // 🔥 sort all components

        return ans;
    }
};
