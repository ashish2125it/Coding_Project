class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
    int n = arr.size();
    long ans=0;
    unordered_map<int,long>mp;
    
    long x =0;
    mp[0] = 1;
    for(int i=0;i<n;i++)
    {
        x = x^arr[i];
        ans += mp[x^k];
        mp[x]++;
        
        
    }
     return ans;
        
    }
};