//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  int solve(int i,vector<int>&prices,int n,int k,int buy,vector<vector<vector<int>>>&dp)
  {
      if(i>=n)
      {
          if(k>=0  && buy==0) 
          return 0;
          return -1e9;
      }
      if(dp[i][k][buy]!=-1) return dp[i][k][buy];
      
      
     if(buy==0 && k>0)
     {
         int Buy = -prices[i] + solve(i+1,prices,n,k,1,dp);
         int not_buy =  solve(i+1,prices,n,k,0,dp);
         return dp[i][k][buy] = max(Buy,not_buy);
     }
     else if(k>0)
     {
         int sell = prices[i] + solve(i+1,prices,n,k-1,0,dp);
         int not_sell = solve(i+1,prices,n,k,1,dp);
         return dp[i][k][buy] = max(sell,not_sell);
     }
     return 0;
      
      
      
  }
    int maxProfit(vector<int>& prices, int k) {
    int n = prices.size();
    vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(k+1,vector<int>(2,-1)));
    int ans =  solve(0,prices,n,k,0,dp);
    if(ans<=0) return 0;
    return ans;
        
    }
};


//{ Driver Code Starts.

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        istringstream iss(input);
        vector<int> arr;
        int num;

        // Read integers from the input string
        while (iss >> num) {
            arr.push_back(num);
        }
        int k;
        cin >> k;
        cin.ignore();
        Solution ob;
        cout << ob.maxProfit(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends