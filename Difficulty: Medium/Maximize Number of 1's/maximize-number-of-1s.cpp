class Solution {
  public:
    int maxOnes(vector<int>& arr, int k) {
    int n = arr.size();
        int i = 0, j = 0;
        int zeros = 0;
        int ans = 0;

        for (j = 0; j < n; ++j) {
            if (arr[j] == 0) zeros++;

            while (zeros > k) {
                if (arr[i] == 0) zeros--;
                i++;
            }

            ans = max(ans, j - i + 1);
        }

        return ans;
    }
};
