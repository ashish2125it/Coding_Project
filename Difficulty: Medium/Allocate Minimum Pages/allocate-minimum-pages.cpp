#define ll long long
class Solution {
  public:
    bool solve(ll pages,vector<int>&arr,int student)
    {
        int n = arr.size();
        int page = arr[0];
        int s=1;
        for(int i=1;i<n;i++)
        {
            if(page + arr[i]<=pages)
            {
                page += arr[i];
            }
            else
            {
                s++;
                page = arr[i];
            }
        }
        
        if(s<=student) return 1;
        return 0;
    }
    int findPages(vector<int> &arr, int k) {
    int n = arr.size();
    if(k>n) return -1;
    // k students 
    // arr[i] -> number of pages
    
    int  low=0;
    ll high =0;
    for(int i=0;i<n;i++)
    {
        low = max(low,arr[i]);
        high += arr[i];
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