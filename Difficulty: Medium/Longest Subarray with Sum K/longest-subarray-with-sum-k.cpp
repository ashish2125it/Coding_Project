class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
    int n = arr.size();
    int sum=0;
    map<int,int>mp;
    mp[0] = -1;
    int ans=0;
    
    for(int j=0;j<n;j++)
    {
        sum += arr[j];
        if(mp.find(sum-k)!=mp.end())
        {
            ans = max(ans,j-mp[sum-k]);
        }
        
        if(mp.find(sum)==mp.end())
        mp[sum] = j;
    }
    return ans;
    
    

        
    }
};