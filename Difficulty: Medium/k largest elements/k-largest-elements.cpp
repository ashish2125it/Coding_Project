//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> kLargest(vector<int>& arr, int k) {
    vector<int>ans;
    int n = arr.size();
    priority_queue<int,vector<int>,greater<int>>q;
    for(int i=0;i<k;i++)
    q.push(arr[i]);
    
    for(int i=k;i<n;i++)
    {
        if(!q.empty() && arr[i]> q.top())
        {
            q.pop();
            q.push(arr[i]);
        }
    }
    
    while(q.size())
    {
        ans.push_back(q.top());
        q.pop();
    }
    
    reverse(ans.begin(),ans.end());
    
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
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        vector<int> ans = ob.kLargest(arr, k);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends