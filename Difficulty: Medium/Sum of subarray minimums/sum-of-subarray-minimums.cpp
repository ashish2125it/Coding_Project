class Solution {
public:

    vector<int> next_smaller(vector<int>& arr, int n)
    {
        stack<int> st;
        vector<int> ans(n, n);

        for(int i = n-1; i >= 0; i--)
        {
            while(!st.empty() && arr[st.top()] >= arr[i])
                st.pop();

            if(!st.empty())
                ans[i] = st.top();

            st.push(i);
        }

        return ans;
    }

    vector<int> prev_smaller(vector<int>& arr, int n)
    {
        stack<int> st;
        vector<int> ans(n, -1);

        for(int i = 0; i < n; i++)
        {
            while(!st.empty() && arr[st.top()] > arr[i])
                st.pop();

            if(!st.empty())
                ans[i] = st.top();

            st.push(i);
        }

        return ans;
    }

    int sumSubMins(vector<int> &arr)
    {
        int n = arr.size();
        long long sum = 0;
        int mod = 1e9 + 7;

        vector<int> next_small = next_smaller(arr, n);
        vector<int> prev_small = prev_smaller(arr, n);

        for(int i = 0; i < n; i++)
        {
            long long left = i - prev_small[i];
            long long right = next_small[i] - i;

            sum = (sum + (left * right % mod) * arr[i] % mod) % mod;
        }

        return sum;
    }
};