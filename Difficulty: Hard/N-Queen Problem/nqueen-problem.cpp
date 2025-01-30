//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  bool is_safe(int row,int col,int n,vector<vector<int>>&grid)
  {
      // check same row,same 
      int r = row;
      int c = col;
      
      while(r>=0)
      {
          if(grid[r][c]==1) return false;
          r--;
      }
      r = row;
      
      // check same col
     
      while(c>=0)
      {
          if(grid[r][c]==1) return false;
          c--;
      }
      
      r = row;
      c = col;
      
      // check left daigonal
      while(r>=0 && c>=0)
      {
          if(grid[r][c]==1) return false;
          r--;
          c--;
      }
      
      r = row;
      c= col;
      while(r>=0 && c<n)
      {
          if(grid[r][c]==1) return false;
          c++;
          r--;
      }
      
      return true;
  }
  void solve(int i,int n,vector<int>&temp,vector<vector<int>>&ans,vector<vector<int>>&grid)
  {
      if(i>=n)
      {
          if(temp.size()==n)
          ans.push_back(temp);
          return ;
      }
      
      for(int j=0;j<n;j++)
      {
          if(is_safe(i,j,n,grid))
          {
              temp.push_back(j+1);
              grid[i][j] = 1;
              solve(i+1,n,temp,ans,grid);
              grid[i][j] = 0;
              temp.pop_back();
             // solve(i+1,n,temp,ans,grid);
          }
          

      }
  }
    vector<vector<int>> nQueen(int n) {
     vector<vector<int>>ans;
     vector<int>temp;
     vector<vector<int>>grid(n,vector<int>(n,0));
     solve(0,n,temp,ans,grid);
     return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if (ans.size() == 0)
            cout << -1 << "\n";
        else {
            sort(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); i++) {
                cout << "[";
                for (int u : ans[i])
                    cout << u << " ";
                cout << "] ";
            }
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends