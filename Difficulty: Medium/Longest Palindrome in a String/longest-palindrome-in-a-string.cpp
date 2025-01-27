//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
  string ans = ""; // To store the longest palindromic substring
    int len = 0;     // To track the length of the longest palindrome

    void solve(int i, int j, string &s) {
        
        while (i >= 0 && j < s.length() && s[i] == s[j]) {
            if (len < (j - i + 1)) {
                len = j - i + 1;
                ans = s.substr(i, len);
            }
            i--;
            j++;
        }
    }
    string longestPalindrome(string s) {
    int n = s.length();
    for(int i=0;i<n-1;i++)
    {
        solve(i,i,s);
        solve(i,i+1,s);
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
        cout << ob.longestPalindrome(S) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends