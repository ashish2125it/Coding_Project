class Solution {
  public:
    int solve(int i,int open, int close,int n)
    {
        if(i==n)
        {
            if(open==close) return 1;
            return 0;
        }
        
        int c2=0;
        int c1 = solve(i+1,open+1,close,n);
        if(open>close)
        c2 = solve(i+1,open,close+1,n);
        
        return c1 + c2;
    }
    int findWays(int n) {
    return solve(0,0,0,n);
        
    }
};