//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  int solve(int start,int end,vector<int>&dp)
  {
      if(start==end) return 1;
      if(start>end) return 0;
      if(dp[start]!=-1) return dp[start];
      
      return dp[start] = solve(start+1,end,dp) + solve(start+2,end,dp);
      
      
  }
    int countWays(int n) {
     vector<int>dp(n+1,-1);
    return solve(0,n,dp);
        
    }
};



//{ Driver Code Starts.
int main() {
    // taking total testcases
    int t;
    cin >> t;
    while (t--) {
        // taking stair count
        int m;
        cin >> m;
        Solution ob;
        cout << ob.countWays(m) << endl; // Print the output from our pre computed array

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends