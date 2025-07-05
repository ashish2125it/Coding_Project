class Solution {
  public:
    int totalElements(vector<int> &arr) {
    int k=2;
    int ans=0;
    int n = arr.size();
    
    unordered_map<int,int>mp;
    int i=0,j=0;
    while(j<n)
    {
        mp[arr[j]]++;
        if(mp.size()>k)
        {
            while(mp.size()>k)
            {
                mp[arr[i]]--;
                if(mp[arr[i]]==0)
                mp.erase(arr[i]);
                i++;
            }
        }
        
        ans = max(ans,j-i+1);
        j++;
    }
    
    return ans;
        
    }
};