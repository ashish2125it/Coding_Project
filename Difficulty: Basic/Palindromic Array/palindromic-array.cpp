/*Complete the function below*/

class Solution {
  public:
    bool solve(string &s,int n)
    {
        int i=0,j=n-1;
        while(i<=j)
        {
            if(s[i]!=s[j]) return 0;
            i++;
            j--;
        }
        
        return 1;
    }
    bool isPalinArray(vector<int> &arr) {
    int n = arr.size();
    
    for(int i=0;i<n;i++)
    {
        string t = to_string(arr[i]);
       // cout<<t<<" ";
        if(solve(t,t.length())==false)
        return 0;
        
    }
    
    return 1;
        
    }
};