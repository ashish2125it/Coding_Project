class Solution {
  public:
    // Function to find equilibrium point in the array.
    int findEquilibrium(vector<int> &arr) {
    int n = arr.size();
    long long tot_sum=0,left =0;
    for(int i=0;i<n;i++)
    tot_sum += arr[i];
    
    for(int i=0;i<n;i++)
    {
        long long right = tot_sum -left -arr[i];
        if(left==right) 
        return i;
        
        left+= arr[i];
    }
    return -1;
        
    }
};