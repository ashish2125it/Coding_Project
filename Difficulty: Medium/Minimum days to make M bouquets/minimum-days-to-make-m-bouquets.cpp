class Solution {
  public:
    int solve(int time,vector<int>&arr,int m,int k)
    {
        int n = arr.size();
        int cnt=0;
        int x = k;
        for(int i=0;i<n;i++)
        {
            if(arr[i]<=time)
            k--;
            
            if(k==0)
            {
                k= x;
                cnt++;
            }
        }
        
        return cnt>=m;
    }
    int minDaysBloom(vector<int>& arr, int k, int m) {
    int n = arr.size();
    if(m*k>n) return -1;
    int low=arr[0],high= arr[0];
    
    for(int i=0;i<n;i++)
    {
        low = min(low,arr[i]);
        high = max(high,arr[i]);
    }
    
    int res =0;
    while(low<=high)
    {
        int mid = (low+high)/2;
        int ans = solve(mid,arr,m,k);
        if(ans)
        {
        res = mid;
        high = mid-1;
        }
        else
        low = mid+1;
    }
    
    return res;
    
    
        
    }
};