class Solution {
public:
    int countPaths(int V, vector<vector<int>>& e) {
        
        unordered_map<int, vector<pair<int,int>>> mp;
        
        // Build graph
        for (int i = 0; i < e.size(); i++) {
            mp[e[i][0]].push_back({e[i][1], e[i][2]});
            mp[e[i][1]].push_back({e[i][0], e[i][2]});
        }
        
        // Min heap (distance, node)
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        vector<long long> dist(V, LLONG_MAX);
        vector<int> ways(V, 0);
        
        dist[0] = 0;
        ways[0] = 1;
        
        pq.push({0, 0});
        
        int mod = 1e9 + 7;
        
        while (!pq.empty()) {
            auto [distance, node] = pq.top();
            pq.pop();
            
            if (distance > dist[node]) continue;
            
            for (auto &it : mp[node]) {
                int ne = it.first;
                int d = it.second;
                
                long long new_distance = distance + d;
                
                if (new_distance < dist[ne]) {
                    dist[ne] = new_distance;
                    pq.push({new_distance, ne});
                    ways[ne] = ways[node];
                }
                else if (new_distance == dist[ne]) {
                    ways[ne] = (ways[ne] + ways[node]) % mod;
                }
            }
        }
        
        return ways[V - 1] % mod;
    }
};