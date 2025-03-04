//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    // int solve(int index,int a[],int n,int lastIndex,vector<vector<int>>&dp)
    // {
    //     if(index==n)
    //     {
    //       return 0;
    //     }
    //     if(dp[index][lastIndex+1] != -1) return dp[index][lastIndex+1] ;
        
    //     int pick =0;
    //     if( lastIndex == -1 || a[index] > a[lastIndex] )
    //     pick = 1 + solve(index+1,a,n,index,dp);
    //     int notpick = solve(index+1,a,n,lastIndex,dp);
    //     return dp[index][lastIndex+1] = max(pick,notpick );
    // }
    int lis(vector<int>&a)
    {
       // vector<vector<int>>dp(n,vector<int>(n+1,-1));
      //   vector<vector<int>>dp(n+1,vector<int>(n+1,0));
      // return solve(0,a,n,-1,dp);
      int n = a.size();
      vector<int>curr(n+1,0),next(n+1,0);
      
      for(int index = n-1;index>=0;index--)
      {
          for(int lastIndex = index-1;lastIndex>=-1;lastIndex--)
          {
               int pick =0;
        if( lastIndex == -1 || a[index] > a[lastIndex] )
        pick = 1 + next[index+1];
        int notpick = next[lastIndex+1];
        curr[lastIndex+1] = max(pick,notpick );
          }
          next = curr;
      }
      return next[0];
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input

    while (t--) {
        int n;
        vector<int> arr;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            arr.push_back(num);

        Solution obj;
        cout << obj.lis(arr) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends