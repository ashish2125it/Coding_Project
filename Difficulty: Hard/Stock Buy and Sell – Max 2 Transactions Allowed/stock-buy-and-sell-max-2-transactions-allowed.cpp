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
    int maxProfit(vector<int> &prices) {
    // int n = prices.size();
    // int k =2;
    // vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(k+1,vector<int>(2,-1)));
    // int ans =  solve(0,prices,n,k,0,dp);
    // if(ans<=0) return 0;
    // return ans;
    
     int k = 2;  // Maximum 2 transactions allowed
        int n = prices.size();
        
        // Create a 3D DP table
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(k+1, vector<int>(2, 0)));
        
        // Fill the dp table starting from the last day and moving backward
        for (int i = n - 1; i >= 0; i--) { // Traverse backwards from the last day
            for (int remainingTransactions = 1; remainingTransactions <= k; remainingTransactions++) { // Traverse over allowed transactions
                for (int buy = 0; buy <= 1; buy++) { // Buy or sell decision
                    if (buy == 0) { // Option to buy a stock
                        dp[i][remainingTransactions][buy] = max(-prices[i] + dp[i + 1][remainingTransactions][1], 
                                                               dp[i + 1][remainingTransactions][0]);
                    } else { // Option to sell a stock
                        dp[i][remainingTransactions][buy] = max(prices[i] + dp[i + 1][remainingTransactions - 1][0], 
                                                                dp[i + 1][remainingTransactions][1]);
                    }
                }
            }
        }
        
        // The answer will be at dp[0][k][0], which represents the maximum profit
        // starting from day 0, with at most k transactions, and with buying allowed.
        return dp[0][k][0];
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxProfit(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends