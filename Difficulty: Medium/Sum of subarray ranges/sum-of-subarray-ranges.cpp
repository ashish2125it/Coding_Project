class Solution {
public:

    vector<int> prevSmaller(vector<int>& arr,int n)
    {
        vector<int> ans(n,-1);
        stack<int> s;

        for(int i=0;i<n;i++)
        {
            while(!s.empty() && arr[s.top()] > arr[i])
                s.pop();

            if(!s.empty())
                ans[i] = s.top();

            s.push(i);
        }
        return ans;
    }

    vector<int> nextSmaller(vector<int>& arr,int n)
    {
        vector<int> ans(n,n);
        stack<int> s;

        for(int i=n-1;i>=0;i--)
        {
            while(!s.empty() && arr[s.top()] >= arr[i])
                s.pop();

            if(!s.empty())
                ans[i] = s.top();

            s.push(i);
        }
        return ans;
    }

    vector<int> prevGreater(vector<int>& arr,int n)
    {
        vector<int> ans(n,-1);
        stack<int> s;

        for(int i=0;i<n;i++)
        {
            while(!s.empty() && arr[s.top()] < arr[i])
                s.pop();

            if(!s.empty())
                ans[i] = s.top();

            s.push(i);
        }
        return ans;
    }

    vector<int> nextGreater(vector<int>& arr,int n)
    {
        vector<int> ans(n,n);
        stack<int> s;

        for(int i=n-1;i>=0;i--)
        {
            while(!s.empty() && arr[s.top()] <= arr[i])
                s.pop();

            if(!s.empty())
                ans[i] = s.top();

            s.push(i);
        }
        return ans;
    }

    long long subarrayRanges(vector<int>& arr) {

        int n = arr.size();

        vector<int> ps = prevSmaller(arr,n);
        vector<int> ns = nextSmaller(arr,n);
        vector<int> pg = prevGreater(arr,n);
        vector<int> ng = nextGreater(arr,n);

        long long minSum = 0;
        long long maxSum = 0;

        for(int i=0;i<n;i++)
        {
            long long left = i - ps[i];
            long long right = ns[i] - i;
            minSum += (long long)arr[i] * left * right;
        }

        for(int i=0;i<n;i++)
        {
            long long left = i - pg[i];
            long long right = ng[i] - i;
            maxSum += (long long)arr[i] * left * right;
        }

        return maxSum - minSum;
    }
};