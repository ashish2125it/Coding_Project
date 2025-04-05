//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
 private:
 void solve(vector<vector<char>>& grid,int i,int j,vector<vector<int>>&vis,int n,int m)
 {
     queue<pair<int,int>>q;
     q.push({i,j});
     vis[i][j] = 1;
     int nrow[] = {-1, 1, 0, 0, -1, -1, 1, 1}; 
     int ncol[] = {0, 0, -1, 1, -1, 1, -1, 1}; 

     while(q.size())
     {
         
         int size= q.size();
         for(int c=0;c<size;c++)
         {
            int row = q.front().first;
             int col = q.front().second;
             q.pop();     
         for(int x=0;x<8;x++)
         {
            
             int next_row = row + nrow[x];
             int next_col = col + ncol[x];
             if(next_row>=0 && next_col>=0 && next_row<n && next_col<m && grid[next_row][next_col]=='L' && vis[next_row][next_col]==0 )
             {
                 vis[next_row][next_col] = 1;
                 q.push({next_row,next_col});
             }
         }
         }
     }
 }
    
  public:
    int countIslands(vector<vector<char>>& grid) {
    int n = grid.size(),m = grid[0].size();
    int cnt=0;
    vector<vector<int>>vis(n,vector<int>(m,0));
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]=='L' && vis[i][j]==0)
            {
                cnt++;
                solve(grid,i,j,vis,n,m);
            }
        }
    }
    
    return cnt;
        
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.countIslands(grid);
        cout << ans << '\n';

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends