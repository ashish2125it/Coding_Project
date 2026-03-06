#define ll long long
class Solution {
  public:
    int solve(int time,vector<int>&arr , int k)
    {
        int t=time;
        int painter =1;
        
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]<=t)
            {
                t -= arr[i];
            }
            else
            {
                painter++;
                t = time ;
                t -= arr[i];

            }
        }
        
        
        
        if(painter<=k) return 1;
        return 0;
        
    }
    int minTime(vector<int>& arr, int k) {
    int n = arr.size();
    ll low=0;
    ll high =0;
    for(int i=0;i<n;i++)
    {
        low = max(low,1LL*arr[i]);
        high += 1LL*arr[i]; 
    }
    int ans=0;
    while(low<=high)
    {
        ll mid = (low+high)/2;
        if(solve(mid,arr,k))
        {
            ans = mid;
            high = mid-1;
        }
        else
        low = mid+1;
    }
    return ans;
    
    }
};