class Solution {
  public:
    int searchInsertK(vector<int> &arr, int k) {
    int ans=0;
    int n = arr.size();
    for(int i=0;i<n;i++)
    {
        if(arr[i]==k)
        return i;
        if(arr[i]<k)
        ans = i+1;
    }
    return ans;
    }
};