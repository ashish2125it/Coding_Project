//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
   void solve(int i, int n, string &s, vector<string> &ans) {
        if (i >= n) {
            ans.push_back(s);
            return;
        }
        
        unordered_set<char> used; // Track characters already used at this position
        for (int j = i; j < n; j++) {
            if (used.find(s[j]) == used.end()) { // Skip duplicate characters
                used.insert(s[j]);
                swap(s[i], s[j]);
                solve(i + 1, n, s, ans);
                swap(s[i], s[j]); // Backtrack
            }
        }
    }
    
    vector<string> findPermutation(string &s) {
        vector<string> ans;
        sort(s.begin(), s.end()); // Sort to handle duplicates properly
        int n = s.length();
        solve(0, n, s, ans);
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
        vector<string> ans = ob.findPermutation(S);
        sort(ans.begin(), ans.end());
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends