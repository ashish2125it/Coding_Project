//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    string decodedString(string &s) {
    int n = s.length();
    string curr_str = "";
    
    stack<string>st;
    stack<int>number;
    int num =0;
    
    for(int i=0;i<n;i++)
    {
        if(s[i]=='[')
        {
            st.push(curr_str);
            number.push(num);
            num =0 ;
            curr_str = "";
        }
        else if(s[i]==']')
        {
            string prev = st.top();
            int prev_num = number.top();
            st.pop();
            number.pop();
            
            for(int k=0;k<prev_num;k++)
            {
                prev += curr_str;
            }
            
            curr_str = prev;
        }
        else if(s[i]>='a' && s[i]<='z')
        {
            curr_str += s[i];
        }
        else if(s[i]>='0' && s[i]<='9')
        {
            num = num*10 + (s[i]-'0');
        }
    }
    
 
    return curr_str;
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
        cout << ob.decodedString(s) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends