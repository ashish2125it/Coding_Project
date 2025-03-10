//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to compute the edit distance between two strings
    int solve(int i,int j,string &s1,string &s2,int n1,int n2,vector<vector<int>>&dp)
    {
        if (i == n1) return n2 - j; // Insert remaining characters of s2
        if (j == n2) return n1 - i; // Remove remaining characters of s1
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        
        int opt1=1e18,opt2=1e18,opt3=1e18;
        if(s1[i]==s2[j])
        opt1 = solve(i+1,j+1,s1,s2,n1,n2,dp);
        else
        {
            // insert 
            opt1 = 1 + solve(i,j+1,s1,s2,n1,n2,dp);
            // remove
            opt2= 1 + solve(i+1,j,s1,s2,n1,n2,dp);
            // replace
            opt3 = 1 + solve(i+1,j+1,s1,s2,n1,n2,dp);
        }
        
        
        return dp[i][j] = min( min(opt1,opt2) , opt3 );
        
    }
    int editDistance(string& s1, string& s2) {
    int n1 = s1.length(),n2 = s2.length();
    vector<vector<int>>dp(n1+1,vector<int>(n2+1,-1));
    int ans= solve(0,0,s1,s2,n1,n2,dp);
    if(ans>=1e18) return 0;
    return ans;
    
    }
};


//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        string s1;
        getline(cin, s1);
        string s2;
        getline(cin, s2);
        Solution ob;
        int ans = ob.editDistance(s1, s2);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends