//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  int solve(int i,int n,vector<int>&arr,int sum,int target,vector<vector<int>>&dp)
  {
      if(sum==target) return 1;
      if(i>=n) return 0;
      if(dp[i][sum]!=-1) return dp[i][sum]; 
      
      int case1=0;
      if(sum+arr[i]<=target)
       case1 = solve(i+1,n,arr,sum+arr[i],target,dp);
      int case2 = solve(i+1,n,arr,sum,target,dp);
      
      return dp[i][sum] =  case1 || case2;
      
  }
    bool isSubsetSum(vector<int>& arr, int sum) {
    int n = arr.size();
    vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
    return solve(0,n,arr,0,sum,dp);
        
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
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends