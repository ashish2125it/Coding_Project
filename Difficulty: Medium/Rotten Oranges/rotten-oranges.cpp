//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int orangesRotting(vector<vector<int>>& mat) {
    int n = mat.size(), m = mat[0].size();
    queue<pair<int, int>> q;
    vector<vector<int>> vis(n, vector<int>(m, 0));
    
    int freshCount = 0; // Count of fresh oranges
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 2) {
                q.push({i, j});
                vis[i][j] = 1;
            } else if (mat[i][j] == 1) {
                freshCount++; 
            }
        }
    }
    
    if (freshCount == 0) return 0; 
    
    int time = 0;
    int nrow[] = {-1, 0, 1, 0};
    int ncol[] = {0, 1, 0, -1};
    
    while (!q.empty()) {
        int size = q.size();
        bool changed = false;
        for (int i = 0; i < size; i++) { 
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int x = 0; x < 4; x++) {
                int next_row = row + nrow[x];
                int next_col = col + ncol[x];
                if (next_row >= 0 && next_col >= 0 && next_row < n && next_col < m &&
                    vis[next_row][next_col] == 0 && mat[next_row][next_col] == 1) {
                    
                    vis[next_row][next_col] = 1;
                    q.push({next_row, next_col});
                    freshCount--;
                    changed = true;
                }
            }
        }
        
        if (changed) time++;
    }
    
    return (freshCount == 0) ? time : -1; 
    
        
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        int ans = obj.orangesRotting(mat);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends