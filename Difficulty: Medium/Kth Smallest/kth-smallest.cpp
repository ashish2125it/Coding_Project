// User function template for C++

class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k) {
     set<int>st;
     int n = arr.size();
     for(int i=0;i<n;i++)
     st.insert(arr[i]);
     
     int cnt=0;
     for(auto it:st)
     {
         cnt++;
         if(cnt==k)
         return it;
     }
     
     return -1;
        
    }
};