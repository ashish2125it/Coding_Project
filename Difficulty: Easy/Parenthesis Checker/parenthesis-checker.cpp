//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isBalanced(string& s) {
    int n = s.length();
    stack<char>st;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='(' || s[i]=='[' || s[i]=='{')
        {
             st.push(s[i]);
        }
        else
        {
            if(s[i]==')')
            {
                if(st.size()==0) return 0;
                if(st.top()=='(')
                st.pop();
                else
                return 0;
            }
            else if(s[i]=='}')
            {
                if(st.size()==0) return 0;
                if(st.top()=='{')
                st.pop();
                else
                return 0;
            }
            else if(s[i]==']')
            {
                if(st.size()==0) return 0;
                if(st.top()=='[')
                st.pop();
                else
                return 0;
            }
        }
    }
    if(st.size()==0) return 1;
    return 0;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    string a;
    cin >> t;
    while (t--) {
        cin >> a;
        Solution obj;
        if (obj.isBalanced(a))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends