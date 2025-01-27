//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int characterReplacement(string& s, int k) {
    int n = s.length();
    int ans= 0;
    map<char,int>mp;
    int j=0,i=0;
    int max_f= 0;
    while(j<n)
    {
        mp[s[j]]++;
        max_f =max(max_f,mp[s[j]]);
        
        int changes = (j-i+1) - max_f;
        while( ((j-i+1) - max_f)>k)
        {
            mp[s[i]]--;
            if(mp[s[i]]==0)
            mp.erase(s[i]);
            max_f= 0;
            for(auto it:mp)
            {
                 max_f = max(max_f,it.second);
            }
            i++;
        }
        ans = max(ans,j-i+1);
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
        string S;
        cin >> S;
        int K;
        cin >> K;

        Solution obj;
        cout << obj.characterReplacement(S, K) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends