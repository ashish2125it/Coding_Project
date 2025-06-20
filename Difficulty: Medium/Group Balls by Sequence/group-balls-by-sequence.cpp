class Solution {
  public:
    bool validgroup(vector<int> &arr, int k) {
   int n = arr.size();
        if (n % k != 0) return false;

        map<int, int> mp;
        for (int num : arr) mp[num]++;

        while (!mp.empty()) {
            int start = mp.begin()->first; // always start from the smallest number

            for (int i = 0; i < k; i++) {
                int num = start + i;
                if (mp.find(num) == mp.end()) return false;

                mp[num]--;
                if (mp[num] == 0) mp.erase(num);
            }
        }

        return true;
        
    }
};