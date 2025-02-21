//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxLength(string& s) {
    int n = s.length();
    int ans= 0;
    int open =0,close=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='(') open++;
        else
        close++;
        
        if(close>open)
        {
            open =0;
            close=0;
        }
        else if(open==close)
        ans= max(ans,2*open);
    }
    
    open =0,close=0;
    for(int i=n-1;i>=0;i--)
    {
         if(s[i]=='(') open++;
        else
        close++;
        
        if(close<open)
        {
            open =0;
            close=0;
        }
        else if(open==close)
        ans= max(ans,2*open);
    }
    return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.maxLength(S) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends