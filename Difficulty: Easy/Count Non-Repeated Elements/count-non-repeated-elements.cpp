class Solution {
  public:
    int countNonRepeated(vector<int>& arr) {
    int n = arr.size();
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++)
    mp[arr[i]]++;
    
    int cnt=0;
    for(auto it:mp)
    {
        int element = it.first;
        int freq = it.second;
        if(freq==1)
        cnt++;
    }
    
    return cnt;
        
    }
};