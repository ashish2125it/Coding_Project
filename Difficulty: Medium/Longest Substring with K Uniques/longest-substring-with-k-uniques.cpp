class Solution {
  public:
    int longestKSubstr(string &s, int k) {
     int n = s.length();
     unordered_map<char,int>mp;
     int ans=-1,j=0,i=0;
     while(j<n)
     {
         mp[s[j]]++;
         while(mp.size()>k)
         {
             mp[s[i]]--;
             if(mp[s[i]]==0)
             mp.erase(s[i]);
             i++;
         }
         if(mp.size()==k)
         ans =max(ans,j-i+1);
         j++;
     }
     
     return ans;
        
    }
};