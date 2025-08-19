class Solution {
  public:
    vector<int> farMin(vector<int>& arr) {
     int n = arr.size();
     vector<int>ans(n,-1);
     
     vector<int>right(n);
     right[n-1] = arr[n-1];
     for(int i=n-2;i>=0;i--)
     right[i] = min(right[i+1],arr[i]);
     
     for(int i=0;i<n;i++)
     {
         int low = i+1, high = n-1;
         int index = -1;
         while(low<=high)
         {
             int mid=  (low+high)/2;
             if(right[mid]<arr[i])
             {
                 index = mid;
                 low = mid+1;
             }
             else
             high = mid-1;
         }
         ans[i] = index;
     }
     
     return ans;
    }
};