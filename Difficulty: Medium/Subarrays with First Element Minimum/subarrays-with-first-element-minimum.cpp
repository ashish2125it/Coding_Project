class Solution {
  public:
    vector<int> next_greater(vector<int>& arr,int n)
    {
        stack<int>st;
        vector<int>ans(n,n);
        for(int i=n-1;i>=0;i--)
        {
            if(st.empty())
            st.push(i);
            else
            {
                while(!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
                
                if(!st.empty())
                ans[i] = st.top();
                
                st.push(i);
            }
        }
        
        return ans;
    }
    int countSubarrays(vector<int> &arr) {
    int n = arr.size();
    vector<int>next = next_greater(arr,n);
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int next_ind = next[i];
        int len = next_ind - i;
        ans += len;
    }
    return ans;
    
    
    
    
    
        
    }
};