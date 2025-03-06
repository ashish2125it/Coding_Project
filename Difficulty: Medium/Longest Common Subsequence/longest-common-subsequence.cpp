//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int solve(int i,int j,string &s1,string &s2,int n,int m,vector<vector<int>>&dp)
    {
        if(i>=n || j>=m) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        
        
        int op1=0,op2=0;
        if(s1[i]==s2[j])
        {
            op1 = 1 + solve(i+1,j+1,s1,s2,n,m,dp);
        }
        else
        {
            op1 = solve(i+1,j,s1,s2,n,m,dp);
            op2 = solve(i,j+1,s1,s2,n,m,dp);
        }
        
        return dp[i][j] =  max(op1,op2);
        
        
        
    }
    int lcs(string &s1, string &s2) {
     int n = s1.length(), m = s2.length();
     vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
     return solve(0,0,s1,s2,n,m,dp);
        
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2; // Take both the strings as input
        Solution ob;
        cout << ob.lcs(s1, s2) << endl; // Call the lcs function
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends