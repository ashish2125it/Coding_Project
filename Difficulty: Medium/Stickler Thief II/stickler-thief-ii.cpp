//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  int solve(int i,int n,vector<int>&arr,vector<int>&dp)
  {
      if(i>=n) return 0;
      if(dp[i]!=-1) return dp[i];
      
      int take  = arr[i] + solve(i+2,n,arr,dp);
      int not_take= solve(i+1,n,arr,dp);
      return dp[i] = max(take,not_take);
  }
    int maxValue(vector<int>& arr) {
     int n = arr.size();
     vector<int>dp1(n+1,-1);
     vector<int>dp2(n+1,-1);
     int ans1= solve(0,n-1,arr,dp1);
     int ans2 = solve(1,n,arr,dp2);
     return max(ans1,ans2);
     
        
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        int res;
        res = ob.maxValue(arr);
        cout << res << "\n"
             << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends