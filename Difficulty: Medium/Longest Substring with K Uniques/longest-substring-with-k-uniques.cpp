class Solution {
  public:
    int longestKSubstr(string &s, int k) {
    int n = s.length();
    unordered_map<char,int>mp;
    int i=0,j=0;
    int ans= INT_MIN;
    while(j<n)
    {
        mp[s[j]]++;
        if(mp.size()==k)
        ans = max(ans,j-i+1);
        else if(mp.size()>k)
        {
            while(mp.size()>k)
            {
                mp[s[i]]--;
                if(mp[s[i]]==0)
                mp.erase(s[i]);
                i++;
            }
        }
        j++;
    }
    
    if(ans==INT_MIN) return -1;
    return ans;
    
    
        
    }
};