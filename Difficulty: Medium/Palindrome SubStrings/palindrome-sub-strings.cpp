//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
  void solve(int start,int end,string &s,int n,int &ans)
  {
      if(start<0 || end>=n ) return ;
      
      if(s[start]==s[end]) 
      {
          if(end-start+1>=2)
          ans++;
          solve(start-1,end+1,s,n,ans);
        
      }
      else
      return ;
  }
    int countPS(string &s) {
    int n = s.length();
    int ans=0;
    for(int i=0;i<n;i++)
    {
    solve(i,i,s,n,ans);  // odd lengrh
    solve(i,i+1,s,n,ans);
    }
    return ans;
    
    
      
      
    
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.countPS(s) << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends