class Solution {
  public:
    int catchThieves(vector<char> &arr, int k) {
    int n = arr.size();
    int i=0,j=0;
    int cnt=0;
    while(i<n && j<n)
    {
        while(j<n && arr[j]=='T') j++;
        while(i<n && arr[i]=='P') i++;
        
        if(i<n && j<n && abs(i-j)<=k)
        {
            cnt++;
            i++;
            j++;
        }
        else if( i<n && j<n && j>i)
        i++;
        else if(j<n && i<n && i>j)
        j++;
    }
    
    return cnt;
    
        
    }
};