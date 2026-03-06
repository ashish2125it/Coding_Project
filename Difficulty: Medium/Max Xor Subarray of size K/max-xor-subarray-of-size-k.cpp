class Solution {
  public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
    int ans=0;
    int xr =0;
    int n = arr.size();
    for(int i=0;i<k;i++)
    xr = xr^arr[i];
    
    
    
    ans = max(ans,xr);
    int old_xr = 0;
    int j=0;
    for(int i=k;i<n;i++)
    {
         xr = xr^arr[i];
         old_xr = old_xr^arr[j];
         j++;
         ans = max(ans,xr^old_xr);
    }
    
    return ans;
        
    }
};