//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  int solve(int i,vector<int>&arr,int n,int sum,vector<vector<int>>&dp )
  {
      if(sum==0) return 1;
      if(i>=n) return 0;
      if(dp[i][sum]!=-1) return dp[i][sum];
      
      
      int case1= 0;
      if(sum>=arr[i])
      case1 = solve(i+1,arr,n,sum-arr[i],dp);
     int case2 = solve(i+1,arr,n,sum,dp);
     
     return dp[i][sum] = (case1 || case2); 
      
  }
    bool equalPartition(vector<int>& arr) {
    int n = arr.size();
    int sum=0;
    for(auto it:arr) sum += it;
    if(sum%2!=0) return 0;
    
    vector<vector<int>>dp(n+1,vector<int>((sum/2)+1,-1));
    return solve(0,arr,n,sum/2,dp);
    
        
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
        if (ob.equalPartition(arr))
            cout << "true\n";
        else
            cout << "false\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends