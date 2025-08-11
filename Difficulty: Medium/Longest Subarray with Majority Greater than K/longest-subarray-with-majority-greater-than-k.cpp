class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
    int n = arr.size();
    int ans = 0;
    int sum =0;
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>k)
        sum++;
        else
        sum--;
        
        if(sum>0)
        ans=  max(ans,i+1);
        
        if(mp.find(sum)==mp.end())
        mp[sum] = i;
        
        if(mp.find(sum-1)!=mp.end())
        ans= max(ans,i-mp[sum-1]);
    }
        
        return ans;
    }
};