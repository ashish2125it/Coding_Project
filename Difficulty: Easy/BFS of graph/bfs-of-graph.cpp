//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
    vector<int>ans;
    int n = adj.size();
    vector<int>vis(n,0);
    vis[0] = 1;
    queue<int>q;
    q.push(0);
    while(q.size())
    {
        
        int size = q.size();
        for(int i=0;i<size;i++)
        {
            int front = q.front();
            q.pop();
            ans.push_back(front);
           
            for(int j=0;j<adj[front].size();j++)
            {
                if(vis[adj[front][j]]==0)
                {
                    q.push(adj[front][j]);
                    vis[adj[front][j]] = 1;
                }
            }
        }
    }
    
    return ans;
        
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V;
        cin >> V;
        cin.ignore();
        // Use vector of vectors instead of array of vectors.
        vector<vector<int>> adj(V);

        for (int i = 0; i < V; i++) {
            string input;
            getline(cin, input);
            int num;
            vector<int> node;
            stringstream ss(input);
            while (ss >> num) {
                node.push_back(num);
            }
            adj[i] = node;
        }

        Solution obj;
        vector<int> ans = obj.bfs(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends