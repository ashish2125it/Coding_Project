//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
       vector<vector<int>> ans;
        priority_queue<vector<int>> q;  // Max-heap

        for (int i = 0; i < k; i++) {
            long long dist = (long long)points[i][0] * points[i][0] + (long long)points[i][1] * points[i][1];
            q.push({dist, points[i][0], points[i][1]});
        }

        for (int i = k; i < points.size(); i++) {
            long long dist = (long long)points[i][0] * points[i][0] + (long long)points[i][1] * points[i][1];
            if (q.top()[0] > dist) {
                q.pop();
                q.push({dist, points[i][0], points[i][1]});
            }
        }

        while (!q.empty()) {
            ans.push_back({q.top()[1], q.top()[2]});
            q.pop();
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        int n;
        cin >> n;
        vector<vector<int>> points(n, vector<int>(2));
        for (int i = 0; i < n; i++) {
            cin >> points[i][0] >> points[i][1];
        }
        Solution ob;
        vector<vector<int>> ans = ob.kClosest(points, k);
        sort(ans.begin(), ans.end());
        for (const vector<int>& point : ans) {
            cout << point[0] << " " << point[1] << endl;
        }
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends