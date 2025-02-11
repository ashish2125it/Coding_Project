//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestUniqueSubstr(string &s) {
    
    int n = s.length();
    int i=0,j=0;
    map<char,int>mp;
    int ans= 0;
    while(j<n)
    {
        if(mp.find(s[j])!=mp.end())
        {
            int index = mp[s[j]];
            
            while(i<=index)
            {
               mp.erase(s[i]);
               i++;
            }
            
        }
        
        ans = max(ans,j-i+1);
        mp[s[j]] = j;
        j++;
    }
    return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        Solution obj;
        string s;
        cin >> s;
        cout << obj.longestUniqueSubstr(s) << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends