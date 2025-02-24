//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  vector<int> prev_smaller_index(vector<int>&arr,int n)
  {
      stack<int>st;
      vector<int>ans(n,-1);
      for(int i=0;i<n;i++)
      { 
          while(!st.empty() && arr[st.top()] >= arr[i])
          st.pop();
          
          if(!st.empty())
          ans[i] = st.top();
          
          st.push(i);
      }
      
      return ans;
  }
  
    vector<int> next_smaller_index(vector<int>&arr,int n)
  {
      stack<int>st;
      vector<int>ans(n,n);
      for(int i=n-1;i>=0;i--)
      { 
          while(!st.empty() && arr[st.top()] >= arr[i])
          st.pop();
          
          if(!st.empty())
          ans[i] = st.top();
          
          st.push(i);
      }
      
      return ans;
  }
    int getMaxArea(vector<int> &arr) {
    int n= arr.size();
    vector<int>prev_smaller = prev_smaller_index(arr,n);
    vector<int>next_smaller = next_smaller_index(arr,n);
    
    int ans= 0;
    for(int i=0;i<n;i++)
    {
        int height = arr[i];
        int width = (i-prev_smaller[i]) + (next_smaller[i]-i) -1;
        
        ans = max(ans,height*width);
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
        int res = obj.getMaxArea(arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends