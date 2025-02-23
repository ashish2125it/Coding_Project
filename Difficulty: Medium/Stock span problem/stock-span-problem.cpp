//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
    int  n = arr.size();
    vector<int>ans(n,1);
    stack<int>st;
    for(int i=0;i<n;i++)
    {
        while(!st.empty() && arr[i]>=arr[st.top()])
            st.pop();
            
            if(!st.empty())
            ans[i] = i - st.top();
            else
            ans[i] = i+1;
            
            st.push(i);
    
    }
    return ans;
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        vector<int> ans = obj.calculateSpan(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends