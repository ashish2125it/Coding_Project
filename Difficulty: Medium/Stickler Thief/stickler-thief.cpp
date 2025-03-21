//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;


// } Driver Code Ends

#define ll long long int
class Solution {
  public:
  ll solve(int i,int n,vector<int>&arr,vector<ll>&dp)
  {
      if(i>=n) return 0;
      if(dp[i]!=-1) return dp[i];
      
      ll take = arr[i] + solve(i+2,n,arr,dp);
      ll not_take = solve(i+1,n,arr,dp);
      return dp[i] = max(take,not_take);
  }
    int findMaxSum(vector<int>& arr) {
    int n = arr.size();
    vector<ll>dp(n+1,-1);
    return solve(0,n,arr,dp);
        
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
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.findMaxSum(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends