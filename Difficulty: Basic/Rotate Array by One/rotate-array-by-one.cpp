// User function Template for C++

class Solution {
  public:
    void rotate(vector<int> &arr) {
    int n = arr.size();
    vector<int>temp;
    temp.push_back(arr[n-1]);
    for(int i=0;i<=n-2;i++)
    temp.push_back(arr[i]);
    
    for(int i=0;i<n;i++)
    arr[i] = temp[i];
        
    }
};