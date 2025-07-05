class Solution {
  public:
    int substrCount(string &s, int k) {
    int n = s.length();
    unordered_map<char,int>mp;
    int i=0,j=0;
    int ans=0;
    while(j<n)
    {
        mp[s[j]]++;
        if(j-i+1==k)
        {
            if(mp.size()==k-1)
            ans += 1;
            
            mp[s[i]]--;
            if(mp[s[i]]==0)
            mp.erase(s[i]);
            i++;
        }
        j++;
    }
    
    return ans;
    
    
    
    
    
    }
};