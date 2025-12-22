// User function template for C++
class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
    int n = arr.size(),m = arr[0].size();
    int index= -1;
    int max_one=0;
    for(int i=0;i<n;i++)
    {
        int one= 0;
        for(int j=0;j<m;j++)
        {
            if(arr[i][j]==1)
            one++;
        }
        if(max_one<one)
        {
            max_one = one;
            index = i;
        }
    }
    
    return index;
    
        
    }
};