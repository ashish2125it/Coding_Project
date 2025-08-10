class Solution {
  public:
    
    void solve(int i,int j,string &s,int &cnt)
    {
        if(i<0 || j>=s.length()) return ;
        
        if(s[i]==s[j])
        {
            if(j-i+1>=2)
            {
                cnt++;
                
            }
            solve(i-1,j+1,s,cnt);
        }
        else
        return ;
    }
    int countPS(string &s) {
    int n = s.length();
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        solve(i,i,s,cnt);
        solve(i,i+1,s,cnt);
    }
    
    
    return cnt;
        
    }
};