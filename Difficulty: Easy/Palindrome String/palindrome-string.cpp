class Solution {
  public:
    string Reverse(string &s)
    {
        string rev = "";
        int n = s.length();
        for(int i=n-1;i>=0;i--)
        rev = rev + s[i];
        
        return rev;
    }
    bool isPalindrome(string& s) {
     int n = s.length();
    // string rev = Reverse(s);
    
    // if(s==rev) 
    // return 1;
    
    int i=0,j=n-1;
    while(i<=j)
    {
        if(s[i]==s[j])
        {
            i++;
            j--;
        }
        else
        return 0;
    }
    
    return 1;
        
    }
};