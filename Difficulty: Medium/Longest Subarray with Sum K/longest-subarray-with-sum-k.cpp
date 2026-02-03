class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
    int n = arr.size();
    int sum=0;
    unordered_map<int,int>mp;
    int i=0,j=0;
    int ans=0;
    mp[0]= -1;
    while(j<n)
    {
        sum+=arr[j];
        if(mp.find(sum-k)!=mp.end())
        ans = max(ans,j-mp[sum-k]);
        
        if(mp.find(sum)==mp.end())
        mp[sum] = j;
        j++;
    }
    return ans;
        
    }
};