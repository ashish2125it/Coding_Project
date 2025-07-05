class Solution {
  public:
  
  bool check(string &s)
  {
      int i=0,j=s.length()-1;
      while(i<=j)
      {
          if(s[i]!=s[j]) return false;
          i++;
          j--;
      }
      return true;
  }
    void solve(int i,string &s,vector<vector<string>>&ans,vector<string>temp,int n)
    {
        if(i>=n)
        {
            if(temp.size()>=1)
            ans.push_back(temp);
            return ;
        }
        
        
        string st = "";
        for(int j=i;j<n;j++)
        {
            st += s[j];
            if(check(st))
            {
                temp.push_back(st);
                solve(j+1,s,ans,temp,n);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> palinParts(string &s) {
    vector<vector<string>>ans;
    vector<string>temp;
    int n = s.length();
    solve(0,s,ans,temp,n);
    return ans;
    
    
        
    }
};