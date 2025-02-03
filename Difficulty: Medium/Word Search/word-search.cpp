//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
  bool solve(int i1,int j1,int i,vector<vector<char>>& mat,int n,int m,string &word,vector<vector<int>>&vis)
  {
       if(i>=word.length())
       return 1;
       
       if(i1>=n ||i1<0 || j1>=m || j1<0 || vis[i1][j1]==1 || mat[i1][j1]!=word[i])
       return 0;
       
       
       bool ans = false;
       vis[i1][j1] =1 ;
       int nrow[] = {-1,0,1,0};
       int ncol[] = {0,1,0,-1};
       for(int x=0;x<4;x++)
       {
           int next_row = i1 + nrow[x];
           int next_col = j1 + ncol[x];
           
           ans = ans || solve(next_row,next_col,i+1,mat,n,m,word,vis);
           if(ans) return 1;
       }
       vis[i1][j1] =0;
       return ans;
  }
    bool isWordExist(vector<vector<char>>& mat, string& word) {
    int n = mat.size(),m = mat[0].size();
    vector<vector<int>>vis(n,vector<int>(m,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(mat[i][j]==word[0])
            {
                if(solve(i,j,0,mat,n,m,word,vis)) return 1;
            }
        }
    }
    return 0;
    
    
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> mat(n, vector<char>(m, '*'));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];
        string word;
        cin >> word;
        Solution obj;
        bool ans = obj.isWordExist(mat, word);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends