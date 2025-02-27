//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int evaluate(vector<string>& arr) {
         stack<int> st;
        int n = arr.size();
        
        for(int i = 0;i<n;i++)
        {
            if((arr[i] != "+")&&(arr[i] != "-")&&(arr[i] != "*")&&(arr[i] != "/"))
            {
                int x = stoi(arr[i]);
                st.push(x);
            }
            else
            {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                int y;
                if(arr[i] == "+")
                {y = a + b;}
                else if(arr[i] == "-")
                {y = b-a;}
                else if(arr[i] == "*")
                {y = a * b;}
                else
                {y = b/a;}
                st.push(y);
            }
        }
        return st.top();

    }
};


//{ Driver Code Starts.

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        vector<string> arr;
        while (ss >> str) {
            arr.push_back(str);
        }
        Solution ob;
        cout << ob.evaluate(arr) << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends