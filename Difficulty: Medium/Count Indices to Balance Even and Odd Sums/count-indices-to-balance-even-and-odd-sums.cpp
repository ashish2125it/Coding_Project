class Solution {
  public:
    int cntWays(vector<int>& arr) {
    int n = arr.size();
        int ans = 0;

        vector<int> even(n, 0), odd(n, 0);

       
        if ((n - 1) % 2 == 0)
            even[n - 1] = arr[n - 1];
        else
            odd[n - 1] = arr[n - 1];

     
        for (int i = n - 2; i >= 0; i--) {
            even[i] = even[i + 1];
            odd[i]  = odd[i + 1];

            if (i % 2 == 0)
                even[i] += arr[i];
            else
                odd[i] += arr[i];
        }

        int left_even = 0, left_odd = 0;

        for (int i = 0; i < n; i++) {
            if (i == n - 1) {
                if (left_even == left_odd) ans++;
                continue;
            }

            
            if (left_even + odd[i + 1] == left_odd + even[i + 1])
                ans++;

            if (i % 2 == 0)
                left_even += arr[i];
            else
                left_odd += arr[i];
        }

        return ans;
        
    }
};